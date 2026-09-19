#pragma once

#include "BlockTexture.h"
#include "BlockType.h"

EBlockTexture GetBlockTexture(EBlockType block, EBlockFace face);

EBlockTexture GetBlockOverlayTexture(EBlockType block, EBlockFace face);
