import os
import json
from PIL import Image

MODELS_DIR = "../Assets/Models/Blocks"
ANIMATED_TEXTURE_DIR = "../Assets/Textures/Blocks/Animated"
OUTPUT_HEADER_DIR = "../Source/Public/Generated/"
OUTPUT_CPP_DIR = "../Source/Private/Generated/"
OUTPUT_FILE_NAME = "BlockTextureMapping"
OUTPUT_HEADER_FILE = OUTPUT_FILE_NAME + ".h"
OUTPUT_CPP_FILE = OUTPUT_FILE_NAME + ".cpp"



VALID_JSON_KEYS = {
    "top",
    "bottom",
    "side",
    "front",
    "back",
    "all",
    "texture"
}

IGNORE_JSON_KEYS = {
    "particle"
}

def snake_to_pascal(name: str) -> str:
    return ''.join(word.capitalize() for word in name.split('_'))

def get_texture_path(json_entry):
    # "block/grass_block_top" → "GrassBlockTop"
    return json_entry.split('/')[-1]
    

def get_animated_block_textures():
    ignore_extensions = {".mcmeta"}
    block_textures = []
    for file in os.listdir(ANIMATED_TEXTURE_DIR):
        source_path = os.path.join(ANIMATED_TEXTURE_DIR, file)
        if os.path.splitext(file)[-1] in ignore_extensions or not os.path.isfile(source_path):
            continue
        try:
            with Image.open(source_path) as img:
                block_textures.append(os.path.splitext(file)[0])
        
        except Exception as e:
            print(f"[WARNING] Failed to read image: {file}")

    block_textures.sort()

    return block_textures


overlay_tex_files = []

def write_block_texture_mapping_func():
    # Header file
    os.makedirs(OUTPUT_HEADER_DIR, exist_ok=True)
    header_loc = os.path.join(OUTPUT_HEADER_DIR, OUTPUT_HEADER_FILE)

    with open(header_loc, "w") as f:
        f.write("#pragma once\n\n")
        f.write('#include "BlockTexture.h"\n')
        f.write('#include "BlockType.h"\n\n')
        f.write("EBlockTexture GetBlockTexture(EBlockType block, EBlockFace face);\n\n")
        f.write("EBlockTexture GetBlockOverlayTexture(EBlockType block, EBlockFace face);\n")

    print(f"Generated {header_loc}")
    
    # CPP file
    cpp_loc = os.path.join(OUTPUT_CPP_DIR, OUTPUT_CPP_FILE)
    with open(cpp_loc, "w") as f:
        f.write('#include "BlockTexture.h"\n')
        f.write(f'#include "{OUTPUT_HEADER_FILE}"\n')
        f.write('#include "BlockType.h"\n\n')

        f.write("EBlockTexture GetBlockTexture(EBlockType block, EBlockFace face)\n")
        f.write("{\n")
        f.write("\tswitch (block)\n")
        f.write("\t{\n")

        block_files = sorted([
            f for f in os.listdir(MODELS_DIR)
            if f.endswith(".json")
        ])

        animated_textures = get_animated_block_textures()

        def add_texture_for_face(texture, face):
            texture_path = get_texture_path(texture)
            if (texture_path in animated_textures):
                print(f"The texture {texture_path} is animated, ignoring for now")
            else:
                tex_enum = snake_to_pascal(texture_path)
                if face == "all":
                    f.write(f"\t\treturn EBlockTexture::{tex_enum};\n")
                else:
                    if face == "top":
                        f.write("\t\tcase EBlockFace::Top:\n")
                    elif face == "bottom":
                        f.write("\t\tcase EBlockFace::Bottom:\n")
                    elif face == "side":
                        f.write("\t\tcase EBlockFace::Side:\n")
                    elif face == "front":
                        f.write("\t\tcase EBlockFace::Front:\n")
                    elif face == "back":
                        f.write("\t\tcase EBlockFace::Back:\n")
                    
                    f.write(f"\t\t\treturn EBlockTexture::{tex_enum};\n")                  
                    

        for file in block_files:
            block_enum = snake_to_pascal(os.path.splitext(file)[0])
            full_path = os.path.join(MODELS_DIR, file)

            with open(full_path, "r") as jf:
                data = json.load(jf)

            textures = data.get("textures", {})

            if "overlay" in textures:
                overlay_tex_files.append(file)

            num_valid_keys = 0
            num_valid_textures = 0
            # Warn about unsupported keys
            for key in textures.keys():
                if key in VALID_JSON_KEYS:
                    num_valid_keys += 1
                    texture_path = get_texture_path(textures[key])
                    if (texture_path not in animated_textures):
                        num_valid_textures += 1
                elif key not in IGNORE_JSON_KEYS:
                    print(f"[WARNING] {file} contains unsupported texture key: '{key}'")
                
                

            f.write(f"\tcase EBlockType::{block_enum}:\n")
            f.write("\t{\n")
            
            if num_valid_keys == 0 or num_valid_textures == 0:
                f.write("\t\treturn EBlockTexture::Invalid;\n")
            # HIGHEST PRIORITY: "all" or "texture"
            elif "all" in textures:
                add_texture_for_face(textures["all"], "all")
            elif "texture" in textures:
                add_texture_for_face(textures["texture"], "all")
            
            else:
                f.write("\t\tswitch (face)\n")
                f.write("\t\t{\n")
                if "top" in textures:
                    add_texture_for_face(textures["top"], "top")

                if "bottom" in textures:
                    add_texture_for_face(textures["bottom"], "bottom")
                elif "top" in textures: # Reuse top texture if there is no dedicated bottom texture
                    add_texture_for_face(textures["top"], "bottom")

                if "side" in textures:
                    add_texture_for_face(textures["side"], "side")

                if "back" in textures:
                    add_texture_for_face(textures["back"], "back")
                elif "side" in textures: # Reuse side texture if there is no dedicated back texture
                    add_texture_for_face(textures["side"], "back")

                if "front" in textures:
                    add_texture_for_face(textures["front"], "front")
                elif "side" in textures: # Reuse side texture if there is no dedicated front texture
                    add_texture_for_face(textures["side"], "front")


                f.write("\t\tdefault:\n")
                f.write("\t\t\treturn EBlockTexture::Invalid;\n")

                f.write("\t\t}\n")
            f.write("\t}\n")

        f.write("\tdefault:\n\t\treturn EBlockTexture::Invalid;\n")
        f.write("\t}\n")
        f.write("}\n\n")

        f.write("EBlockTexture GetBlockOverlayTexture(EBlockType block, EBlockFace face)\n")
        f.write("{\n")
        f.write("\tswitch (block)\n")
        f.write("\t{\n")

        for file in overlay_tex_files:
            block_enum = snake_to_pascal(os.path.splitext(file)[0])
            full_path = os.path.join(MODELS_DIR, file)

            with open(full_path, "r") as jf:
                data = json.load(jf)

            textures = data.get("textures", {})

            f.write(f"\tcase EBlockType::{block_enum}:\n")
            f.write("\t{\n")
            f.write("\t\tif (face != EBlockFace::Top && face != EBlockFace::Bottom)\n")
            f.write("\t\t{\n")
            f.write(f"\t\t\treturn EBlockTexture::{snake_to_pascal(get_texture_path(textures["overlay"]))};\n")
            f.write("\t\t}\n")

            f.write("\t\telse\n")
            f.write("\t\t{\n")
            f.write("\t\t\treturn EBlockTexture::Transparent;\n")
            f.write("\t\t}\n")

            f.write("\t}\n")

        f.write("\tdefault:\n\t\treturn EBlockTexture::Transparent;\n")
        f.write("\t}\n")
        f.write("}\n")

    print(f"Generated {cpp_loc}")

write_block_texture_mapping_func()