import os
import shutil
from PIL import Image

TEXTURE_DIR = "../Assets/Textures/Blocks"

OUTPUT_HEADER_DIR = "../Source/Public/Generated/"
OUTPUT_HEADER_FILE = "BlockTexture.h"
IMG_WIDTH = 16
IMG_HEIGHT = 16

def snake_to_pascal(name: str) -> str:
    # Split by underscores, capitalize each word, join
    return ''.join(word.capitalize() for word in name.split('_'))


def get_block_textures():
    block_textures = []
    for file in os.listdir(TEXTURE_DIR):
        source_path = os.path.join(TEXTURE_DIR, file)
        if not os.path.isfile(source_path):
            continue
        try:
            with Image.open(source_path) as img:
                if img.width == IMG_WIDTH and img.height == IMG_HEIGHT:
                    block_textures.append(snake_to_pascal(os.path.splitext(file)[0]))
                else:
                    print(f"[WARNING] Wrong sized image: {file}, expected {IMG_WIDTH}x{IMG_HEIGHT}, but the image was {img.width}x{img.height}")

        except Exception as e:
            print(f"[WARNING] Failed to read image: {file}")

    block_textures.sort()

    return block_textures

def write_block_texture_enum(enum_names):
    os.makedirs(OUTPUT_HEADER_DIR, exist_ok=True)
    file_loc = os.path.join(OUTPUT_HEADER_DIR, OUTPUT_HEADER_FILE)
    with open(file_loc, "w") as f:
        f.write("#pragma once\n\n")
        f.write('#include "Types.h"\n\n')
        f.write("enum class EBlockTexture : uint16\n{\n")
        
        for name in enum_names:
            f.write(f"\t{name},\n")
        
        f.write("\tTransparent,\n")
        f.write("\tInvalid,\n")
        f.write("\tCOUNT\n};\n\n")
        
        # Emit full EBlockFace enum
        f.write("enum class EBlockFace : uint8\n")
        f.write("{\n")
        f.write("\tTop,\n")
        f.write("\tBottom,\n")
        f.write("\tFront,\n")
        f.write("\tBack,\n")
        f.write("\tSide,\n")
        f.write("\tCOUNT\n")
        f.write("};\n\n")

    print(f"Generated enum for {len(enum_names)} textures in {file_loc}")


write_block_texture_enum(get_block_textures())