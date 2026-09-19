import os

MODEL_DIR = "../Assets/Models/Blocks"
OUTPUT_HEADER_DIR = "../Source/Public/Generated/"
OUTPUT_HEADER_FILE = "BlockType.h"

valid_extensions = {".json"}


def snake_to_pascal(name: str) -> str:
    # Split by underscores, capitalize each word, join
    return ''.join(word.capitalize() for word in name.split('_'))


def get_block_types():
    block_types = []

    for file in os.listdir(MODEL_DIR):
        if os.path.isfile(os.path.join(MODEL_DIR, file)) and os.path.splitext(file)[1].lower() in valid_extensions:
            block_types.append(snake_to_pascal(os.path.splitext(file)[0]))

    block_types.sort()
    return block_types



def write_block_type_enum(enum_names):
    os.makedirs(OUTPUT_HEADER_DIR, exist_ok=True)
    file_loc = os.path.join(OUTPUT_HEADER_DIR, OUTPUT_HEADER_FILE)
    with open(file_loc, "w") as f:
        f.write("#pragma once\n\n")
        f.write('#include "Types.h"\n\n')
        f.write("enum class EBlockType : uint16\n{\n")

        for name in enum_names:
            f.write(f"\t{name},\n")

        f.write("\tCOUNT\n};\n\n")

    print(f"Generated enum for {len(enum_names)} block types in {file_loc}")

write_block_type_enum(get_block_types())

