#include "BlockTexture.h"
#include "BlockTextureMapping.h"
#include "BlockType.h"

EBlockTexture GetBlockTexture(EBlockType block, EBlockFace face)
{
	switch (block)
	{
	case EBlockType::AcaciaButton:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaButtonInventory:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaButtonPressed:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaFenceGate:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaFenceGateOpen:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaFenceGateWall:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaFenceGateWallOpen:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaFenceInventory:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaFencePost:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaFenceSide:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AcaciaLeaves:
	{
		return EBlockTexture::AcaciaLeaves;
	}
	case EBlockType::AcaciaLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::AcaciaLog;
		case EBlockFace::Back:
			return EBlockTexture::AcaciaLog;
		case EBlockFace::Front:
			return EBlockTexture::AcaciaLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::AcaciaLog;
		case EBlockFace::Back:
			return EBlockTexture::AcaciaLog;
		case EBlockFace::Front:
			return EBlockTexture::AcaciaLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaPlanks:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaPressurePlate:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaPressurePlateDown:
	{
		return EBlockTexture::AcaciaPlanks;
	}
	case EBlockType::AcaciaSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AcaciaSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AcaciaSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Side:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Back:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Front:
			return EBlockTexture::AcaciaPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Side:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Back:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Front:
			return EBlockTexture::AcaciaPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Side:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Back:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Front:
			return EBlockTexture::AcaciaPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Side:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Back:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Front:
			return EBlockTexture::AcaciaPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Side:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Back:
			return EBlockTexture::AcaciaPlanks;
		case EBlockFace::Front:
			return EBlockTexture::AcaciaPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AcaciaTrapdoorBottom:
	{
		return EBlockTexture::AcaciaTrapdoor;
	}
	case EBlockType::AcaciaTrapdoorOpen:
	{
		return EBlockTexture::AcaciaTrapdoor;
	}
	case EBlockType::AcaciaTrapdoorTop:
	{
		return EBlockTexture::AcaciaTrapdoor;
	}
	case EBlockType::AcaciaWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::AcaciaLog;
		case EBlockFace::Back:
			return EBlockTexture::AcaciaLog;
		case EBlockFace::Front:
			return EBlockTexture::AcaciaLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ActivatorRail:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ActivatorRailOn:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ActivatorRailOnRaisedNe:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ActivatorRailOnRaisedSw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ActivatorRailRaisedNe:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ActivatorRailRaisedSw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Air:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Allium:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AmethystBlock:
	{
		return EBlockTexture::AmethystBlock;
	}
	case EBlockType::AmethystCluster:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AncientDebris:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::AncientDebrisSide;
		case EBlockFace::Back:
			return EBlockTexture::AncientDebrisSide;
		case EBlockFace::Front:
			return EBlockTexture::AncientDebrisSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Andesite:
	{
		return EBlockTexture::Andesite;
	}
	case EBlockType::AndesiteSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Andesite;
		case EBlockFace::Bottom:
			return EBlockTexture::Andesite;
		case EBlockFace::Side:
			return EBlockTexture::Andesite;
		case EBlockFace::Back:
			return EBlockTexture::Andesite;
		case EBlockFace::Front:
			return EBlockTexture::Andesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AndesiteSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Andesite;
		case EBlockFace::Bottom:
			return EBlockTexture::Andesite;
		case EBlockFace::Side:
			return EBlockTexture::Andesite;
		case EBlockFace::Back:
			return EBlockTexture::Andesite;
		case EBlockFace::Front:
			return EBlockTexture::Andesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AndesiteStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Andesite;
		case EBlockFace::Bottom:
			return EBlockTexture::Andesite;
		case EBlockFace::Side:
			return EBlockTexture::Andesite;
		case EBlockFace::Back:
			return EBlockTexture::Andesite;
		case EBlockFace::Front:
			return EBlockTexture::Andesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AndesiteStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Andesite;
		case EBlockFace::Bottom:
			return EBlockTexture::Andesite;
		case EBlockFace::Side:
			return EBlockTexture::Andesite;
		case EBlockFace::Back:
			return EBlockTexture::Andesite;
		case EBlockFace::Front:
			return EBlockTexture::Andesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AndesiteStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Andesite;
		case EBlockFace::Bottom:
			return EBlockTexture::Andesite;
		case EBlockFace::Side:
			return EBlockTexture::Andesite;
		case EBlockFace::Back:
			return EBlockTexture::Andesite;
		case EBlockFace::Front:
			return EBlockTexture::Andesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AndesiteWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AndesiteWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AndesiteWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AndesiteWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Anvil:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AnvilTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AnvilTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AttachedMelonStem:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::AttachedPumpkinStem:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Azalea:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::AzaleaTop;
		case EBlockFace::Bottom:
			return EBlockTexture::AzaleaTop;
		case EBlockFace::Side:
			return EBlockTexture::AzaleaSide;
		case EBlockFace::Back:
			return EBlockTexture::AzaleaSide;
		case EBlockFace::Front:
			return EBlockTexture::AzaleaSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::AzaleaLeaves:
	{
		return EBlockTexture::AzaleaLeaves;
	}
	case EBlockType::AzureBluet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Bamboo1Age0:
	{
		return EBlockTexture::BambooStalk;
	}
	case EBlockType::Bamboo1Age1:
	{
		return EBlockTexture::BambooStalk;
	}
	case EBlockType::Bamboo2Age0:
	{
		return EBlockTexture::BambooStalk;
	}
	case EBlockType::Bamboo2Age1:
	{
		return EBlockTexture::BambooStalk;
	}
	case EBlockType::Bamboo3Age0:
	{
		return EBlockTexture::BambooStalk;
	}
	case EBlockType::Bamboo3Age1:
	{
		return EBlockTexture::BambooStalk;
	}
	case EBlockType::Bamboo4Age0:
	{
		return EBlockTexture::BambooStalk;
	}
	case EBlockType::Bamboo4Age1:
	{
		return EBlockTexture::BambooStalk;
	}
	case EBlockType::BambooBlock:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BambooBlock;
		case EBlockFace::Back:
			return EBlockTexture::BambooBlock;
		case EBlockFace::Front:
			return EBlockTexture::BambooBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooBlockX:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BambooBlock;
		case EBlockFace::Back:
			return EBlockTexture::BambooBlock;
		case EBlockFace::Front:
			return EBlockTexture::BambooBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooBlockY:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BambooBlock;
		case EBlockFace::Back:
			return EBlockTexture::BambooBlock;
		case EBlockFace::Front:
			return EBlockTexture::BambooBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooBlockZ:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BambooBlock;
		case EBlockFace::Back:
			return EBlockTexture::BambooBlock;
		case EBlockFace::Front:
			return EBlockTexture::BambooBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooButton:
	{
		return EBlockTexture::BambooPlanks;
	}
	case EBlockType::BambooButtonInventory:
	{
		return EBlockTexture::BambooPlanks;
	}
	case EBlockType::BambooButtonPressed:
	{
		return EBlockTexture::BambooPlanks;
	}
	case EBlockType::BambooDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooFenceGate:
	{
		return EBlockTexture::BambooFenceGate;
	}
	case EBlockType::BambooFenceGateOpen:
	{
		return EBlockTexture::BambooFenceGate;
	}
	case EBlockType::BambooFenceGateWall:
	{
		return EBlockTexture::BambooFenceGate;
	}
	case EBlockType::BambooFenceGateWallOpen:
	{
		return EBlockTexture::BambooFenceGate;
	}
	case EBlockType::BambooFenceInventory:
	{
		return EBlockTexture::BambooFence;
	}
	case EBlockType::BambooFencePost:
	{
		return EBlockTexture::BambooFence;
	}
	case EBlockType::BambooFenceSideEast:
	{
		return EBlockTexture::BambooFence;
	}
	case EBlockType::BambooFenceSideNorth:
	{
		return EBlockTexture::BambooFence;
	}
	case EBlockType::BambooFenceSideSouth:
	{
		return EBlockTexture::BambooFence;
	}
	case EBlockType::BambooFenceSideWest:
	{
		return EBlockTexture::BambooFence;
	}
	case EBlockType::BambooHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BambooLargeLeaves:
	{
		return EBlockTexture::BambooLargeLeaves;
	}
	case EBlockType::BambooMosaic:
	{
		return EBlockTexture::BambooMosaic;
	}
	case EBlockType::BambooMosaicSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Side:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Back:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Front:
			return EBlockTexture::BambooMosaic;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooMosaicSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Side:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Back:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Front:
			return EBlockTexture::BambooMosaic;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooMosaicStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Side:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Back:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Front:
			return EBlockTexture::BambooMosaic;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooMosaicStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Side:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Back:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Front:
			return EBlockTexture::BambooMosaic;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooMosaicStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Side:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Back:
			return EBlockTexture::BambooMosaic;
		case EBlockFace::Front:
			return EBlockTexture::BambooMosaic;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooPlanks:
	{
		return EBlockTexture::BambooPlanks;
	}
	case EBlockType::BambooPressurePlate:
	{
		return EBlockTexture::BambooPlanks;
	}
	case EBlockType::BambooPressurePlateDown:
	{
		return EBlockTexture::BambooPlanks;
	}
	case EBlockType::BambooSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BambooSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BambooSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BambooPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BambooPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooSmallLeaves:
	{
		return EBlockTexture::BambooSmallLeaves;
	}
	case EBlockType::BambooStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BambooPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BambooPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BambooPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BambooPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BambooTrapdoorBottom:
	{
		return EBlockTexture::BambooTrapdoor;
	}
	case EBlockType::BambooTrapdoorOpen:
	{
		return EBlockTexture::BambooTrapdoor;
	}
	case EBlockType::BambooTrapdoorTop:
	{
		return EBlockTexture::BambooTrapdoor;
	}
	case EBlockType::Banner:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Barrel:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BarrelTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BarrelBottom;
		case EBlockFace::Side:
			return EBlockTexture::BarrelSide;
		case EBlockFace::Back:
			return EBlockTexture::BarrelSide;
		case EBlockFace::Front:
			return EBlockTexture::BarrelSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BarrelOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BarrelTopOpen;
		case EBlockFace::Bottom:
			return EBlockTexture::BarrelBottom;
		case EBlockFace::Side:
			return EBlockTexture::BarrelSide;
		case EBlockFace::Back:
			return EBlockTexture::BarrelSide;
		case EBlockFace::Front:
			return EBlockTexture::BarrelSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Barrier:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Basalt:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BasaltSide;
		case EBlockFace::Back:
			return EBlockTexture::BasaltSide;
		case EBlockFace::Front:
			return EBlockTexture::BasaltSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Beacon:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Bed:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Bedrock:
	{
		return EBlockTexture::Bedrock;
	}
	case EBlockType::BedrockMirrored:
	{
		return EBlockTexture::Bedrock;
	}
	case EBlockType::BeeNestEmpty:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BeeNestTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BeeNestBottom;
		case EBlockFace::Side:
			return EBlockTexture::BeeNestSide;
		case EBlockFace::Back:
			return EBlockTexture::BeeNestSide;
		case EBlockFace::Front:
			return EBlockTexture::BeeNestFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BeeNestHoney:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BeeNestTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BeeNestBottom;
		case EBlockFace::Side:
			return EBlockTexture::BeeNestSide;
		case EBlockFace::Back:
			return EBlockTexture::BeeNestSide;
		case EBlockFace::Front:
			return EBlockTexture::BeeNestFrontHoney;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BeehiveEmpty:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BeehiveEnd;
		case EBlockFace::Bottom:
			return EBlockTexture::BeehiveEnd;
		case EBlockFace::Side:
			return EBlockTexture::BeehiveSide;
		case EBlockFace::Back:
			return EBlockTexture::BeehiveSide;
		case EBlockFace::Front:
			return EBlockTexture::BeehiveFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BeehiveHoney:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BeehiveEnd;
		case EBlockFace::Bottom:
			return EBlockTexture::BeehiveEnd;
		case EBlockFace::Side:
			return EBlockTexture::BeehiveSide;
		case EBlockFace::Back:
			return EBlockTexture::BeehiveSide;
		case EBlockFace::Front:
			return EBlockTexture::BeehiveFrontHoney;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BeetrootsStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BeetrootsStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BeetrootsStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BeetrootsStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BellBetweenWalls:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BellCeiling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BellFloor:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BellWall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BigDripleaf:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BigDripleafTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BigDripleafTop;
		case EBlockFace::Side:
			return EBlockTexture::BigDripleafSide;
		case EBlockFace::Back:
			return EBlockTexture::BigDripleafSide;
		case EBlockFace::Front:
			return EBlockTexture::BigDripleafSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BigDripleafFullTilt:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BigDripleafTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BigDripleafTop;
		case EBlockFace::Side:
			return EBlockTexture::BigDripleafSide;
		case EBlockFace::Back:
			return EBlockTexture::BigDripleafSide;
		case EBlockFace::Front:
			return EBlockTexture::BigDripleafSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BigDripleafPartialTilt:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BigDripleafTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BigDripleafTop;
		case EBlockFace::Side:
			return EBlockTexture::BigDripleafSide;
		case EBlockFace::Back:
			return EBlockTexture::BigDripleafSide;
		case EBlockFace::Front:
			return EBlockTexture::BigDripleafSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BigDripleafStem:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BirchButton:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchButtonInventory:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchButtonPressed:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchFenceGate:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchFenceGateOpen:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchFenceGateWall:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchFenceGateWallOpen:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchFenceInventory:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchFencePost:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchFenceSide:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BirchLeaves:
	{
		return EBlockTexture::BirchLeaves;
	}
	case EBlockType::BirchLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BirchLog;
		case EBlockFace::Back:
			return EBlockTexture::BirchLog;
		case EBlockFace::Front:
			return EBlockTexture::BirchLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BirchLog;
		case EBlockFace::Back:
			return EBlockTexture::BirchLog;
		case EBlockFace::Front:
			return EBlockTexture::BirchLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchPlanks:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchPressurePlate:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchPressurePlateDown:
	{
		return EBlockTexture::BirchPlanks;
	}
	case EBlockType::BirchSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BirchSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BirchSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BirchPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BirchPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BirchPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BirchPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Side:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Back:
			return EBlockTexture::BirchPlanks;
		case EBlockFace::Front:
			return EBlockTexture::BirchPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BirchTrapdoorBottom:
	{
		return EBlockTexture::BirchTrapdoor;
	}
	case EBlockType::BirchTrapdoorOpen:
	{
		return EBlockTexture::BirchTrapdoor;
	}
	case EBlockType::BirchTrapdoorTop:
	{
		return EBlockTexture::BirchTrapdoor;
	}
	case EBlockType::BirchWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BirchLog;
		case EBlockFace::Back:
			return EBlockTexture::BirchLog;
		case EBlockFace::Front:
			return EBlockTexture::BirchLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackCandleFourCandles:
	{
		return EBlockTexture::BlackCandle;
	}
	case EBlockType::BlackCandleFourCandlesLit:
	{
		return EBlockTexture::BlackCandleLit;
	}
	case EBlockType::BlackCandleOneCandle:
	{
		return EBlockTexture::BlackCandle;
	}
	case EBlockType::BlackCandleOneCandleLit:
	{
		return EBlockTexture::BlackCandleLit;
	}
	case EBlockType::BlackCandleThreeCandles:
	{
		return EBlockTexture::BlackCandle;
	}
	case EBlockType::BlackCandleThreeCandlesLit:
	{
		return EBlockTexture::BlackCandleLit;
	}
	case EBlockType::BlackCandleTwoCandles:
	{
		return EBlockTexture::BlackCandle;
	}
	case EBlockType::BlackCandleTwoCandlesLit:
	{
		return EBlockTexture::BlackCandleLit;
	}
	case EBlockType::BlackCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackConcrete:
	{
		return EBlockTexture::BlackConcrete;
	}
	case EBlockType::BlackConcretePowder:
	{
		return EBlockTexture::BlackConcretePowder;
	}
	case EBlockType::BlackGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackStainedGlass:
	{
		return EBlockTexture::BlackStainedGlass;
	}
	case EBlockType::BlackStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackTerracotta:
	{
		return EBlockTexture::BlackTerracotta;
	}
	case EBlockType::BlackWool:
	{
		return EBlockTexture::BlackWool;
	}
	case EBlockType::Blackstone:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::Blackstone;
		case EBlockFace::Back:
			return EBlockTexture::Blackstone;
		case EBlockFace::Front:
			return EBlockTexture::Blackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackstoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::Blackstone;
		case EBlockFace::Back:
			return EBlockTexture::Blackstone;
		case EBlockFace::Front:
			return EBlockTexture::Blackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackstoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::Blackstone;
		case EBlockFace::Back:
			return EBlockTexture::Blackstone;
		case EBlockFace::Front:
			return EBlockTexture::Blackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackstoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::Blackstone;
		case EBlockFace::Back:
			return EBlockTexture::Blackstone;
		case EBlockFace::Front:
			return EBlockTexture::Blackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackstoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::Blackstone;
		case EBlockFace::Back:
			return EBlockTexture::Blackstone;
		case EBlockFace::Front:
			return EBlockTexture::Blackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackstoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BlackstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::Blackstone;
		case EBlockFace::Back:
			return EBlockTexture::Blackstone;
		case EBlockFace::Front:
			return EBlockTexture::Blackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlackstoneWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackstoneWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackstoneWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlackstoneWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlastFurnace:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BlastFurnaceTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BlastFurnaceTop;
		case EBlockFace::Side:
			return EBlockTexture::BlastFurnaceSide;
		case EBlockFace::Back:
			return EBlockTexture::BlastFurnaceSide;
		case EBlockFace::Front:
			return EBlockTexture::BlastFurnaceFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlastFurnaceOn:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::BlastFurnaceTop;
		case EBlockFace::Bottom:
			return EBlockTexture::BlastFurnaceTop;
		case EBlockFace::Side:
			return EBlockTexture::BlastFurnaceSide;
		case EBlockFace::Back:
			return EBlockTexture::BlastFurnaceSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Block:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlueCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BlueCandleFourCandles:
	{
		return EBlockTexture::BlueCandle;
	}
	case EBlockType::BlueCandleFourCandlesLit:
	{
		return EBlockTexture::BlueCandleLit;
	}
	case EBlockType::BlueCandleOneCandle:
	{
		return EBlockTexture::BlueCandle;
	}
	case EBlockType::BlueCandleOneCandleLit:
	{
		return EBlockTexture::BlueCandleLit;
	}
	case EBlockType::BlueCandleThreeCandles:
	{
		return EBlockTexture::BlueCandle;
	}
	case EBlockType::BlueCandleThreeCandlesLit:
	{
		return EBlockTexture::BlueCandleLit;
	}
	case EBlockType::BlueCandleTwoCandles:
	{
		return EBlockTexture::BlueCandle;
	}
	case EBlockType::BlueCandleTwoCandlesLit:
	{
		return EBlockTexture::BlueCandleLit;
	}
	case EBlockType::BlueCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueConcrete:
	{
		return EBlockTexture::BlueConcrete;
	}
	case EBlockType::BlueConcretePowder:
	{
		return EBlockTexture::BlueConcretePowder;
	}
	case EBlockType::BlueGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueIce:
	{
		return EBlockTexture::BlueIce;
	}
	case EBlockType::BlueOrchid:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueStainedGlass:
	{
		return EBlockTexture::BlueStainedGlass;
	}
	case EBlockType::BlueStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BlueTerracotta:
	{
		return EBlockTexture::BlueTerracotta;
	}
	case EBlockType::BlueWool:
	{
		return EBlockTexture::BlueWool;
	}
	case EBlockType::BoneBlock:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::BoneBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::BoneBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::BoneBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Bookshelf:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::Bookshelf;
		case EBlockFace::Back:
			return EBlockTexture::Bookshelf;
		case EBlockFace::Front:
			return EBlockTexture::Bookshelf;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BrainCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrainCoralBlock:
	{
		return EBlockTexture::BrainCoralBlock;
	}
	case EBlockType::BrainCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrainCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrewingStand:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrewingStandBottle0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrewingStandBottle1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrewingStandBottle2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrewingStandEmpty0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrewingStandEmpty1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrewingStandEmpty2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Bricks;
		case EBlockFace::Bottom:
			return EBlockTexture::Bricks;
		case EBlockFace::Side:
			return EBlockTexture::Bricks;
		case EBlockFace::Back:
			return EBlockTexture::Bricks;
		case EBlockFace::Front:
			return EBlockTexture::Bricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Bricks;
		case EBlockFace::Bottom:
			return EBlockTexture::Bricks;
		case EBlockFace::Side:
			return EBlockTexture::Bricks;
		case EBlockFace::Back:
			return EBlockTexture::Bricks;
		case EBlockFace::Front:
			return EBlockTexture::Bricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Bricks;
		case EBlockFace::Bottom:
			return EBlockTexture::Bricks;
		case EBlockFace::Side:
			return EBlockTexture::Bricks;
		case EBlockFace::Back:
			return EBlockTexture::Bricks;
		case EBlockFace::Front:
			return EBlockTexture::Bricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Bricks;
		case EBlockFace::Bottom:
			return EBlockTexture::Bricks;
		case EBlockFace::Side:
			return EBlockTexture::Bricks;
		case EBlockFace::Back:
			return EBlockTexture::Bricks;
		case EBlockFace::Front:
			return EBlockTexture::Bricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Bricks;
		case EBlockFace::Bottom:
			return EBlockTexture::Bricks;
		case EBlockFace::Side:
			return EBlockTexture::Bricks;
		case EBlockFace::Back:
			return EBlockTexture::Bricks;
		case EBlockFace::Front:
			return EBlockTexture::Bricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Bricks:
	{
		return EBlockTexture::Bricks;
	}
	case EBlockType::BrownCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BrownCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::BrownCandleFourCandles:
	{
		return EBlockTexture::BrownCandle;
	}
	case EBlockType::BrownCandleFourCandlesLit:
	{
		return EBlockTexture::BrownCandleLit;
	}
	case EBlockType::BrownCandleOneCandle:
	{
		return EBlockTexture::BrownCandle;
	}
	case EBlockType::BrownCandleOneCandleLit:
	{
		return EBlockTexture::BrownCandleLit;
	}
	case EBlockType::BrownCandleThreeCandles:
	{
		return EBlockTexture::BrownCandle;
	}
	case EBlockType::BrownCandleThreeCandlesLit:
	{
		return EBlockTexture::BrownCandleLit;
	}
	case EBlockType::BrownCandleTwoCandles:
	{
		return EBlockTexture::BrownCandle;
	}
	case EBlockType::BrownCandleTwoCandlesLit:
	{
		return EBlockTexture::BrownCandleLit;
	}
	case EBlockType::BrownCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownConcrete:
	{
		return EBlockTexture::BrownConcrete;
	}
	case EBlockType::BrownConcretePowder:
	{
		return EBlockTexture::BrownConcretePowder;
	}
	case EBlockType::BrownGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownMushroom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownMushroomBlock:
	{
		return EBlockTexture::BrownMushroomBlock;
	}
	case EBlockType::BrownMushroomBlockInventory:
	{
		return EBlockTexture::BrownMushroomBlock;
	}
	case EBlockType::BrownShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownStainedGlass:
	{
		return EBlockTexture::BrownStainedGlass;
	}
	case EBlockType::BrownStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BrownTerracotta:
	{
		return EBlockTexture::BrownTerracotta;
	}
	case EBlockType::BrownWool:
	{
		return EBlockTexture::BrownWool;
	}
	case EBlockType::BubbleCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BubbleCoralBlock:
	{
		return EBlockTexture::BubbleCoralBlock;
	}
	case EBlockType::BubbleCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BubbleCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::BuddingAmethyst:
	{
		return EBlockTexture::BuddingAmethyst;
	}
	case EBlockType::Bush:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Button:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ButtonInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ButtonPressed:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Cactus:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CactusTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CactusBottom;
		case EBlockFace::Side:
			return EBlockTexture::CactusSide;
		case EBlockFace::Back:
			return EBlockTexture::CactusSide;
		case EBlockFace::Front:
			return EBlockTexture::CactusSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CactusFlower:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Cake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CakeSlice1:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CakeSlice2:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CakeSlice3:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CakeSlice4:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CakeSlice5:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CakeSlice6:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Calcite:
	{
		return EBlockTexture::Calcite;
	}
	case EBlockType::CalibratedSculkSensor:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CalibratedSculkSensorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SculkSensorBottom;
		case EBlockFace::Side:
			return EBlockTexture::SculkSensorSide;
		case EBlockFace::Back:
			return EBlockTexture::SculkSensorSide;
		case EBlockFace::Front:
			return EBlockTexture::SculkSensorSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CalibratedSculkSensorActive:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CalibratedSculkSensorInactive:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Campfire:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CampfireOff:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CandleFourCandles:
	{
		return EBlockTexture::Candle;
	}
	case EBlockType::CandleFourCandlesLit:
	{
		return EBlockTexture::CandleLit;
	}
	case EBlockType::CandleOneCandle:
	{
		return EBlockTexture::Candle;
	}
	case EBlockType::CandleOneCandleLit:
	{
		return EBlockTexture::CandleLit;
	}
	case EBlockType::CandleThreeCandles:
	{
		return EBlockTexture::Candle;
	}
	case EBlockType::CandleThreeCandlesLit:
	{
		return EBlockTexture::CandleLit;
	}
	case EBlockType::CandleTwoCandles:
	{
		return EBlockTexture::Candle;
	}
	case EBlockType::CandleTwoCandlesLit:
	{
		return EBlockTexture::CandleLit;
	}
	case EBlockType::Carpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CarrotsStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CarrotsStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CarrotsStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CarrotsStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CartographyTable:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CarvedPumpkin:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PumpkinTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PumpkinTop;
		case EBlockFace::Side:
			return EBlockTexture::PumpkinSide;
		case EBlockFace::Back:
			return EBlockTexture::PumpkinSide;
		case EBlockFace::Front:
			return EBlockTexture::CarvedPumpkin;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Cauldron:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CaveVines:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CaveVinesLit:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CaveVinesPlant:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CaveVinesPlantLit:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ChainCommandBlock:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ChainCommandBlockConditional:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CherryButton:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryButtonInventory:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryButtonPressed:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryFenceGate:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryFenceGateOpen:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryFenceGateWall:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryFenceGateWallOpen:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryFenceInventory:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryFencePost:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryFenceSide:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CherryLeaves:
	{
		return EBlockTexture::CherryLeaves;
	}
	case EBlockType::CherryLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CherryLog;
		case EBlockFace::Back:
			return EBlockTexture::CherryLog;
		case EBlockFace::Front:
			return EBlockTexture::CherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryLogX:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CherryLog;
		case EBlockFace::Back:
			return EBlockTexture::CherryLog;
		case EBlockFace::Front:
			return EBlockTexture::CherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryLogY:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CherryLog;
		case EBlockFace::Back:
			return EBlockTexture::CherryLog;
		case EBlockFace::Front:
			return EBlockTexture::CherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryLogZ:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CherryLog;
		case EBlockFace::Back:
			return EBlockTexture::CherryLog;
		case EBlockFace::Front:
			return EBlockTexture::CherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryPlanks:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryPressurePlate:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherryPressurePlateDown:
	{
		return EBlockTexture::CherryPlanks;
	}
	case EBlockType::CherrySapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CherrySign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CherrySlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CherryPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherrySlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CherryPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CherryPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CherryPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CherryPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CherryPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CherryTrapdoorBottom:
	{
		return EBlockTexture::CherryTrapdoor;
	}
	case EBlockType::CherryTrapdoorOpen:
	{
		return EBlockTexture::CherryTrapdoor;
	}
	case EBlockType::CherryTrapdoorTop:
	{
		return EBlockTexture::CherryTrapdoor;
	}
	case EBlockType::CherryWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CherryLog;
		case EBlockFace::Back:
			return EBlockTexture::CherryLog;
		case EBlockFace::Front:
			return EBlockTexture::CherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Chest:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ChippedAnvil:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ChippedAnvilTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ChippedAnvilTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ChiseledBookshelf:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ChiseledBookshelfTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ChiseledBookshelfTop;
		case EBlockFace::Side:
			return EBlockTexture::ChiseledBookshelfSide;
		case EBlockFace::Back:
			return EBlockTexture::ChiseledBookshelfSide;
		case EBlockFace::Front:
			return EBlockTexture::ChiseledBookshelfSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ChiseledBookshelfEmptySlotBottomLeft:
	{
		return EBlockTexture::ChiseledBookshelfEmpty;
	}
	case EBlockType::ChiseledBookshelfEmptySlotBottomMid:
	{
		return EBlockTexture::ChiseledBookshelfEmpty;
	}
	case EBlockType::ChiseledBookshelfEmptySlotBottomRight:
	{
		return EBlockTexture::ChiseledBookshelfEmpty;
	}
	case EBlockType::ChiseledBookshelfEmptySlotTopLeft:
	{
		return EBlockTexture::ChiseledBookshelfEmpty;
	}
	case EBlockType::ChiseledBookshelfEmptySlotTopMid:
	{
		return EBlockTexture::ChiseledBookshelfEmpty;
	}
	case EBlockType::ChiseledBookshelfEmptySlotTopRight:
	{
		return EBlockTexture::ChiseledBookshelfEmpty;
	}
	case EBlockType::ChiseledBookshelfInventory:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ChiseledBookshelfTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ChiseledBookshelfTop;
		case EBlockFace::Side:
			return EBlockTexture::ChiseledBookshelfSide;
		case EBlockFace::Back:
			return EBlockTexture::ChiseledBookshelfSide;
		case EBlockFace::Front:
			return EBlockTexture::ChiseledBookshelfEmpty;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ChiseledBookshelfOccupiedSlotBottomLeft:
	{
		return EBlockTexture::ChiseledBookshelfOccupied;
	}
	case EBlockType::ChiseledBookshelfOccupiedSlotBottomMid:
	{
		return EBlockTexture::ChiseledBookshelfOccupied;
	}
	case EBlockType::ChiseledBookshelfOccupiedSlotBottomRight:
	{
		return EBlockTexture::ChiseledBookshelfOccupied;
	}
	case EBlockType::ChiseledBookshelfOccupiedSlotTopLeft:
	{
		return EBlockTexture::ChiseledBookshelfOccupied;
	}
	case EBlockType::ChiseledBookshelfOccupiedSlotTopMid:
	{
		return EBlockTexture::ChiseledBookshelfOccupied;
	}
	case EBlockType::ChiseledBookshelfOccupiedSlotTopRight:
	{
		return EBlockTexture::ChiseledBookshelfOccupied;
	}
	case EBlockType::ChiseledCopper:
	{
		return EBlockTexture::ChiseledCopper;
	}
	case EBlockType::ChiseledDeepslate:
	{
		return EBlockTexture::ChiseledDeepslate;
	}
	case EBlockType::ChiseledNetherBricks:
	{
		return EBlockTexture::ChiseledNetherBricks;
	}
	case EBlockType::ChiseledPolishedBlackstone:
	{
		return EBlockTexture::ChiseledPolishedBlackstone;
	}
	case EBlockType::ChiseledQuartzBlock:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::ChiseledQuartzBlock;
		case EBlockFace::Back:
			return EBlockTexture::ChiseledQuartzBlock;
		case EBlockFace::Front:
			return EBlockTexture::ChiseledQuartzBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ChiseledRedSandstone:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::ChiseledRedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::ChiseledRedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::ChiseledRedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ChiseledResinBricks:
	{
		return EBlockTexture::ChiseledResinBricks;
	}
	case EBlockType::ChiseledSandstone:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::ChiseledSandstone;
		case EBlockFace::Back:
			return EBlockTexture::ChiseledSandstone;
		case EBlockFace::Front:
			return EBlockTexture::ChiseledSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ChiseledStoneBricks:
	{
		return EBlockTexture::ChiseledStoneBricks;
	}
	case EBlockType::ChiseledTuff:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::ChiseledTuff;
		case EBlockFace::Back:
			return EBlockTexture::ChiseledTuff;
		case EBlockFace::Front:
			return EBlockTexture::ChiseledTuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ChiseledTuffBricks:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::ChiseledTuffBricks;
		case EBlockFace::Back:
			return EBlockTexture::ChiseledTuffBricks;
		case EBlockFace::Front:
			return EBlockTexture::ChiseledTuffBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ChorusFlower:
	{
		return EBlockTexture::ChorusFlower;
	}
	case EBlockType::ChorusFlowerDead:
	{
		return EBlockTexture::ChorusFlowerDead;
	}
	case EBlockType::ChorusPlant:
	{
		return EBlockTexture::ChorusPlant;
	}
	case EBlockType::ChorusPlantNoside:
	{
		return EBlockTexture::ChorusPlant;
	}
	case EBlockType::ChorusPlantNoside1:
	{
		return EBlockTexture::ChorusPlant;
	}
	case EBlockType::ChorusPlantNoside2:
	{
		return EBlockTexture::ChorusPlant;
	}
	case EBlockType::ChorusPlantNoside3:
	{
		return EBlockTexture::ChorusPlant;
	}
	case EBlockType::ChorusPlantSide:
	{
		return EBlockTexture::ChorusPlant;
	}
	case EBlockType::Clay:
	{
		return EBlockTexture::Clay;
	}
	case EBlockType::ClosedEyeblossom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CoalBlock:
	{
		return EBlockTexture::CoalBlock;
	}
	case EBlockType::CoalOre:
	{
		return EBlockTexture::CoalOre;
	}
	case EBlockType::CoarseDirt:
	{
		return EBlockTexture::CoarseDirt;
	}
	case EBlockType::CobbledDeepslate:
	{
		return EBlockTexture::CobbledDeepslate;
	}
	case EBlockType::CobbledDeepslateSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::CobbledDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobbledDeepslateSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::CobbledDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobbledDeepslateStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::CobbledDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobbledDeepslateStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::CobbledDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobbledDeepslateStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::CobbledDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::CobbledDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobbledDeepslateWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CobbledDeepslateWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CobbledDeepslateWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CobbledDeepslateWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Cobblestone:
	{
		return EBlockTexture::Cobblestone;
	}
	case EBlockType::CobblestoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Side:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Back:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Front:
			return EBlockTexture::Cobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobblestoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Side:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Back:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Front:
			return EBlockTexture::Cobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobblestoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Side:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Back:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Front:
			return EBlockTexture::Cobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobblestoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Side:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Back:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Front:
			return EBlockTexture::Cobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobblestoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Side:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Back:
			return EBlockTexture::Cobblestone;
		case EBlockFace::Front:
			return EBlockTexture::Cobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CobblestoneWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CobblestoneWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CobblestoneWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CobblestoneWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Cobweb:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CocoaStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CocoaStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CocoaStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CommandBlock:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CommandBlockConditional:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Comparator:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Comparator;
		case EBlockFace::Bottom:
			return EBlockTexture::Comparator;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ComparatorOn:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ComparatorOn;
		case EBlockFace::Bottom:
			return EBlockTexture::ComparatorOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ComparatorOnSubtract:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ComparatorOn;
		case EBlockFace::Bottom:
			return EBlockTexture::ComparatorOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ComparatorSubtract:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Comparator;
		case EBlockFace::Bottom:
			return EBlockTexture::Comparator;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Composter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ComposterTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ComposterBottom;
		case EBlockFace::Side:
			return EBlockTexture::ComposterSide;
		case EBlockFace::Back:
			return EBlockTexture::ComposterSide;
		case EBlockFace::Front:
			return EBlockTexture::ComposterSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ComposterContents1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ComposterContents2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ComposterContents3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ComposterContents4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ComposterContents5:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ComposterContents6:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ComposterContents7:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ComposterContentsReady:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Conduit:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperBarsCap:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperBarsCapAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperBarsPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperBarsPostEnds:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperBarsSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperBarsSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperBlock:
	{
		return EBlockTexture::CopperBlock;
	}
	case EBlockType::CopperBulb:
	{
		return EBlockTexture::CopperBulb;
	}
	case EBlockType::CopperBulbLit:
	{
		return EBlockTexture::CopperBulbLit;
	}
	case EBlockType::CopperBulbLitPowered:
	{
		return EBlockTexture::CopperBulbLitPowered;
	}
	case EBlockType::CopperBulbPowered:
	{
		return EBlockTexture::CopperBulbPowered;
	}
	case EBlockType::CopperChain:
	{
		return EBlockTexture::CopperChain;
	}
	case EBlockType::CopperChest:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CopperDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CopperDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CopperDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CopperDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CopperDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CopperDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CopperDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CopperGolemStatue:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperGrate:
	{
		return EBlockTexture::CopperGrate;
	}
	case EBlockType::CopperLantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperLanternHanging:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperOre:
	{
		return EBlockTexture::CopperOre;
	}
	case EBlockType::CopperTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CopperTrapdoorBottom:
	{
		return EBlockTexture::CopperTrapdoor;
	}
	case EBlockType::CopperTrapdoorOpen:
	{
		return EBlockTexture::CopperTrapdoor;
	}
	case EBlockType::CopperTrapdoorTop:
	{
		return EBlockTexture::CopperTrapdoor;
	}
	case EBlockType::CopperWallTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Cornflower:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrackedDeepslateBricks:
	{
		return EBlockTexture::CrackedDeepslateBricks;
	}
	case EBlockType::CrackedDeepslateTiles:
	{
		return EBlockTexture::CrackedDeepslateTiles;
	}
	case EBlockType::CrackedNetherBricks:
	{
		return EBlockTexture::CrackedNetherBricks;
	}
	case EBlockType::CrackedPolishedBlackstoneBricks:
	{
		return EBlockTexture::CrackedPolishedBlackstoneBricks;
	}
	case EBlockType::CrackedStoneBricks:
	{
		return EBlockTexture::CrackedStoneBricks;
	}
	case EBlockType::Crafter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrafterTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrafterBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrafterCrafting:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrafterTopCrafting;
		case EBlockFace::Bottom:
			return EBlockTexture::CrafterTopCrafting;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrafterCraftingTriggered:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrafterTriggered:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrafterTopTriggered;
		case EBlockFace::Bottom:
			return EBlockTexture::CrafterTopTriggered;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CraftingTable:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CreakingHeart:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CreakingHeart;
		case EBlockFace::Back:
			return EBlockTexture::CreakingHeart;
		case EBlockFace::Front:
			return EBlockTexture::CreakingHeart;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CreakingHeartAwake:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CreakingHeartAwake;
		case EBlockFace::Back:
			return EBlockTexture::CreakingHeartAwake;
		case EBlockFace::Front:
			return EBlockTexture::CreakingHeartAwake;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CreakingHeartAwakeHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CreakingHeartAwake;
		case EBlockFace::Back:
			return EBlockTexture::CreakingHeartAwake;
		case EBlockFace::Front:
			return EBlockTexture::CreakingHeartAwake;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CreakingHeartDormant:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CreakingHeartDormant;
		case EBlockFace::Back:
			return EBlockTexture::CreakingHeartDormant;
		case EBlockFace::Front:
			return EBlockTexture::CreakingHeartDormant;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CreakingHeartDormantHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CreakingHeartDormant;
		case EBlockFace::Back:
			return EBlockTexture::CreakingHeartDormant;
		case EBlockFace::Front:
			return EBlockTexture::CreakingHeartDormant;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CreakingHeartHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CreakingHeart;
		case EBlockFace::Back:
			return EBlockTexture::CreakingHeart;
		case EBlockFace::Front:
			return EBlockTexture::CreakingHeart;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonButton:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonButtonInventory:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonButtonPressed:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonFenceGate:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonFenceGateOpen:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonFenceGateWall:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonFenceGateWallOpen:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonFenceInventory:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonFencePost:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonFenceSide:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonFungus:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrimsonHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrimsonHyphae:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrimsonNylium:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonNylium;
		case EBlockFace::Bottom:
			return EBlockTexture::Netherrack;
		case EBlockFace::Side:
			return EBlockTexture::CrimsonNyliumSide;
		case EBlockFace::Back:
			return EBlockTexture::CrimsonNyliumSide;
		case EBlockFace::Front:
			return EBlockTexture::CrimsonNyliumSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonPlanks:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonPressurePlate:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonPressurePlateDown:
	{
		return EBlockTexture::CrimsonPlanks;
	}
	case EBlockType::CrimsonRoots:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrimsonSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrimsonSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CrimsonPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CrimsonPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CrimsonPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CrimsonPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Side:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Back:
			return EBlockTexture::CrimsonPlanks;
		case EBlockFace::Front:
			return EBlockTexture::CrimsonPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CrimsonStem:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrimsonTrapdoorBottom:
	{
		return EBlockTexture::CrimsonTrapdoor;
	}
	case EBlockType::CrimsonTrapdoorOpen:
	{
		return EBlockTexture::CrimsonTrapdoor;
	}
	case EBlockType::CrimsonTrapdoorTop:
	{
		return EBlockTexture::CrimsonTrapdoor;
	}
	case EBlockType::Crop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Cross:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CrossEmissive:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CryingObsidian:
	{
		return EBlockTexture::CryingObsidian;
	}
	case EBlockType::Cube:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeAll:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeAllInnerFaces:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeBottomTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeBottomTopInnerFaces:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeColumn:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeColumnHorizontal:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeColumnMirrored:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeColumnUvLockedX:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeColumnUvLockedY:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeColumnUvLockedZ:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeDirectional:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeMirrored:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeMirroredAll:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeNorthWestMirrored:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeNorthWestMirroredAll:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CubeTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CustomFenceInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CustomFencePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CustomFenceSideEast:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CustomFenceSideNorth:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CustomFenceSideSouth:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CustomFenceSideWest:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CutCopper:
	{
		return EBlockTexture::CutCopper;
	}
	case EBlockType::CutCopperSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::CutCopper;
		case EBlockFace::Side:
			return EBlockTexture::CutCopper;
		case EBlockFace::Back:
			return EBlockTexture::CutCopper;
		case EBlockFace::Front:
			return EBlockTexture::CutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutCopperSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::CutCopper;
		case EBlockFace::Side:
			return EBlockTexture::CutCopper;
		case EBlockFace::Back:
			return EBlockTexture::CutCopper;
		case EBlockFace::Front:
			return EBlockTexture::CutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutCopperStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::CutCopper;
		case EBlockFace::Side:
			return EBlockTexture::CutCopper;
		case EBlockFace::Back:
			return EBlockTexture::CutCopper;
		case EBlockFace::Front:
			return EBlockTexture::CutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutCopperStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::CutCopper;
		case EBlockFace::Side:
			return EBlockTexture::CutCopper;
		case EBlockFace::Back:
			return EBlockTexture::CutCopper;
		case EBlockFace::Front:
			return EBlockTexture::CutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutCopperStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::CutCopper;
		case EBlockFace::Side:
			return EBlockTexture::CutCopper;
		case EBlockFace::Back:
			return EBlockTexture::CutCopper;
		case EBlockFace::Front:
			return EBlockTexture::CutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutRedSandstone:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CutRedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::CutRedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::CutRedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutRedSandstoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::CutRedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::CutRedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::CutRedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutRedSandstoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::CutRedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::CutRedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::CutRedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutSandstone:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::CutSandstone;
		case EBlockFace::Back:
			return EBlockTexture::CutSandstone;
		case EBlockFace::Front:
			return EBlockTexture::CutSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutSandstoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::CutSandstone;
		case EBlockFace::Back:
			return EBlockTexture::CutSandstone;
		case EBlockFace::Front:
			return EBlockTexture::CutSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CutSandstoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::CutSandstone;
		case EBlockFace::Back:
			return EBlockTexture::CutSandstone;
		case EBlockFace::Front:
			return EBlockTexture::CutSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CyanCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CyanCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::CyanCandleFourCandles:
	{
		return EBlockTexture::CyanCandle;
	}
	case EBlockType::CyanCandleFourCandlesLit:
	{
		return EBlockTexture::CyanCandleLit;
	}
	case EBlockType::CyanCandleOneCandle:
	{
		return EBlockTexture::CyanCandle;
	}
	case EBlockType::CyanCandleOneCandleLit:
	{
		return EBlockTexture::CyanCandleLit;
	}
	case EBlockType::CyanCandleThreeCandles:
	{
		return EBlockTexture::CyanCandle;
	}
	case EBlockType::CyanCandleThreeCandlesLit:
	{
		return EBlockTexture::CyanCandleLit;
	}
	case EBlockType::CyanCandleTwoCandles:
	{
		return EBlockTexture::CyanCandle;
	}
	case EBlockType::CyanCandleTwoCandlesLit:
	{
		return EBlockTexture::CyanCandleLit;
	}
	case EBlockType::CyanCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CyanConcrete:
	{
		return EBlockTexture::CyanConcrete;
	}
	case EBlockType::CyanConcretePowder:
	{
		return EBlockTexture::CyanConcretePowder;
	}
	case EBlockType::CyanGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CyanShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CyanStainedGlass:
	{
		return EBlockTexture::CyanStainedGlass;
	}
	case EBlockType::CyanStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CyanStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CyanStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CyanStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CyanStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::CyanTerracotta:
	{
		return EBlockTexture::CyanTerracotta;
	}
	case EBlockType::CyanWool:
	{
		return EBlockTexture::CyanWool;
	}
	case EBlockType::DamagedAnvil:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DamagedAnvilTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DamagedAnvilTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Dandelion:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DarkOakButton:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakButtonInventory:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakButtonPressed:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakFenceGate:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakFenceGateOpen:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakFenceGateWall:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakFenceGateWallOpen:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakFenceInventory:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakFencePost:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakFenceSide:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DarkOakLeaves:
	{
		return EBlockTexture::DarkOakLeaves;
	}
	case EBlockType::DarkOakLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::DarkOakLog;
		case EBlockFace::Back:
			return EBlockTexture::DarkOakLog;
		case EBlockFace::Front:
			return EBlockTexture::DarkOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::DarkOakLog;
		case EBlockFace::Back:
			return EBlockTexture::DarkOakLog;
		case EBlockFace::Front:
			return EBlockTexture::DarkOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakPlanks:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakPressurePlate:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakPressurePlateDown:
	{
		return EBlockTexture::DarkOakPlanks;
	}
	case EBlockType::DarkOakSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DarkOakSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DarkOakSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::DarkOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::DarkOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::DarkOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::DarkOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::DarkOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::DarkOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkOakTrapdoorBottom:
	{
		return EBlockTexture::DarkOakTrapdoor;
	}
	case EBlockType::DarkOakTrapdoorOpen:
	{
		return EBlockTexture::DarkOakTrapdoor;
	}
	case EBlockType::DarkOakTrapdoorTop:
	{
		return EBlockTexture::DarkOakTrapdoor;
	}
	case EBlockType::DarkOakWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::DarkOakLog;
		case EBlockFace::Back:
			return EBlockTexture::DarkOakLog;
		case EBlockFace::Front:
			return EBlockTexture::DarkOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkPrismarine:
	{
		return EBlockTexture::DarkPrismarine;
	}
	case EBlockType::DarkPrismarineSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Side:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Back:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Front:
			return EBlockTexture::DarkPrismarine;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkPrismarineSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Side:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Back:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Front:
			return EBlockTexture::DarkPrismarine;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkPrismarineStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Side:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Back:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Front:
			return EBlockTexture::DarkPrismarine;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkPrismarineStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Side:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Back:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Front:
			return EBlockTexture::DarkPrismarine;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DarkPrismarineStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Bottom:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Side:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Back:
			return EBlockTexture::DarkPrismarine;
		case EBlockFace::Front:
			return EBlockTexture::DarkPrismarine;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DaylightDetector:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DaylightDetectorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DaylightDetectorTop;
		case EBlockFace::Side:
			return EBlockTexture::DaylightDetectorSide;
		case EBlockFace::Back:
			return EBlockTexture::DaylightDetectorSide;
		case EBlockFace::Front:
			return EBlockTexture::DaylightDetectorSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DaylightDetectorInverted:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DaylightDetectorInvertedTop;
		case EBlockFace::Bottom:
			return EBlockTexture::DaylightDetectorInvertedTop;
		case EBlockFace::Side:
			return EBlockTexture::DaylightDetectorSide;
		case EBlockFace::Back:
			return EBlockTexture::DaylightDetectorSide;
		case EBlockFace::Front:
			return EBlockTexture::DaylightDetectorSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeadBrainCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadBrainCoralBlock:
	{
		return EBlockTexture::DeadBrainCoralBlock;
	}
	case EBlockType::DeadBrainCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadBrainCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadBubbleCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadBubbleCoralBlock:
	{
		return EBlockTexture::DeadBubbleCoralBlock;
	}
	case EBlockType::DeadBubbleCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadBubbleCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadBush:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadFireCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadFireCoralBlock:
	{
		return EBlockTexture::DeadFireCoralBlock;
	}
	case EBlockType::DeadFireCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadFireCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadHornCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadHornCoralBlock:
	{
		return EBlockTexture::DeadHornCoralBlock;
	}
	case EBlockType::DeadHornCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadHornCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadSeaPickle:
	{
		return EBlockTexture::SeaPickle;
	}
	case EBlockType::DeadTubeCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadTubeCoralBlock:
	{
		return EBlockTexture::DeadTubeCoralBlock;
	}
	case EBlockType::DeadTubeCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeadTubeCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DecoratedPot:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Deepslate:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::Deepslate;
		case EBlockFace::Back:
			return EBlockTexture::Deepslate;
		case EBlockFace::Front:
			return EBlockTexture::Deepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateBricks;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeepslateBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeepslateBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeepslateBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeepslateBricks:
	{
		return EBlockTexture::DeepslateBricks;
	}
	case EBlockType::DeepslateCoalOre:
	{
		return EBlockTexture::DeepslateCoalOre;
	}
	case EBlockType::DeepslateCopperOre:
	{
		return EBlockTexture::DeepslateCopperOre;
	}
	case EBlockType::DeepslateDiamondOre:
	{
		return EBlockTexture::DeepslateDiamondOre;
	}
	case EBlockType::DeepslateEmeraldOre:
	{
		return EBlockTexture::DeepslateEmeraldOre;
	}
	case EBlockType::DeepslateGoldOre:
	{
		return EBlockTexture::DeepslateGoldOre;
	}
	case EBlockType::DeepslateIronOre:
	{
		return EBlockTexture::DeepslateIronOre;
	}
	case EBlockType::DeepslateLapisOre:
	{
		return EBlockTexture::DeepslateLapisOre;
	}
	case EBlockType::DeepslateMirrored:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::Deepslate;
		case EBlockFace::Back:
			return EBlockTexture::Deepslate;
		case EBlockFace::Front:
			return EBlockTexture::Deepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateRedstoneOre:
	{
		return EBlockTexture::DeepslateRedstoneOre;
	}
	case EBlockType::DeepslateTileSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateTiles;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateTileSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateTiles;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateTileStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateTiles;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateTileStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateTiles;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateTileStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Bottom:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Side:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Back:
			return EBlockTexture::DeepslateTiles;
		case EBlockFace::Front:
			return EBlockTexture::DeepslateTiles;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DeepslateTileWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeepslateTileWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeepslateTileWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeepslateTileWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DeepslateTiles:
	{
		return EBlockTexture::DeepslateTiles;
	}
	case EBlockType::DetectorRail:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DetectorRailOn:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DetectorRailOnRaisedNe:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DetectorRailOnRaisedSw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DetectorRailRaisedNe:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DetectorRailRaisedSw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DiamondBlock:
	{
		return EBlockTexture::DiamondBlock;
	}
	case EBlockType::DiamondOre:
	{
		return EBlockTexture::DiamondOre;
	}
	case EBlockType::Diorite:
	{
		return EBlockTexture::Diorite;
	}
	case EBlockType::DioriteSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Diorite;
		case EBlockFace::Bottom:
			return EBlockTexture::Diorite;
		case EBlockFace::Side:
			return EBlockTexture::Diorite;
		case EBlockFace::Back:
			return EBlockTexture::Diorite;
		case EBlockFace::Front:
			return EBlockTexture::Diorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DioriteSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Diorite;
		case EBlockFace::Bottom:
			return EBlockTexture::Diorite;
		case EBlockFace::Side:
			return EBlockTexture::Diorite;
		case EBlockFace::Back:
			return EBlockTexture::Diorite;
		case EBlockFace::Front:
			return EBlockTexture::Diorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DioriteStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Diorite;
		case EBlockFace::Bottom:
			return EBlockTexture::Diorite;
		case EBlockFace::Side:
			return EBlockTexture::Diorite;
		case EBlockFace::Back:
			return EBlockTexture::Diorite;
		case EBlockFace::Front:
			return EBlockTexture::Diorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DioriteStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Diorite;
		case EBlockFace::Bottom:
			return EBlockTexture::Diorite;
		case EBlockFace::Side:
			return EBlockTexture::Diorite;
		case EBlockFace::Back:
			return EBlockTexture::Diorite;
		case EBlockFace::Front:
			return EBlockTexture::Diorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DioriteStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Diorite;
		case EBlockFace::Bottom:
			return EBlockTexture::Diorite;
		case EBlockFace::Side:
			return EBlockTexture::Diorite;
		case EBlockFace::Back:
			return EBlockTexture::Diorite;
		case EBlockFace::Front:
			return EBlockTexture::Diorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DioriteWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DioriteWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DioriteWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DioriteWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Dirt:
	{
		return EBlockTexture::Dirt;
	}
	case EBlockType::DirtPath:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DirtPathTop;
		case EBlockFace::Bottom:
			return EBlockTexture::Dirt;
		case EBlockFace::Side:
			return EBlockTexture::DirtPathSide;
		case EBlockFace::Back:
			return EBlockTexture::DirtPathSide;
		case EBlockFace::Front:
			return EBlockTexture::DirtPathSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Dispenser:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Bottom:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Side:
			return EBlockTexture::FurnaceSide;
		case EBlockFace::Back:
			return EBlockTexture::FurnaceSide;
		case EBlockFace::Front:
			return EBlockTexture::DispenserFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DispenserVertical:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Back:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Front:
			return EBlockTexture::DispenserFrontVertical;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DoorBottomLeft:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DoorBottomLeftOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DoorBottomRight:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DoorBottomRightOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DoorTopLeft:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DoorTopLeftOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DoorTopRight:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DoorTopRightOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DragonEgg:
	{
		return EBlockTexture::DragonEgg;
	}
	case EBlockType::DriedGhast:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DriedGhastHydration0:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DriedGhastHydration0Top;
		case EBlockFace::Bottom:
			return EBlockTexture::DriedGhastHydration0Bottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DriedGhastHydration1:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DriedGhastHydration1Top;
		case EBlockFace::Bottom:
			return EBlockTexture::DriedGhastHydration1Bottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DriedGhastHydration2:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DriedGhastHydration2Top;
		case EBlockFace::Bottom:
			return EBlockTexture::DriedGhastHydration2Bottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DriedGhastHydration3:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::DriedGhastHydration3Top;
		case EBlockFace::Bottom:
			return EBlockTexture::DriedGhastHydration3Bottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DriedKelpBlock:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::DripstoneBlock:
	{
		return EBlockTexture::DripstoneBlock;
	}
	case EBlockType::Dropper:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Bottom:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Side:
			return EBlockTexture::FurnaceSide;
		case EBlockFace::Back:
			return EBlockTexture::FurnaceSide;
		case EBlockFace::Front:
			return EBlockTexture::DropperFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::DropperVertical:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Back:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Front:
			return EBlockTexture::DropperFrontVertical;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EmeraldBlock:
	{
		return EBlockTexture::EmeraldBlock;
	}
	case EBlockType::EmeraldOre:
	{
		return EBlockTexture::EmeraldOre;
	}
	case EBlockType::EnchantingTable:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::EnchantingTableTop;
		case EBlockFace::Bottom:
			return EBlockTexture::EnchantingTableBottom;
		case EBlockFace::Side:
			return EBlockTexture::EnchantingTableSide;
		case EBlockFace::Back:
			return EBlockTexture::EnchantingTableSide;
		case EBlockFace::Front:
			return EBlockTexture::EnchantingTableSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EndGateway:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::EndPortal:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::EndPortalFrame:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::EndPortalFrameTop;
		case EBlockFace::Bottom:
			return EBlockTexture::EndStone;
		case EBlockFace::Side:
			return EBlockTexture::EndPortalFrameSide;
		case EBlockFace::Back:
			return EBlockTexture::EndPortalFrameSide;
		case EBlockFace::Front:
			return EBlockTexture::EndPortalFrameSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EndPortalFrameFilled:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::EndPortalFrameTop;
		case EBlockFace::Bottom:
			return EBlockTexture::EndStone;
		case EBlockFace::Side:
			return EBlockTexture::EndPortalFrameSide;
		case EBlockFace::Back:
			return EBlockTexture::EndPortalFrameSide;
		case EBlockFace::Front:
			return EBlockTexture::EndPortalFrameSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EndRod:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::EndStone:
	{
		return EBlockTexture::EndStone;
	}
	case EBlockType::EndStoneBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::EndStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EndStoneBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::EndStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EndStoneBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::EndStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EndStoneBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::EndStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EndStoneBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::EndStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::EndStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::EndStoneBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::EndStoneBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::EndStoneBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::EndStoneBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::EndStoneBricks:
	{
		return EBlockTexture::EndStoneBricks;
	}
	case EBlockType::EnderChest:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedChiseledCopper:
	{
		return EBlockTexture::ExposedChiseledCopper;
	}
	case EBlockType::ExposedCopper:
	{
		return EBlockTexture::ExposedCopper;
	}
	case EBlockType::ExposedCopperBarsCap:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperBarsCapAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperBarsPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperBarsPostEnds:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperBarsSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperBarsSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperBulb:
	{
		return EBlockTexture::ExposedCopperBulb;
	}
	case EBlockType::ExposedCopperBulbLit:
	{
		return EBlockTexture::ExposedCopperBulbLit;
	}
	case EBlockType::ExposedCopperBulbLitPowered:
	{
		return EBlockTexture::ExposedCopperBulbLitPowered;
	}
	case EBlockType::ExposedCopperBulbPowered:
	{
		return EBlockTexture::ExposedCopperBulbPowered;
	}
	case EBlockType::ExposedCopperChain:
	{
		return EBlockTexture::ExposedCopperChain;
	}
	case EBlockType::ExposedCopperChest:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCopperDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCopperDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCopperDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCopperDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCopperDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCopperDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCopperDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCopperGolemStatue:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperGrate:
	{
		return EBlockTexture::ExposedCopperGrate;
	}
	case EBlockType::ExposedCopperLantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperLanternHanging:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ExposedCopperTrapdoorBottom:
	{
		return EBlockTexture::ExposedCopperTrapdoor;
	}
	case EBlockType::ExposedCopperTrapdoorOpen:
	{
		return EBlockTexture::ExposedCopperTrapdoor;
	}
	case EBlockType::ExposedCopperTrapdoorTop:
	{
		return EBlockTexture::ExposedCopperTrapdoor;
	}
	case EBlockType::ExposedCutCopper:
	{
		return EBlockTexture::ExposedCutCopper;
	}
	case EBlockType::ExposedCutCopperSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::ExposedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCutCopperSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::ExposedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCutCopperStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::ExposedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCutCopperStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::ExposedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedCutCopperStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::ExposedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::ExposedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ExposedLightningRod:
	{
		return EBlockTexture::ExposedLightningRod;
	}
	case EBlockType::Farmland:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Farmland;
		case EBlockFace::Bottom:
			return EBlockTexture::Farmland;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::FarmlandMoist:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::FarmlandMoist;
		case EBlockFace::Bottom:
			return EBlockTexture::FarmlandMoist;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::FenceInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FencePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FenceSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Fern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireCoralBlock:
	{
		return EBlockTexture::FireCoralBlock;
	}
	case EBlockType::FireCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireFloor0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireFloor1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireSide0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireSide1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireSideAlt0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireSideAlt1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireUp0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireUp1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireUpAlt0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireUpAlt1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FireflyBush:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FletchingTable:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FlowerPot:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FlowerPotCross:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FlowerPotCrossEmissive:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Flowerbed1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Flowerbed2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Flowerbed3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Flowerbed4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::FloweringAzalea:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::FloweringAzaleaTop;
		case EBlockFace::Bottom:
			return EBlockTexture::FloweringAzaleaTop;
		case EBlockFace::Side:
			return EBlockTexture::FloweringAzaleaSide;
		case EBlockFace::Back:
			return EBlockTexture::FloweringAzaleaSide;
		case EBlockFace::Front:
			return EBlockTexture::FloweringAzaleaSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::FloweringAzaleaLeaves:
	{
		return EBlockTexture::FloweringAzaleaLeaves;
	}
	case EBlockType::FourDeadSeaPickles:
	{
		return EBlockTexture::SeaPickle;
	}
	case EBlockType::FourSeaPickles:
	{
		return EBlockTexture::SeaPickle;
	}
	case EBlockType::FourSlightlyCrackedTurtleEggs:
	{
		return EBlockTexture::TurtleEggSlightlyCracked;
	}
	case EBlockType::FourTurtleEggs:
	{
		return EBlockTexture::TurtleEgg;
	}
	case EBlockType::FourVeryCrackedTurtleEggs:
	{
		return EBlockTexture::TurtleEggVeryCracked;
	}
	case EBlockType::Frogspawn:
	{
		return EBlockTexture::Frogspawn;
	}
	case EBlockType::FrostedIce0:
	{
		return EBlockTexture::FrostedIce0;
	}
	case EBlockType::FrostedIce1:
	{
		return EBlockTexture::FrostedIce1;
	}
	case EBlockType::FrostedIce2:
	{
		return EBlockTexture::FrostedIce2;
	}
	case EBlockType::FrostedIce3:
	{
		return EBlockTexture::FrostedIce3;
	}
	case EBlockType::Furnace:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Bottom:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Side:
			return EBlockTexture::FurnaceSide;
		case EBlockFace::Back:
			return EBlockTexture::FurnaceSide;
		case EBlockFace::Front:
			return EBlockTexture::FurnaceFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::FurnaceOn:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Bottom:
			return EBlockTexture::FurnaceTop;
		case EBlockFace::Side:
			return EBlockTexture::FurnaceSide;
		case EBlockFace::Back:
			return EBlockTexture::FurnaceSide;
		case EBlockFace::Front:
			return EBlockTexture::FurnaceFrontOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GildedBlackstone:
	{
		return EBlockTexture::GildedBlackstone;
	}
	case EBlockType::Glass:
	{
		return EBlockTexture::Glass;
	}
	case EBlockType::GlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GlowItemFrame:
	{
		switch (face)
		{
		case EBlockFace::Back:
			return EBlockTexture::GlowItemFrame;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GlowItemFrameMap:
	{
		switch (face)
		{
		case EBlockFace::Back:
			return EBlockTexture::GlowItemFrame;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GlowLichen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Glowstone:
	{
		return EBlockTexture::Glowstone;
	}
	case EBlockType::GoldBlock:
	{
		return EBlockTexture::GoldBlock;
	}
	case EBlockType::GoldOre:
	{
		return EBlockTexture::GoldOre;
	}
	case EBlockType::Granite:
	{
		return EBlockTexture::Granite;
	}
	case EBlockType::GraniteSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Granite;
		case EBlockFace::Bottom:
			return EBlockTexture::Granite;
		case EBlockFace::Side:
			return EBlockTexture::Granite;
		case EBlockFace::Back:
			return EBlockTexture::Granite;
		case EBlockFace::Front:
			return EBlockTexture::Granite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GraniteSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Granite;
		case EBlockFace::Bottom:
			return EBlockTexture::Granite;
		case EBlockFace::Side:
			return EBlockTexture::Granite;
		case EBlockFace::Back:
			return EBlockTexture::Granite;
		case EBlockFace::Front:
			return EBlockTexture::Granite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GraniteStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Granite;
		case EBlockFace::Bottom:
			return EBlockTexture::Granite;
		case EBlockFace::Side:
			return EBlockTexture::Granite;
		case EBlockFace::Back:
			return EBlockTexture::Granite;
		case EBlockFace::Front:
			return EBlockTexture::Granite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GraniteStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Granite;
		case EBlockFace::Bottom:
			return EBlockTexture::Granite;
		case EBlockFace::Side:
			return EBlockTexture::Granite;
		case EBlockFace::Back:
			return EBlockTexture::Granite;
		case EBlockFace::Front:
			return EBlockTexture::Granite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GraniteStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Granite;
		case EBlockFace::Bottom:
			return EBlockTexture::Granite;
		case EBlockFace::Side:
			return EBlockTexture::Granite;
		case EBlockFace::Back:
			return EBlockTexture::Granite;
		case EBlockFace::Front:
			return EBlockTexture::Granite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GraniteWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GraniteWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GraniteWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GraniteWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrassBlock:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::GrassBlockTop;
		case EBlockFace::Bottom:
			return EBlockTexture::Dirt;
		case EBlockFace::Side:
			return EBlockTexture::Dirt;
		case EBlockFace::Back:
			return EBlockTexture::Dirt;
		case EBlockFace::Front:
			return EBlockTexture::Dirt;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GrassBlockSnow:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::GrassBlockTop;
		case EBlockFace::Bottom:
			return EBlockTexture::Dirt;
		case EBlockFace::Side:
			return EBlockTexture::GrassBlockSnow;
		case EBlockFace::Back:
			return EBlockTexture::GrassBlockSnow;
		case EBlockFace::Front:
			return EBlockTexture::GrassBlockSnow;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Gravel:
	{
		return EBlockTexture::Gravel;
	}
	case EBlockType::GrayCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GrayCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GrayCandleFourCandles:
	{
		return EBlockTexture::GrayCandle;
	}
	case EBlockType::GrayCandleFourCandlesLit:
	{
		return EBlockTexture::GrayCandleLit;
	}
	case EBlockType::GrayCandleOneCandle:
	{
		return EBlockTexture::GrayCandle;
	}
	case EBlockType::GrayCandleOneCandleLit:
	{
		return EBlockTexture::GrayCandleLit;
	}
	case EBlockType::GrayCandleThreeCandles:
	{
		return EBlockTexture::GrayCandle;
	}
	case EBlockType::GrayCandleThreeCandlesLit:
	{
		return EBlockTexture::GrayCandleLit;
	}
	case EBlockType::GrayCandleTwoCandles:
	{
		return EBlockTexture::GrayCandle;
	}
	case EBlockType::GrayCandleTwoCandlesLit:
	{
		return EBlockTexture::GrayCandleLit;
	}
	case EBlockType::GrayCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrayConcrete:
	{
		return EBlockTexture::GrayConcrete;
	}
	case EBlockType::GrayConcretePowder:
	{
		return EBlockTexture::GrayConcretePowder;
	}
	case EBlockType::GrayGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrayShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrayStainedGlass:
	{
		return EBlockTexture::GrayStainedGlass;
	}
	case EBlockType::GrayStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrayStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrayStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrayStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrayStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GrayTerracotta:
	{
		return EBlockTexture::GrayTerracotta;
	}
	case EBlockType::GrayWool:
	{
		return EBlockTexture::GrayWool;
	}
	case EBlockType::GreenCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GreenCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::GreenCandleFourCandles:
	{
		return EBlockTexture::GreenCandle;
	}
	case EBlockType::GreenCandleFourCandlesLit:
	{
		return EBlockTexture::GreenCandleLit;
	}
	case EBlockType::GreenCandleOneCandle:
	{
		return EBlockTexture::GreenCandle;
	}
	case EBlockType::GreenCandleOneCandleLit:
	{
		return EBlockTexture::GreenCandleLit;
	}
	case EBlockType::GreenCandleThreeCandles:
	{
		return EBlockTexture::GreenCandle;
	}
	case EBlockType::GreenCandleThreeCandlesLit:
	{
		return EBlockTexture::GreenCandleLit;
	}
	case EBlockType::GreenCandleTwoCandles:
	{
		return EBlockTexture::GreenCandle;
	}
	case EBlockType::GreenCandleTwoCandlesLit:
	{
		return EBlockTexture::GreenCandleLit;
	}
	case EBlockType::GreenCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GreenConcrete:
	{
		return EBlockTexture::GreenConcrete;
	}
	case EBlockType::GreenConcretePowder:
	{
		return EBlockTexture::GreenConcretePowder;
	}
	case EBlockType::GreenGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GreenShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GreenStainedGlass:
	{
		return EBlockTexture::GreenStainedGlass;
	}
	case EBlockType::GreenStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GreenStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GreenStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GreenStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GreenStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::GreenTerracotta:
	{
		return EBlockTexture::GreenTerracotta;
	}
	case EBlockType::GreenWool:
	{
		return EBlockTexture::GreenWool;
	}
	case EBlockType::Grindstone:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::GrindstoneSide;
		case EBlockFace::Back:
			return EBlockTexture::GrindstoneSide;
		case EBlockFace::Front:
			return EBlockTexture::GrindstoneSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::HangingRoots:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::HayBlock:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::HayBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::HayBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::HayBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::HayBlockHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::HayBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::HayBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::HayBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::HeavyCore:
	{
		return EBlockTexture::HeavyCore;
	}
	case EBlockType::HeavyWeightedPressurePlate:
	{
		return EBlockTexture::IronBlock;
	}
	case EBlockType::HeavyWeightedPressurePlateDown:
	{
		return EBlockTexture::IronBlock;
	}
	case EBlockType::HoneyBlock:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::HoneyBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::HoneyBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::HoneyBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::HoneycombBlock:
	{
		return EBlockTexture::HoneycombBlock;
	}
	case EBlockType::Hopper:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::HopperTop;
		case EBlockFace::Bottom:
			return EBlockTexture::HopperTop;
		case EBlockFace::Side:
			return EBlockTexture::HopperOutside;
		case EBlockFace::Back:
			return EBlockTexture::HopperOutside;
		case EBlockFace::Front:
			return EBlockTexture::HopperOutside;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::HopperSide:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::HopperTop;
		case EBlockFace::Bottom:
			return EBlockTexture::HopperTop;
		case EBlockFace::Side:
			return EBlockTexture::HopperOutside;
		case EBlockFace::Back:
			return EBlockTexture::HopperOutside;
		case EBlockFace::Front:
			return EBlockTexture::HopperOutside;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::HornCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::HornCoralBlock:
	{
		return EBlockTexture::HornCoralBlock;
	}
	case EBlockType::HornCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::HornCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Ice:
	{
		return EBlockTexture::Ice;
	}
	case EBlockType::InnerStairs:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::IronBarsCap:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::IronBarsCapAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::IronBarsPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::IronBarsPostEnds:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::IronBarsSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::IronBarsSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::IronBlock:
	{
		return EBlockTexture::IronBlock;
	}
	case EBlockType::IronChain:
	{
		return EBlockTexture::IronChain;
	}
	case EBlockType::IronDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::IronDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::IronDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::IronDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::IronDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::IronDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::IronDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::IronDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::IronDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::IronDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::IronDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::IronDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::IronDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::IronDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::IronDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::IronDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::IronDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::IronDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::IronDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::IronDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::IronDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::IronDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::IronDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::IronDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::IronOre:
	{
		return EBlockTexture::IronOre;
	}
	case EBlockType::IronTrapdoorBottom:
	{
		return EBlockTexture::IronTrapdoor;
	}
	case EBlockType::IronTrapdoorOpen:
	{
		return EBlockTexture::IronTrapdoor;
	}
	case EBlockType::IronTrapdoorTop:
	{
		return EBlockTexture::IronTrapdoor;
	}
	case EBlockType::ItemFrame:
	{
		switch (face)
		{
		case EBlockFace::Back:
			return EBlockTexture::ItemFrame;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ItemFrameMap:
	{
		switch (face)
		{
		case EBlockFace::Back:
			return EBlockTexture::ItemFrame;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JackOLantern:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PumpkinTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PumpkinTop;
		case EBlockFace::Side:
			return EBlockTexture::PumpkinSide;
		case EBlockFace::Back:
			return EBlockTexture::PumpkinSide;
		case EBlockFace::Front:
			return EBlockTexture::JackOLantern;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Jigsaw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Jukebox:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JukeboxTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JukeboxTop;
		case EBlockFace::Side:
			return EBlockTexture::JukeboxSide;
		case EBlockFace::Back:
			return EBlockTexture::JukeboxSide;
		case EBlockFace::Front:
			return EBlockTexture::JukeboxSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleButton:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleButtonInventory:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleButtonPressed:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JungleDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JungleDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JungleDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JungleDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JungleDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JungleDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JungleDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JungleDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JungleDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JungleDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JungleDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JungleDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JungleDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JungleDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JungleDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::JungleDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleFenceGate:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleFenceGateOpen:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleFenceGateWall:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleFenceGateWallOpen:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleFenceInventory:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleFencePost:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleFenceSide:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::JungleLeaves:
	{
		return EBlockTexture::JungleLeaves;
	}
	case EBlockType::JungleLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::JungleLog;
		case EBlockFace::Back:
			return EBlockTexture::JungleLog;
		case EBlockFace::Front:
			return EBlockTexture::JungleLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::JungleLog;
		case EBlockFace::Back:
			return EBlockTexture::JungleLog;
		case EBlockFace::Front:
			return EBlockTexture::JungleLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JunglePlanks:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JunglePressurePlate:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JunglePressurePlateDown:
	{
		return EBlockTexture::JunglePlanks;
	}
	case EBlockType::JungleSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::JungleSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::JungleSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Side:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Back:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Front:
			return EBlockTexture::JunglePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Side:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Back:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Front:
			return EBlockTexture::JunglePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Side:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Back:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Front:
			return EBlockTexture::JunglePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Side:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Back:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Front:
			return EBlockTexture::JunglePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Side:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Back:
			return EBlockTexture::JunglePlanks;
		case EBlockFace::Front:
			return EBlockTexture::JunglePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::JungleTrapdoorBottom:
	{
		return EBlockTexture::JungleTrapdoor;
	}
	case EBlockType::JungleTrapdoorOpen:
	{
		return EBlockTexture::JungleTrapdoor;
	}
	case EBlockType::JungleTrapdoorTop:
	{
		return EBlockTexture::JungleTrapdoor;
	}
	case EBlockType::JungleWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::JungleLog;
		case EBlockFace::Back:
			return EBlockTexture::JungleLog;
		case EBlockFace::Front:
			return EBlockTexture::JungleLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Kelp:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::KelpPlant:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Ladder:
	{
		return EBlockTexture::Ladder;
	}
	case EBlockType::Lantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LanternHanging:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LapisBlock:
	{
		return EBlockTexture::LapisBlock;
	}
	case EBlockType::LapisOre:
	{
		return EBlockTexture::LapisOre;
	}
	case EBlockType::LargeAmethystBud:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LargeFernBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LargeFernTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Lava:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LavaCauldron:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::LeafLitter1:
	{
		return EBlockTexture::LeafLitter;
	}
	case EBlockType::LeafLitter2:
	{
		return EBlockTexture::LeafLitter;
	}
	case EBlockType::LeafLitter3:
	{
		return EBlockTexture::LeafLitter;
	}
	case EBlockType::LeafLitter4:
	{
		return EBlockTexture::LeafLitter;
	}
	case EBlockType::Leaves:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Lectern:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::LecternTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::LecternFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Lever:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LeverOn:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light00:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light01:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light02:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light03:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light04:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light05:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light06:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light07:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light08:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light09:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light10:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light11:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light12:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light13:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light14:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Light15:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::LightBlueCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::LightBlueCandleFourCandles:
	{
		return EBlockTexture::LightBlueCandle;
	}
	case EBlockType::LightBlueCandleFourCandlesLit:
	{
		return EBlockTexture::LightBlueCandleLit;
	}
	case EBlockType::LightBlueCandleOneCandle:
	{
		return EBlockTexture::LightBlueCandle;
	}
	case EBlockType::LightBlueCandleOneCandleLit:
	{
		return EBlockTexture::LightBlueCandleLit;
	}
	case EBlockType::LightBlueCandleThreeCandles:
	{
		return EBlockTexture::LightBlueCandle;
	}
	case EBlockType::LightBlueCandleThreeCandlesLit:
	{
		return EBlockTexture::LightBlueCandleLit;
	}
	case EBlockType::LightBlueCandleTwoCandles:
	{
		return EBlockTexture::LightBlueCandle;
	}
	case EBlockType::LightBlueCandleTwoCandlesLit:
	{
		return EBlockTexture::LightBlueCandleLit;
	}
	case EBlockType::LightBlueCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueConcrete:
	{
		return EBlockTexture::LightBlueConcrete;
	}
	case EBlockType::LightBlueConcretePowder:
	{
		return EBlockTexture::LightBlueConcretePowder;
	}
	case EBlockType::LightBlueGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueStainedGlass:
	{
		return EBlockTexture::LightBlueStainedGlass;
	}
	case EBlockType::LightBlueStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightBlueTerracotta:
	{
		return EBlockTexture::LightBlueTerracotta;
	}
	case EBlockType::LightBlueWool:
	{
		return EBlockTexture::LightBlueWool;
	}
	case EBlockType::LightGrayCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::LightGrayCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::LightGrayCandleFourCandles:
	{
		return EBlockTexture::LightGrayCandle;
	}
	case EBlockType::LightGrayCandleFourCandlesLit:
	{
		return EBlockTexture::LightGrayCandleLit;
	}
	case EBlockType::LightGrayCandleOneCandle:
	{
		return EBlockTexture::LightGrayCandle;
	}
	case EBlockType::LightGrayCandleOneCandleLit:
	{
		return EBlockTexture::LightGrayCandleLit;
	}
	case EBlockType::LightGrayCandleThreeCandles:
	{
		return EBlockTexture::LightGrayCandle;
	}
	case EBlockType::LightGrayCandleThreeCandlesLit:
	{
		return EBlockTexture::LightGrayCandleLit;
	}
	case EBlockType::LightGrayCandleTwoCandles:
	{
		return EBlockTexture::LightGrayCandle;
	}
	case EBlockType::LightGrayCandleTwoCandlesLit:
	{
		return EBlockTexture::LightGrayCandleLit;
	}
	case EBlockType::LightGrayCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightGrayConcrete:
	{
		return EBlockTexture::LightGrayConcrete;
	}
	case EBlockType::LightGrayConcretePowder:
	{
		return EBlockTexture::LightGrayConcretePowder;
	}
	case EBlockType::LightGrayGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightGrayShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightGrayStainedGlass:
	{
		return EBlockTexture::LightGrayStainedGlass;
	}
	case EBlockType::LightGrayStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightGrayStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightGrayStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightGrayStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightGrayStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LightGrayTerracotta:
	{
		return EBlockTexture::LightGrayTerracotta;
	}
	case EBlockType::LightGrayWool:
	{
		return EBlockTexture::LightGrayWool;
	}
	case EBlockType::LightWeightedPressurePlate:
	{
		return EBlockTexture::GoldBlock;
	}
	case EBlockType::LightWeightedPressurePlateDown:
	{
		return EBlockTexture::GoldBlock;
	}
	case EBlockType::LightningRod:
	{
		return EBlockTexture::LightningRod;
	}
	case EBlockType::LightningRodOn:
	{
		return EBlockTexture::LightningRodOn;
	}
	case EBlockType::LilacBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LilacTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LilyOfTheValley:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LilyPad:
	{
		return EBlockTexture::LilyPad;
	}
	case EBlockType::LimeCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::LimeCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::LimeCandleFourCandles:
	{
		return EBlockTexture::LimeCandle;
	}
	case EBlockType::LimeCandleFourCandlesLit:
	{
		return EBlockTexture::LimeCandleLit;
	}
	case EBlockType::LimeCandleOneCandle:
	{
		return EBlockTexture::LimeCandle;
	}
	case EBlockType::LimeCandleOneCandleLit:
	{
		return EBlockTexture::LimeCandleLit;
	}
	case EBlockType::LimeCandleThreeCandles:
	{
		return EBlockTexture::LimeCandle;
	}
	case EBlockType::LimeCandleThreeCandlesLit:
	{
		return EBlockTexture::LimeCandleLit;
	}
	case EBlockType::LimeCandleTwoCandles:
	{
		return EBlockTexture::LimeCandle;
	}
	case EBlockType::LimeCandleTwoCandlesLit:
	{
		return EBlockTexture::LimeCandleLit;
	}
	case EBlockType::LimeCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LimeConcrete:
	{
		return EBlockTexture::LimeConcrete;
	}
	case EBlockType::LimeConcretePowder:
	{
		return EBlockTexture::LimeConcretePowder;
	}
	case EBlockType::LimeGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LimeShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LimeStainedGlass:
	{
		return EBlockTexture::LimeStainedGlass;
	}
	case EBlockType::LimeStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LimeStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LimeStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LimeStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LimeStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::LimeTerracotta:
	{
		return EBlockTexture::LimeTerracotta;
	}
	case EBlockType::LimeWool:
	{
		return EBlockTexture::LimeWool;
	}
	case EBlockType::Lodestone:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::LodestoneSide;
		case EBlockFace::Back:
			return EBlockTexture::LodestoneSide;
		case EBlockFace::Front:
			return EBlockTexture::LodestoneSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Loom:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::LoomTop;
		case EBlockFace::Bottom:
			return EBlockTexture::LoomBottom;
		case EBlockFace::Side:
			return EBlockTexture::LoomSide;
		case EBlockFace::Back:
			return EBlockTexture::LoomSide;
		case EBlockFace::Front:
			return EBlockTexture::LoomFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MagentaCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MagentaCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MagentaCandleFourCandles:
	{
		return EBlockTexture::MagentaCandle;
	}
	case EBlockType::MagentaCandleFourCandlesLit:
	{
		return EBlockTexture::MagentaCandleLit;
	}
	case EBlockType::MagentaCandleOneCandle:
	{
		return EBlockTexture::MagentaCandle;
	}
	case EBlockType::MagentaCandleOneCandleLit:
	{
		return EBlockTexture::MagentaCandleLit;
	}
	case EBlockType::MagentaCandleThreeCandles:
	{
		return EBlockTexture::MagentaCandle;
	}
	case EBlockType::MagentaCandleThreeCandlesLit:
	{
		return EBlockTexture::MagentaCandleLit;
	}
	case EBlockType::MagentaCandleTwoCandles:
	{
		return EBlockTexture::MagentaCandle;
	}
	case EBlockType::MagentaCandleTwoCandlesLit:
	{
		return EBlockTexture::MagentaCandleLit;
	}
	case EBlockType::MagentaCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MagentaConcrete:
	{
		return EBlockTexture::MagentaConcrete;
	}
	case EBlockType::MagentaConcretePowder:
	{
		return EBlockTexture::MagentaConcretePowder;
	}
	case EBlockType::MagentaGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MagentaShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MagentaStainedGlass:
	{
		return EBlockTexture::MagentaStainedGlass;
	}
	case EBlockType::MagentaStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MagentaStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MagentaStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MagentaStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MagentaStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MagentaTerracotta:
	{
		return EBlockTexture::MagentaTerracotta;
	}
	case EBlockType::MagentaWool:
	{
		return EBlockTexture::MagentaWool;
	}
	case EBlockType::MagmaBlock:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangroveButton:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveButtonInventory:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveButtonPressed:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveFenceGate:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveFenceGateOpen:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveFenceGateWall:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveFenceGateWallOpen:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveFenceInventory:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveFencePost:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveFenceSide:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangroveHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangroveLeaves:
	{
		return EBlockTexture::MangroveLeaves;
	}
	case EBlockType::MangroveLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::MangroveLog;
		case EBlockFace::Back:
			return EBlockTexture::MangroveLog;
		case EBlockFace::Front:
			return EBlockTexture::MangroveLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::MangroveLog;
		case EBlockFace::Back:
			return EBlockTexture::MangroveLog;
		case EBlockFace::Front:
			return EBlockTexture::MangroveLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangrovePlanks:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangrovePressurePlate:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangrovePressurePlateDown:
	{
		return EBlockTexture::MangrovePlanks;
	}
	case EBlockType::MangrovePropagule:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangrovePropaguleHanging0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangrovePropaguleHanging1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangrovePropaguleHanging2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangrovePropaguleHanging3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangrovePropaguleHanging4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangroveRoots:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangroveRootsTop;
		case EBlockFace::Bottom:
			return EBlockTexture::MangroveRootsTop;
		case EBlockFace::Side:
			return EBlockTexture::MangroveRootsSide;
		case EBlockFace::Back:
			return EBlockTexture::MangroveRootsSide;
		case EBlockFace::Front:
			return EBlockTexture::MangroveRootsSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MangroveSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Side:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Back:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Front:
			return EBlockTexture::MangrovePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Side:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Back:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Front:
			return EBlockTexture::MangrovePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Side:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Back:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Front:
			return EBlockTexture::MangrovePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Side:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Back:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Front:
			return EBlockTexture::MangrovePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Side:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Back:
			return EBlockTexture::MangrovePlanks;
		case EBlockFace::Front:
			return EBlockTexture::MangrovePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MangroveTrapdoorBottom:
	{
		return EBlockTexture::MangroveTrapdoor;
	}
	case EBlockType::MangroveTrapdoorOpen:
	{
		return EBlockTexture::MangroveTrapdoor;
	}
	case EBlockType::MangroveTrapdoorTop:
	{
		return EBlockTexture::MangroveTrapdoor;
	}
	case EBlockType::MangroveWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::MangroveLog;
		case EBlockFace::Back:
			return EBlockTexture::MangroveLog;
		case EBlockFace::Front:
			return EBlockTexture::MangroveLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MediumAmethystBud:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Melon:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::MelonSide;
		case EBlockFace::Back:
			return EBlockTexture::MelonSide;
		case EBlockFace::Front:
			return EBlockTexture::MelonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MelonStemStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MelonStemStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MelonStemStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MelonStemStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MelonStemStage4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MelonStemStage5:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MelonStemStage6:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MelonStemStage7:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossBlock:
	{
		return EBlockTexture::MossBlock;
	}
	case EBlockType::MossCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyCarpetSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyCobblestone:
	{
		return EBlockTexture::MossyCobblestone;
	}
	case EBlockType::MossyCobblestoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Side:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Back:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Front:
			return EBlockTexture::MossyCobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyCobblestoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Side:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Back:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Front:
			return EBlockTexture::MossyCobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyCobblestoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Side:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Back:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Front:
			return EBlockTexture::MossyCobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyCobblestoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Side:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Back:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Front:
			return EBlockTexture::MossyCobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyCobblestoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Side:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Back:
			return EBlockTexture::MossyCobblestone;
		case EBlockFace::Front:
			return EBlockTexture::MossyCobblestone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyCobblestoneWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyCobblestoneWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyCobblestoneWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyCobblestoneWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyStoneBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::MossyStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyStoneBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::MossyStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyStoneBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::MossyStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyStoneBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::MossyStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyStoneBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::MossyStoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::MossyStoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MossyStoneBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyStoneBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyStoneBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyStoneBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MossyStoneBricks:
	{
		return EBlockTexture::MossyStoneBricks;
	}
	case EBlockType::MovingPiston:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Mud:
	{
		return EBlockTexture::Mud;
	}
	case EBlockType::MudBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MudBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MudBricks;
		case EBlockFace::Side:
			return EBlockTexture::MudBricks;
		case EBlockFace::Back:
			return EBlockTexture::MudBricks;
		case EBlockFace::Front:
			return EBlockTexture::MudBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MudBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MudBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MudBricks;
		case EBlockFace::Side:
			return EBlockTexture::MudBricks;
		case EBlockFace::Back:
			return EBlockTexture::MudBricks;
		case EBlockFace::Front:
			return EBlockTexture::MudBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MudBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MudBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MudBricks;
		case EBlockFace::Side:
			return EBlockTexture::MudBricks;
		case EBlockFace::Back:
			return EBlockTexture::MudBricks;
		case EBlockFace::Front:
			return EBlockTexture::MudBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MudBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MudBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MudBricks;
		case EBlockFace::Side:
			return EBlockTexture::MudBricks;
		case EBlockFace::Back:
			return EBlockTexture::MudBricks;
		case EBlockFace::Front:
			return EBlockTexture::MudBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MudBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MudBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::MudBricks;
		case EBlockFace::Side:
			return EBlockTexture::MudBricks;
		case EBlockFace::Back:
			return EBlockTexture::MudBricks;
		case EBlockFace::Front:
			return EBlockTexture::MudBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MudBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MudBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MudBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MudBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::MudBricks:
	{
		return EBlockTexture::MudBricks;
	}
	case EBlockType::MudBricksNorthWestMirrored:
	{
		return EBlockTexture::MudBricks;
	}
	case EBlockType::MuddyMangroveRoots:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::MuddyMangroveRootsSide;
		case EBlockFace::Back:
			return EBlockTexture::MuddyMangroveRootsSide;
		case EBlockFace::Front:
			return EBlockTexture::MuddyMangroveRootsSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::MushroomBlockInside:
	{
		return EBlockTexture::MushroomBlockInside;
	}
	case EBlockType::MushroomStem:
	{
		return EBlockTexture::MushroomStem;
	}
	case EBlockType::MushroomStemInventory:
	{
		return EBlockTexture::MushroomStem;
	}
	case EBlockType::Mycelium:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::MyceliumTop;
		case EBlockFace::Bottom:
			return EBlockTexture::Dirt;
		case EBlockFace::Side:
			return EBlockTexture::MyceliumSide;
		case EBlockFace::Back:
			return EBlockTexture::MyceliumSide;
		case EBlockFace::Front:
			return EBlockTexture::MyceliumSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::NetherBrickFenceInventory:
	{
		return EBlockTexture::NetherBricks;
	}
	case EBlockType::NetherBrickFencePost:
	{
		return EBlockTexture::NetherBricks;
	}
	case EBlockType::NetherBrickFenceSide:
	{
		return EBlockTexture::NetherBricks;
	}
	case EBlockType::NetherBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::NetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::NetherBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::NetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::NetherBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::NetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::NetherBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::NetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::NetherBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::NetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::NetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::NetherBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherBricks:
	{
		return EBlockTexture::NetherBricks;
	}
	case EBlockType::NetherGoldOre:
	{
		return EBlockTexture::NetherGoldOre;
	}
	case EBlockType::NetherPortalEw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherPortalNs:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherQuartzOre:
	{
		return EBlockTexture::NetherQuartzOre;
	}
	case EBlockType::NetherSprouts:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherWartBlock:
	{
		return EBlockTexture::NetherWartBlock;
	}
	case EBlockType::NetherWartStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherWartStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetherWartStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::NetheriteBlock:
	{
		return EBlockTexture::NetheriteBlock;
	}
	case EBlockType::Netherrack:
	{
		return EBlockTexture::Netherrack;
	}
	case EBlockType::NoteBlock:
	{
		return EBlockTexture::NoteBlock;
	}
	case EBlockType::OakButton:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakButtonInventory:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakButtonPressed:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakFenceGate:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakFenceGateOpen:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakFenceGateWall:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakFenceGateWallOpen:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakFenceInventory:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakFencePost:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakFenceSide:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OakLeaves:
	{
		return EBlockTexture::OakLeaves;
	}
	case EBlockType::OakLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::OakLog;
		case EBlockFace::Back:
			return EBlockTexture::OakLog;
		case EBlockFace::Front:
			return EBlockTexture::OakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::OakLog;
		case EBlockFace::Back:
			return EBlockTexture::OakLog;
		case EBlockFace::Front:
			return EBlockTexture::OakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakPlanks:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakPressurePlate:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakPressurePlateDown:
	{
		return EBlockTexture::OakPlanks;
	}
	case EBlockType::OakSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OakSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OakSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::OakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::OakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::OakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::OakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::OakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OakTrapdoorBottom:
	{
		return EBlockTexture::OakTrapdoor;
	}
	case EBlockType::OakTrapdoorOpen:
	{
		return EBlockTexture::OakTrapdoor;
	}
	case EBlockType::OakTrapdoorTop:
	{
		return EBlockTexture::OakTrapdoor;
	}
	case EBlockType::OakWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::OakLog;
		case EBlockFace::Back:
			return EBlockTexture::OakLog;
		case EBlockFace::Front:
			return EBlockTexture::OakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Observer:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ObserverTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ObserverBack;
		case EBlockFace::Side:
			return EBlockTexture::ObserverSide;
		case EBlockFace::Back:
			return EBlockTexture::ObserverSide;
		case EBlockFace::Front:
			return EBlockTexture::ObserverFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ObserverOn:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::ObserverBackOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Obsidian:
	{
		return EBlockTexture::Obsidian;
	}
	case EBlockType::OchreFroglight:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::OchreFroglightSide;
		case EBlockFace::Back:
			return EBlockTexture::OchreFroglightSide;
		case EBlockFace::Front:
			return EBlockTexture::OchreFroglightSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OchreFroglightHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::OchreFroglightSide;
		case EBlockFace::Back:
			return EBlockTexture::OchreFroglightSide;
		case EBlockFace::Front:
			return EBlockTexture::OchreFroglightSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OpenEyeblossom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OrangeCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OrangeCandleFourCandles:
	{
		return EBlockTexture::OrangeCandle;
	}
	case EBlockType::OrangeCandleFourCandlesLit:
	{
		return EBlockTexture::OrangeCandleLit;
	}
	case EBlockType::OrangeCandleOneCandle:
	{
		return EBlockTexture::OrangeCandle;
	}
	case EBlockType::OrangeCandleOneCandleLit:
	{
		return EBlockTexture::OrangeCandleLit;
	}
	case EBlockType::OrangeCandleThreeCandles:
	{
		return EBlockTexture::OrangeCandle;
	}
	case EBlockType::OrangeCandleThreeCandlesLit:
	{
		return EBlockTexture::OrangeCandleLit;
	}
	case EBlockType::OrangeCandleTwoCandles:
	{
		return EBlockTexture::OrangeCandle;
	}
	case EBlockType::OrangeCandleTwoCandlesLit:
	{
		return EBlockTexture::OrangeCandleLit;
	}
	case EBlockType::OrangeCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeConcrete:
	{
		return EBlockTexture::OrangeConcrete;
	}
	case EBlockType::OrangeConcretePowder:
	{
		return EBlockTexture::OrangeConcretePowder;
	}
	case EBlockType::OrangeGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeStainedGlass:
	{
		return EBlockTexture::OrangeStainedGlass;
	}
	case EBlockType::OrangeStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeTerracotta:
	{
		return EBlockTexture::OrangeTerracotta;
	}
	case EBlockType::OrangeTulip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrangeWool:
	{
		return EBlockTexture::OrangeWool;
	}
	case EBlockType::OrientableVertical:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OrientableWithBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OuterStairs:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxeyeDaisy:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedChiseledCopper:
	{
		return EBlockTexture::OxidizedChiseledCopper;
	}
	case EBlockType::OxidizedCopper:
	{
		return EBlockTexture::OxidizedCopper;
	}
	case EBlockType::OxidizedCopperBarsCap:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperBarsCapAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperBarsPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperBarsPostEnds:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperBarsSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperBarsSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperBulb:
	{
		return EBlockTexture::OxidizedCopperBulb;
	}
	case EBlockType::OxidizedCopperBulbLit:
	{
		return EBlockTexture::OxidizedCopperBulbLit;
	}
	case EBlockType::OxidizedCopperBulbLitPowered:
	{
		return EBlockTexture::OxidizedCopperBulbLitPowered;
	}
	case EBlockType::OxidizedCopperBulbPowered:
	{
		return EBlockTexture::OxidizedCopperBulbPowered;
	}
	case EBlockType::OxidizedCopperChain:
	{
		return EBlockTexture::OxidizedCopperChain;
	}
	case EBlockType::OxidizedCopperChest:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCopperDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCopperDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCopperDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCopperDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCopperDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCopperDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCopperDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCopperGolemStatue:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperGrate:
	{
		return EBlockTexture::OxidizedCopperGrate;
	}
	case EBlockType::OxidizedCopperLantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperLanternHanging:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::OxidizedCopperTrapdoorBottom:
	{
		return EBlockTexture::OxidizedCopperTrapdoor;
	}
	case EBlockType::OxidizedCopperTrapdoorOpen:
	{
		return EBlockTexture::OxidizedCopperTrapdoor;
	}
	case EBlockType::OxidizedCopperTrapdoorTop:
	{
		return EBlockTexture::OxidizedCopperTrapdoor;
	}
	case EBlockType::OxidizedCutCopper:
	{
		return EBlockTexture::OxidizedCutCopper;
	}
	case EBlockType::OxidizedCutCopperSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::OxidizedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCutCopperSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::OxidizedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCutCopperStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::OxidizedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCutCopperStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::OxidizedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedCutCopperStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::OxidizedCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::OxidizedCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::OxidizedLightningRod:
	{
		return EBlockTexture::OxidizedLightningRod;
	}
	case EBlockType::PackedIce:
	{
		return EBlockTexture::PackedIce;
	}
	case EBlockType::PackedMud:
	{
		return EBlockTexture::PackedMud;
	}
	case EBlockType::PaleHangingMoss:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PaleHangingMossTip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PaleMossBlock:
	{
		return EBlockTexture::PaleMossBlock;
	}
	case EBlockType::PaleMossCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PaleMossCarpetSideSmall:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PaleMossCarpetSideSmall;
		case EBlockFace::Back:
			return EBlockTexture::PaleMossCarpetSideSmall;
		case EBlockFace::Front:
			return EBlockTexture::PaleMossCarpetSideSmall;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleMossCarpetSideTall:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PaleMossCarpetSideTall;
		case EBlockFace::Back:
			return EBlockTexture::PaleMossCarpetSideTall;
		case EBlockFace::Front:
			return EBlockTexture::PaleMossCarpetSideTall;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakButton:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakButtonInventory:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakButtonPressed:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakFenceGate:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakFenceGateOpen:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakFenceGateWall:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakFenceGateWallOpen:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakFenceInventory:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakFencePost:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakFenceSide:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PaleOakLeaves:
	{
		return EBlockTexture::PaleOakLeaves;
	}
	case EBlockType::PaleOakLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PaleOakLog;
		case EBlockFace::Back:
			return EBlockTexture::PaleOakLog;
		case EBlockFace::Front:
			return EBlockTexture::PaleOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PaleOakLog;
		case EBlockFace::Back:
			return EBlockTexture::PaleOakLog;
		case EBlockFace::Front:
			return EBlockTexture::PaleOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakPlanks:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakPressurePlate:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakPressurePlateDown:
	{
		return EBlockTexture::PaleOakPlanks;
	}
	case EBlockType::PaleOakSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PaleOakSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PaleOakSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::PaleOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::PaleOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::PaleOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::PaleOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::PaleOakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::PaleOakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PaleOakTrapdoorBottom:
	{
		return EBlockTexture::PaleOakTrapdoor;
	}
	case EBlockType::PaleOakTrapdoorOpen:
	{
		return EBlockTexture::PaleOakTrapdoor;
	}
	case EBlockType::PaleOakTrapdoorTop:
	{
		return EBlockTexture::PaleOakTrapdoor;
	}
	case EBlockType::PaleOakWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PaleOakLog;
		case EBlockFace::Back:
			return EBlockTexture::PaleOakLog;
		case EBlockFace::Front:
			return EBlockTexture::PaleOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PearlescentFroglight:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PearlescentFroglightSide;
		case EBlockFace::Back:
			return EBlockTexture::PearlescentFroglightSide;
		case EBlockFace::Front:
			return EBlockTexture::PearlescentFroglightSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PearlescentFroglightHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PearlescentFroglightSide;
		case EBlockFace::Back:
			return EBlockTexture::PearlescentFroglightSide;
		case EBlockFace::Front:
			return EBlockTexture::PearlescentFroglightSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PeonyBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PeonyTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PetrifiedOakSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::OakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PetrifiedOakSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Side:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Back:
			return EBlockTexture::OakPlanks;
		case EBlockFace::Front:
			return EBlockTexture::OakPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PinkCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PinkCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PinkCandleFourCandles:
	{
		return EBlockTexture::PinkCandle;
	}
	case EBlockType::PinkCandleFourCandlesLit:
	{
		return EBlockTexture::PinkCandleLit;
	}
	case EBlockType::PinkCandleOneCandle:
	{
		return EBlockTexture::PinkCandle;
	}
	case EBlockType::PinkCandleOneCandleLit:
	{
		return EBlockTexture::PinkCandleLit;
	}
	case EBlockType::PinkCandleThreeCandles:
	{
		return EBlockTexture::PinkCandle;
	}
	case EBlockType::PinkCandleThreeCandlesLit:
	{
		return EBlockTexture::PinkCandleLit;
	}
	case EBlockType::PinkCandleTwoCandles:
	{
		return EBlockTexture::PinkCandle;
	}
	case EBlockType::PinkCandleTwoCandlesLit:
	{
		return EBlockTexture::PinkCandleLit;
	}
	case EBlockType::PinkCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkConcrete:
	{
		return EBlockTexture::PinkConcrete;
	}
	case EBlockType::PinkConcretePowder:
	{
		return EBlockTexture::PinkConcretePowder;
	}
	case EBlockType::PinkGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkPetals1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkPetals2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkPetals3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkPetals4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkStainedGlass:
	{
		return EBlockTexture::PinkStainedGlass;
	}
	case EBlockType::PinkStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkTerracotta:
	{
		return EBlockTexture::PinkTerracotta;
	}
	case EBlockType::PinkTulip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PinkWool:
	{
		return EBlockTexture::PinkWool;
	}
	case EBlockType::Piston:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::PistonBottom;
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PistonBase:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::PistonBottom;
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PistonExtended:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PistonHead:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PistonHeadShort:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PistonHeadShortSticky:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PistonHeadSticky:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PistonInventory:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PistonTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PistonBottom;
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PitcherCropBottomStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropBottomStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropBottomStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropBottomStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropBottomStage4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropTopStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropTopStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropTopStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropTopStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherCropTopStage4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PitcherPlantBottom:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::PitcherCropBottomStage4;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PitcherPlantTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PitcherCropTopStage4;
		case EBlockFace::Bottom:
			return EBlockTexture::PitcherCropTopStage4;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Podzol:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PodzolTop;
		case EBlockFace::Bottom:
			return EBlockTexture::Dirt;
		case EBlockFace::Side:
			return EBlockTexture::PodzolSide;
		case EBlockFace::Back:
			return EBlockTexture::PodzolSide;
		case EBlockFace::Front:
			return EBlockTexture::PodzolSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PointedDripstone:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneDownBase:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneDownFrustum:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneDownMiddle:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneDownTip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneDownTipMerge:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneUpBase:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneUpFrustum:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneUpMiddle:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneUpTip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PointedDripstoneUpTipMerge:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedAndesite:
	{
		return EBlockTexture::PolishedAndesite;
	}
	case EBlockType::PolishedAndesiteSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedAndesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedAndesiteSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedAndesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedAndesiteStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedAndesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedAndesiteStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedAndesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedAndesiteStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedAndesite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedAndesite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBasalt:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PolishedBasaltSide;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBasaltSide;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBasaltSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstone:
	{
		return EBlockTexture::PolishedBlackstone;
	}
	case EBlockType::PolishedBlackstoneBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedBlackstoneBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedBlackstoneBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedBlackstoneBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedBlackstoneBricks:
	{
		return EBlockTexture::PolishedBlackstoneBricks;
	}
	case EBlockType::PolishedBlackstoneButton:
	{
		return EBlockTexture::PolishedBlackstone;
	}
	case EBlockType::PolishedBlackstoneButtonInventory:
	{
		return EBlockTexture::PolishedBlackstone;
	}
	case EBlockType::PolishedBlackstoneButtonPressed:
	{
		return EBlockTexture::PolishedBlackstone;
	}
	case EBlockType::PolishedBlackstonePressurePlate:
	{
		return EBlockTexture::PolishedBlackstone;
	}
	case EBlockType::PolishedBlackstonePressurePlateDown:
	{
		return EBlockTexture::PolishedBlackstone;
	}
	case EBlockType::PolishedBlackstoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Side:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Back:
			return EBlockTexture::PolishedBlackstone;
		case EBlockFace::Front:
			return EBlockTexture::PolishedBlackstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedBlackstoneWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedBlackstoneWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedBlackstoneWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedBlackstoneWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedDeepslate:
	{
		return EBlockTexture::PolishedDeepslate;
	}
	case EBlockType::PolishedDeepslateSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDeepslateSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDeepslateStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDeepslateStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDeepslateStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDeepslate;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDeepslate;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDeepslateWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedDeepslateWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedDeepslateWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedDeepslateWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedDiorite:
	{
		return EBlockTexture::PolishedDiorite;
	}
	case EBlockType::PolishedDioriteSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDiorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDioriteSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDiorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDioriteStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDiorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDioriteStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDiorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedDioriteStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedDiorite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedDiorite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedGranite:
	{
		return EBlockTexture::PolishedGranite;
	}
	case EBlockType::PolishedGraniteSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedGranite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedGraniteSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedGranite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedGraniteStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedGranite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedGraniteStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedGranite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedGraniteStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Side:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Back:
			return EBlockTexture::PolishedGranite;
		case EBlockFace::Front:
			return EBlockTexture::PolishedGranite;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedTuff:
	{
		return EBlockTexture::PolishedTuff;
	}
	case EBlockType::PolishedTuffSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Side:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Back:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Front:
			return EBlockTexture::PolishedTuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedTuffSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Side:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Back:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Front:
			return EBlockTexture::PolishedTuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedTuffStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Side:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Back:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Front:
			return EBlockTexture::PolishedTuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedTuffStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Side:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Back:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Front:
			return EBlockTexture::PolishedTuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedTuffStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Bottom:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Side:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Back:
			return EBlockTexture::PolishedTuff;
		case EBlockFace::Front:
			return EBlockTexture::PolishedTuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PolishedTuffWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedTuffWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedTuffWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PolishedTuffWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Poppy:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PotatoesStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PotatoesStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PotatoesStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PotatoesStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedAcaciaSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedAllium:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedAzaleaBush:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PottedAzaleaBushTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PottedAzaleaBushTop;
		case EBlockFace::Side:
			return EBlockTexture::PottedAzaleaBushSide;
		case EBlockFace::Back:
			return EBlockTexture::PottedAzaleaBushSide;
		case EBlockFace::Front:
			return EBlockTexture::PottedAzaleaBushSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PottedAzureBluet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedBamboo:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedBirchSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedBlueOrchid:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedBrownMushroom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedCactus:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedCherrySapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedClosedEyeblossom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedCornflower:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedCrimsonFungus:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedCrimsonRoots:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedDandelion:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedDarkOakSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedDeadBush:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedFern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedFloweringAzaleaBush:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PottedFloweringAzaleaBushTop;
		case EBlockFace::Bottom:
			return EBlockTexture::PottedFloweringAzaleaBushTop;
		case EBlockFace::Side:
			return EBlockTexture::PottedFloweringAzaleaBushSide;
		case EBlockFace::Back:
			return EBlockTexture::PottedFloweringAzaleaBushSide;
		case EBlockFace::Front:
			return EBlockTexture::PottedFloweringAzaleaBushSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PottedJungleSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedLilyOfTheValley:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedMangrovePropagule:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedOakSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedOpenEyeblossom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedOrangeTulip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedOxeyeDaisy:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedPaleOakSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedPinkTulip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedPoppy:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedRedMushroom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedRedTulip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedSpruceSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedTorchflower:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedWarpedFungus:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedWarpedRoots:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedWhiteTulip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PottedWitherRose:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PowderSnow:
	{
		return EBlockTexture::PowderSnow;
	}
	case EBlockType::PowderSnowCauldronFull:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PowderSnowCauldronLevel1:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PowderSnowCauldronLevel2:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PoweredRail:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PoweredRailOn:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PoweredRailOnRaisedNe:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PoweredRailOnRaisedSw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PoweredRailRaisedNe:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PoweredRailRaisedSw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PressurePlateDown:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PressurePlateUp:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Prismarine:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Side:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Back:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Front:
			return EBlockTexture::PrismarineBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PrismarineBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Side:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Back:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Front:
			return EBlockTexture::PrismarineBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PrismarineBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Side:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Back:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Front:
			return EBlockTexture::PrismarineBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PrismarineBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Side:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Back:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Front:
			return EBlockTexture::PrismarineBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PrismarineBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Side:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Back:
			return EBlockTexture::PrismarineBricks;
		case EBlockFace::Front:
			return EBlockTexture::PrismarineBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PrismarineBricks:
	{
		return EBlockTexture::PrismarineBricks;
	}
	case EBlockType::PrismarineSlab:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineSlabTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineStairs:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineStairsInner:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineStairsOuter:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PrismarineWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Pumpkin:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PumpkinSide;
		case EBlockFace::Back:
			return EBlockTexture::PumpkinSide;
		case EBlockFace::Front:
			return EBlockTexture::PumpkinSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PumpkinStemStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PumpkinStemStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PumpkinStemStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PumpkinStemStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PumpkinStemStage4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PumpkinStemStage5:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PumpkinStemStage6:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PumpkinStemStage7:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PurpleCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PurpleCandleFourCandles:
	{
		return EBlockTexture::PurpleCandle;
	}
	case EBlockType::PurpleCandleFourCandlesLit:
	{
		return EBlockTexture::PurpleCandleLit;
	}
	case EBlockType::PurpleCandleOneCandle:
	{
		return EBlockTexture::PurpleCandle;
	}
	case EBlockType::PurpleCandleOneCandleLit:
	{
		return EBlockTexture::PurpleCandleLit;
	}
	case EBlockType::PurpleCandleThreeCandles:
	{
		return EBlockTexture::PurpleCandle;
	}
	case EBlockType::PurpleCandleThreeCandlesLit:
	{
		return EBlockTexture::PurpleCandleLit;
	}
	case EBlockType::PurpleCandleTwoCandles:
	{
		return EBlockTexture::PurpleCandle;
	}
	case EBlockType::PurpleCandleTwoCandlesLit:
	{
		return EBlockTexture::PurpleCandleLit;
	}
	case EBlockType::PurpleCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleConcrete:
	{
		return EBlockTexture::PurpleConcrete;
	}
	case EBlockType::PurpleConcretePowder:
	{
		return EBlockTexture::PurpleConcretePowder;
	}
	case EBlockType::PurpleGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleStainedGlass:
	{
		return EBlockTexture::PurpleStainedGlass;
	}
	case EBlockType::PurpleStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::PurpleTerracotta:
	{
		return EBlockTexture::PurpleTerracotta;
	}
	case EBlockType::PurpleWool:
	{
		return EBlockTexture::PurpleWool;
	}
	case EBlockType::PurpurBlock:
	{
		return EBlockTexture::PurpurBlock;
	}
	case EBlockType::PurpurPillar:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PurpurPillar;
		case EBlockFace::Back:
			return EBlockTexture::PurpurPillar;
		case EBlockFace::Front:
			return EBlockTexture::PurpurPillar;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PurpurPillarHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::PurpurPillar;
		case EBlockFace::Back:
			return EBlockTexture::PurpurPillar;
		case EBlockFace::Front:
			return EBlockTexture::PurpurPillar;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PurpurSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Bottom:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Side:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Back:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Front:
			return EBlockTexture::PurpurBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PurpurSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Bottom:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Side:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Back:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Front:
			return EBlockTexture::PurpurBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PurpurStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Bottom:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Side:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Back:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Front:
			return EBlockTexture::PurpurBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PurpurStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Bottom:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Side:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Back:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Front:
			return EBlockTexture::PurpurBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::PurpurStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Bottom:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Side:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Back:
			return EBlockTexture::PurpurBlock;
		case EBlockFace::Front:
			return EBlockTexture::PurpurBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::QuartzBlock:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::QuartzBricks:
	{
		return EBlockTexture::QuartzBricks;
	}
	case EBlockType::QuartzPillar:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::QuartzPillar;
		case EBlockFace::Back:
			return EBlockTexture::QuartzPillar;
		case EBlockFace::Front:
			return EBlockTexture::QuartzPillar;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::QuartzPillarHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::QuartzPillar;
		case EBlockFace::Back:
			return EBlockTexture::QuartzPillar;
		case EBlockFace::Front:
			return EBlockTexture::QuartzPillar;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::QuartzSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::QuartzSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::QuartzStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::QuartzStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::QuartzStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockTop;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockSide;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Rail:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RailCorner:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RailCurved:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RailFlat:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RailRaisedNe:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RailRaisedSw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RawCopperBlock:
	{
		return EBlockTexture::RawCopperBlock;
	}
	case EBlockType::RawGoldBlock:
	{
		return EBlockTexture::RawGoldBlock;
	}
	case EBlockType::RawIronBlock:
	{
		return EBlockTexture::RawIronBlock;
	}
	case EBlockType::RedCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedCandleFourCandles:
	{
		return EBlockTexture::RedCandle;
	}
	case EBlockType::RedCandleFourCandlesLit:
	{
		return EBlockTexture::RedCandleLit;
	}
	case EBlockType::RedCandleOneCandle:
	{
		return EBlockTexture::RedCandle;
	}
	case EBlockType::RedCandleOneCandleLit:
	{
		return EBlockTexture::RedCandleLit;
	}
	case EBlockType::RedCandleThreeCandles:
	{
		return EBlockTexture::RedCandle;
	}
	case EBlockType::RedCandleThreeCandlesLit:
	{
		return EBlockTexture::RedCandleLit;
	}
	case EBlockType::RedCandleTwoCandles:
	{
		return EBlockTexture::RedCandle;
	}
	case EBlockType::RedCandleTwoCandlesLit:
	{
		return EBlockTexture::RedCandleLit;
	}
	case EBlockType::RedCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedConcrete:
	{
		return EBlockTexture::RedConcrete;
	}
	case EBlockType::RedConcretePowder:
	{
		return EBlockTexture::RedConcretePowder;
	}
	case EBlockType::RedGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedMushroom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedMushroomBlock:
	{
		return EBlockTexture::RedMushroomBlock;
	}
	case EBlockType::RedMushroomBlockInventory:
	{
		return EBlockTexture::RedMushroomBlock;
	}
	case EBlockType::RedNetherBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::RedNetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedNetherBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::RedNetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedNetherBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::RedNetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedNetherBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::RedNetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedNetherBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Side:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Back:
			return EBlockTexture::RedNetherBricks;
		case EBlockFace::Front:
			return EBlockTexture::RedNetherBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedNetherBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedNetherBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedNetherBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedNetherBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedNetherBricks:
	{
		return EBlockTexture::RedNetherBricks;
	}
	case EBlockType::RedSand:
	{
		return EBlockTexture::RedSand;
	}
	case EBlockType::RedSandstone:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedSandstoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedSandstoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedSandstoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedSandstoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedSandstoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstone;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RedSandstoneWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedSandstoneWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedSandstoneWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedSandstoneWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedStainedGlass:
	{
		return EBlockTexture::RedStainedGlass;
	}
	case EBlockType::RedStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedTerracotta:
	{
		return EBlockTexture::RedTerracotta;
	}
	case EBlockType::RedTulip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedWool:
	{
		return EBlockTexture::RedWool;
	}
	case EBlockType::RedstoneBlock:
	{
		return EBlockTexture::RedstoneBlock;
	}
	case EBlockType::RedstoneDustDot:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneDustSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneDustSide0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneDustSide1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneDustSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneDustSideAlt0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneDustSideAlt1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneDustUp:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneLamp:
	{
		return EBlockTexture::RedstoneLamp;
	}
	case EBlockType::RedstoneLampOn:
	{
		return EBlockTexture::RedstoneLampOn;
	}
	case EBlockType::RedstoneOre:
	{
		return EBlockTexture::RedstoneOre;
	}
	case EBlockType::RedstoneTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneTorchOff:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneWallTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RedstoneWallTorchOff:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ReinforcedDeepslate:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ReinforcedDeepslateTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ReinforcedDeepslateBottom;
		case EBlockFace::Side:
			return EBlockTexture::ReinforcedDeepslateSide;
		case EBlockFace::Back:
			return EBlockTexture::ReinforcedDeepslateSide;
		case EBlockFace::Front:
			return EBlockTexture::ReinforcedDeepslateSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater1tick:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Repeater;
		case EBlockFace::Bottom:
			return EBlockTexture::Repeater;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater1tickLocked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Repeater;
		case EBlockFace::Bottom:
			return EBlockTexture::Repeater;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater1tickOn:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RepeaterOn;
		case EBlockFace::Bottom:
			return EBlockTexture::RepeaterOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater1tickOnLocked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RepeaterOn;
		case EBlockFace::Bottom:
			return EBlockTexture::RepeaterOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater2tick:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Repeater;
		case EBlockFace::Bottom:
			return EBlockTexture::Repeater;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater2tickLocked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Repeater;
		case EBlockFace::Bottom:
			return EBlockTexture::Repeater;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater2tickOn:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RepeaterOn;
		case EBlockFace::Bottom:
			return EBlockTexture::RepeaterOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater2tickOnLocked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RepeaterOn;
		case EBlockFace::Bottom:
			return EBlockTexture::RepeaterOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater3tick:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Repeater;
		case EBlockFace::Bottom:
			return EBlockTexture::Repeater;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater3tickLocked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Repeater;
		case EBlockFace::Bottom:
			return EBlockTexture::Repeater;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater3tickOn:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RepeaterOn;
		case EBlockFace::Bottom:
			return EBlockTexture::RepeaterOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater3tickOnLocked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RepeaterOn;
		case EBlockFace::Bottom:
			return EBlockTexture::RepeaterOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater4tick:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Repeater;
		case EBlockFace::Bottom:
			return EBlockTexture::Repeater;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater4tickLocked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Repeater;
		case EBlockFace::Bottom:
			return EBlockTexture::Repeater;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater4tickOn:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RepeaterOn;
		case EBlockFace::Bottom:
			return EBlockTexture::RepeaterOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Repeater4tickOnLocked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RepeaterOn;
		case EBlockFace::Bottom:
			return EBlockTexture::RepeaterOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RepeatingCommandBlock:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RepeatingCommandBlockConditional:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ResinBlock:
	{
		return EBlockTexture::ResinBlock;
	}
	case EBlockType::ResinBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Side:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Back:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Front:
			return EBlockTexture::ResinBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ResinBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Side:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Back:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Front:
			return EBlockTexture::ResinBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ResinBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Side:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Back:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Front:
			return EBlockTexture::ResinBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ResinBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Side:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Back:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Front:
			return EBlockTexture::ResinBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ResinBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Side:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Back:
			return EBlockTexture::ResinBricks;
		case EBlockFace::Front:
			return EBlockTexture::ResinBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ResinBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ResinBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ResinBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ResinBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ResinBricks:
	{
		return EBlockTexture::ResinBricks;
	}
	case EBlockType::ResinClump:
	{
		return EBlockTexture::ResinClump;
	}
	case EBlockType::RespawnAnchor0:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RespawnAnchorTopOff;
		case EBlockFace::Bottom:
			return EBlockTexture::RespawnAnchorBottom;
		case EBlockFace::Side:
			return EBlockTexture::RespawnAnchorSide0;
		case EBlockFace::Back:
			return EBlockTexture::RespawnAnchorSide0;
		case EBlockFace::Front:
			return EBlockTexture::RespawnAnchorSide0;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RespawnAnchor1:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::RespawnAnchorBottom;
		case EBlockFace::Side:
			return EBlockTexture::RespawnAnchorSide1;
		case EBlockFace::Back:
			return EBlockTexture::RespawnAnchorSide1;
		case EBlockFace::Front:
			return EBlockTexture::RespawnAnchorSide1;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RespawnAnchor2:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::RespawnAnchorBottom;
		case EBlockFace::Side:
			return EBlockTexture::RespawnAnchorSide2;
		case EBlockFace::Back:
			return EBlockTexture::RespawnAnchorSide2;
		case EBlockFace::Front:
			return EBlockTexture::RespawnAnchorSide2;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RespawnAnchor3:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::RespawnAnchorBottom;
		case EBlockFace::Side:
			return EBlockTexture::RespawnAnchorSide3;
		case EBlockFace::Back:
			return EBlockTexture::RespawnAnchorSide3;
		case EBlockFace::Front:
			return EBlockTexture::RespawnAnchorSide3;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RespawnAnchor4:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::RespawnAnchorBottom;
		case EBlockFace::Side:
			return EBlockTexture::RespawnAnchorSide4;
		case EBlockFace::Back:
			return EBlockTexture::RespawnAnchorSide4;
		case EBlockFace::Front:
			return EBlockTexture::RespawnAnchorSide4;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::RootedDirt:
	{
		return EBlockTexture::RootedDirt;
	}
	case EBlockType::RoseBushBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::RoseBushTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Sand:
	{
		return EBlockTexture::Sand;
	}
	case EBlockType::Sandstone:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::Sandstone;
		case EBlockFace::Back:
			return EBlockTexture::Sandstone;
		case EBlockFace::Front:
			return EBlockTexture::Sandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SandstoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::Sandstone;
		case EBlockFace::Back:
			return EBlockTexture::Sandstone;
		case EBlockFace::Front:
			return EBlockTexture::Sandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SandstoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::Sandstone;
		case EBlockFace::Back:
			return EBlockTexture::Sandstone;
		case EBlockFace::Front:
			return EBlockTexture::Sandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SandstoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::Sandstone;
		case EBlockFace::Back:
			return EBlockTexture::Sandstone;
		case EBlockFace::Front:
			return EBlockTexture::Sandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SandstoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::Sandstone;
		case EBlockFace::Back:
			return EBlockTexture::Sandstone;
		case EBlockFace::Front:
			return EBlockTexture::Sandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SandstoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneBottom;
		case EBlockFace::Side:
			return EBlockTexture::Sandstone;
		case EBlockFace::Back:
			return EBlockTexture::Sandstone;
		case EBlockFace::Front:
			return EBlockTexture::Sandstone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SandstoneWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SandstoneWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SandstoneWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SandstoneWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ScaffoldingStable:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ScaffoldingTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ScaffoldingBottom;
		case EBlockFace::Side:
			return EBlockTexture::ScaffoldingSide;
		case EBlockFace::Back:
			return EBlockTexture::ScaffoldingSide;
		case EBlockFace::Front:
			return EBlockTexture::ScaffoldingSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::ScaffoldingUnstable:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::ScaffoldingTop;
		case EBlockFace::Bottom:
			return EBlockTexture::ScaffoldingBottom;
		case EBlockFace::Side:
			return EBlockTexture::ScaffoldingSide;
		case EBlockFace::Back:
			return EBlockTexture::ScaffoldingSide;
		case EBlockFace::Front:
			return EBlockTexture::ScaffoldingSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Sculk:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SculkCatalyst:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SculkCatalystTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SculkCatalystBottom;
		case EBlockFace::Side:
			return EBlockTexture::SculkCatalystSide;
		case EBlockFace::Back:
			return EBlockTexture::SculkCatalystSide;
		case EBlockFace::Front:
			return EBlockTexture::SculkCatalystSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SculkCatalystBloom:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::SculkCatalystBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SculkMirrored:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SculkSensor:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SculkSensorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SculkSensorBottom;
		case EBlockFace::Side:
			return EBlockTexture::SculkSensorSide;
		case EBlockFace::Back:
			return EBlockTexture::SculkSensorSide;
		case EBlockFace::Front:
			return EBlockTexture::SculkSensorSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SculkSensorActive:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SculkSensorInactive:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SculkShrieker:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SculkShriekerTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SculkShriekerBottom;
		case EBlockFace::Side:
			return EBlockTexture::SculkShriekerSide;
		case EBlockFace::Back:
			return EBlockTexture::SculkShriekerSide;
		case EBlockFace::Front:
			return EBlockTexture::SculkShriekerSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SculkShriekerCanSummon:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SculkShriekerTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SculkShriekerBottom;
		case EBlockFace::Side:
			return EBlockTexture::SculkShriekerSide;
		case EBlockFace::Back:
			return EBlockTexture::SculkShriekerSide;
		case EBlockFace::Front:
			return EBlockTexture::SculkShriekerSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SculkVein:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SeaLantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SeaPickle:
	{
		return EBlockTexture::SeaPickle;
	}
	case EBlockType::Seagrass:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ShortDryGrass:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ShortGrass:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Shroomlight:
	{
		return EBlockTexture::Shroomlight;
	}
	case EBlockType::ShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Skull:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Slab:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SlabTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SlightlyCrackedTurtleEgg:
	{
		return EBlockTexture::TurtleEggSlightlyCracked;
	}
	case EBlockType::SlimeBlock:
	{
		return EBlockTexture::SlimeBlock;
	}
	case EBlockType::SmallAmethystBud:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SmallDripleafBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SmallDripleafTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SmallDripleafTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SmallDripleafTop;
		case EBlockFace::Side:
			return EBlockTexture::SmallDripleafSide;
		case EBlockFace::Back:
			return EBlockTexture::SmallDripleafSide;
		case EBlockFace::Front:
			return EBlockTexture::SmallDripleafSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmithingTable:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Smoker:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SmokerTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SmokerBottom;
		case EBlockFace::Side:
			return EBlockTexture::SmokerSide;
		case EBlockFace::Back:
			return EBlockTexture::SmokerSide;
		case EBlockFace::Front:
			return EBlockTexture::SmokerFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmokerOn:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SmokerTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SmokerBottom;
		case EBlockFace::Side:
			return EBlockTexture::SmokerSide;
		case EBlockFace::Back:
			return EBlockTexture::SmokerSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothBasalt:
	{
		return EBlockTexture::SmoothBasalt;
	}
	case EBlockType::SmoothQuartz:
	{
		return EBlockTexture::QuartzBlockBottom;
	}
	case EBlockType::SmoothQuartzSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothQuartzSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothQuartzStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothQuartzStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothQuartzStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Bottom:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Side:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Back:
			return EBlockTexture::QuartzBlockBottom;
		case EBlockFace::Front:
			return EBlockTexture::QuartzBlockBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothRedSandstone:
	{
		return EBlockTexture::RedSandstoneTop;
	}
	case EBlockType::SmoothRedSandstoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothRedSandstoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothRedSandstoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothRedSandstoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothRedSandstoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::RedSandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::RedSandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothSandstone:
	{
		return EBlockTexture::SandstoneTop;
	}
	case EBlockType::SmoothSandstoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::SandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothSandstoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::SandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothSandstoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::SandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothSandstoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::SandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothSandstoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Side:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Back:
			return EBlockTexture::SandstoneTop;
		case EBlockFace::Front:
			return EBlockTexture::SandstoneTop;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothStone:
	{
		return EBlockTexture::SmoothStone;
	}
	case EBlockType::SmoothStoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SmoothStone;
		case EBlockFace::Bottom:
			return EBlockTexture::SmoothStone;
		case EBlockFace::Side:
			return EBlockTexture::SmoothStoneSlabSide;
		case EBlockFace::Back:
			return EBlockTexture::SmoothStoneSlabSide;
		case EBlockFace::Front:
			return EBlockTexture::SmoothStoneSlabSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothStoneSlabDouble:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::SmoothStoneSlabSide;
		case EBlockFace::Back:
			return EBlockTexture::SmoothStoneSlabSide;
		case EBlockFace::Front:
			return EBlockTexture::SmoothStoneSlabSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SmoothStoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SmoothStone;
		case EBlockFace::Bottom:
			return EBlockTexture::SmoothStone;
		case EBlockFace::Side:
			return EBlockTexture::SmoothStoneSlabSide;
		case EBlockFace::Back:
			return EBlockTexture::SmoothStoneSlabSide;
		case EBlockFace::Front:
			return EBlockTexture::SmoothStoneSlabSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SnifferEgg:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SnifferEggNotCracked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SnifferEggNotCrackedTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SnifferEggNotCrackedBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SnifferEggSlightlyCracked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SnifferEggSlightlyCrackedTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SnifferEggSlightlyCrackedBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SnifferEggVeryCracked:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SnifferEggVeryCrackedTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SnifferEggVeryCrackedBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SnowBlock:
	{
		return EBlockTexture::Snow;
	}
	case EBlockType::SnowHeight10:
	{
		return EBlockTexture::Snow;
	}
	case EBlockType::SnowHeight12:
	{
		return EBlockTexture::Snow;
	}
	case EBlockType::SnowHeight14:
	{
		return EBlockTexture::Snow;
	}
	case EBlockType::SnowHeight2:
	{
		return EBlockTexture::Snow;
	}
	case EBlockType::SnowHeight4:
	{
		return EBlockTexture::Snow;
	}
	case EBlockType::SnowHeight6:
	{
		return EBlockTexture::Snow;
	}
	case EBlockType::SnowHeight8:
	{
		return EBlockTexture::Snow;
	}
	case EBlockType::SoulCampfire:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulFireFloor0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulFireFloor1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulFireSide0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulFireSide1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulFireSideAlt0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulFireSideAlt1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulLantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulLanternHanging:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulSand:
	{
		return EBlockTexture::SoulSand;
	}
	case EBlockType::SoulSoil:
	{
		return EBlockTexture::SoulSoil;
	}
	case EBlockType::SoulTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SoulWallTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Spawner:
	{
		return EBlockTexture::Spawner;
	}
	case EBlockType::Sponge:
	{
		return EBlockTexture::Sponge;
	}
	case EBlockType::SporeBlossom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SpruceButton:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceButtonInventory:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceButtonPressed:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SpruceDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SpruceDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SpruceDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SpruceDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SpruceDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SpruceDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SpruceDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SpruceDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SpruceDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SpruceDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SpruceDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SpruceDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SpruceDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SpruceDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SpruceDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SpruceDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceFenceGate:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceFenceGateOpen:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceFenceGateWall:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceFenceGateWallOpen:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceFenceInventory:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceFencePost:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceFenceSide:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SpruceLeaves:
	{
		return EBlockTexture::SpruceLeaves;
	}
	case EBlockType::SpruceLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::SpruceLog;
		case EBlockFace::Back:
			return EBlockTexture::SpruceLog;
		case EBlockFace::Front:
			return EBlockTexture::SpruceLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::SpruceLog;
		case EBlockFace::Back:
			return EBlockTexture::SpruceLog;
		case EBlockFace::Front:
			return EBlockTexture::SpruceLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SprucePlanks:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SprucePressurePlate:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SprucePressurePlateDown:
	{
		return EBlockTexture::SprucePlanks;
	}
	case EBlockType::SpruceSapling:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SpruceSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SpruceSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Side:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Back:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Front:
			return EBlockTexture::SprucePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Side:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Back:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Front:
			return EBlockTexture::SprucePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Side:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Back:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Front:
			return EBlockTexture::SprucePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Side:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Back:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Front:
			return EBlockTexture::SprucePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Side:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Back:
			return EBlockTexture::SprucePlanks;
		case EBlockFace::Front:
			return EBlockTexture::SprucePlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SpruceTrapdoorBottom:
	{
		return EBlockTexture::SpruceTrapdoor;
	}
	case EBlockType::SpruceTrapdoorOpen:
	{
		return EBlockTexture::SpruceTrapdoor;
	}
	case EBlockType::SpruceTrapdoorTop:
	{
		return EBlockTexture::SpruceTrapdoor;
	}
	case EBlockType::SpruceWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::SpruceLog;
		case EBlockFace::Back:
			return EBlockTexture::SpruceLog;
		case EBlockFace::Front:
			return EBlockTexture::SpruceLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Stairs:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemFruit:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemGrowth0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemGrowth1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemGrowth2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemGrowth3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemGrowth4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemGrowth5:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemGrowth6:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StemGrowth7:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StickyPiston:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::PistonBottom;
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StickyPistonInventory:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::PistonTopSticky;
		case EBlockFace::Bottom:
			return EBlockTexture::PistonBottom;
		case EBlockFace::Side:
			return EBlockTexture::PistonSide;
		case EBlockFace::Back:
			return EBlockTexture::PistonSide;
		case EBlockFace::Front:
			return EBlockTexture::PistonSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Stone:
	{
		return EBlockTexture::Stone;
	}
	case EBlockType::StoneBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::StoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::StoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::StoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::StoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Side:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Back:
			return EBlockTexture::StoneBricks;
		case EBlockFace::Front:
			return EBlockTexture::StoneBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StoneBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StoneBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StoneBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::StoneBricks:
	{
		return EBlockTexture::StoneBricks;
	}
	case EBlockType::StoneButton:
	{
		return EBlockTexture::Stone;
	}
	case EBlockType::StoneButtonInventory:
	{
		return EBlockTexture::Stone;
	}
	case EBlockType::StoneButtonPressed:
	{
		return EBlockTexture::Stone;
	}
	case EBlockType::StoneMirrored:
	{
		return EBlockTexture::Stone;
	}
	case EBlockType::StonePressurePlate:
	{
		return EBlockTexture::Stone;
	}
	case EBlockType::StonePressurePlateDown:
	{
		return EBlockTexture::Stone;
	}
	case EBlockType::StoneSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Stone;
		case EBlockFace::Bottom:
			return EBlockTexture::Stone;
		case EBlockFace::Side:
			return EBlockTexture::Stone;
		case EBlockFace::Back:
			return EBlockTexture::Stone;
		case EBlockFace::Front:
			return EBlockTexture::Stone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Stone;
		case EBlockFace::Bottom:
			return EBlockTexture::Stone;
		case EBlockFace::Side:
			return EBlockTexture::Stone;
		case EBlockFace::Back:
			return EBlockTexture::Stone;
		case EBlockFace::Front:
			return EBlockTexture::Stone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Stone;
		case EBlockFace::Bottom:
			return EBlockTexture::Stone;
		case EBlockFace::Side:
			return EBlockTexture::Stone;
		case EBlockFace::Back:
			return EBlockTexture::Stone;
		case EBlockFace::Front:
			return EBlockTexture::Stone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Stone;
		case EBlockFace::Bottom:
			return EBlockTexture::Stone;
		case EBlockFace::Side:
			return EBlockTexture::Stone;
		case EBlockFace::Back:
			return EBlockTexture::Stone;
		case EBlockFace::Front:
			return EBlockTexture::Stone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StoneStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Stone;
		case EBlockFace::Bottom:
			return EBlockTexture::Stone;
		case EBlockFace::Side:
			return EBlockTexture::Stone;
		case EBlockFace::Back:
			return EBlockTexture::Stone;
		case EBlockFace::Front:
			return EBlockTexture::Stone;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Stonecutter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::StonecutterTop;
		case EBlockFace::Bottom:
			return EBlockTexture::StonecutterBottom;
		case EBlockFace::Side:
			return EBlockTexture::StonecutterSide;
		case EBlockFace::Back:
			return EBlockTexture::StonecutterSide;
		case EBlockFace::Front:
			return EBlockTexture::StonecutterSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedAcaciaLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedAcaciaLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedAcaciaLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedAcaciaLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedAcaciaLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedAcaciaLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedAcaciaLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedAcaciaLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedAcaciaWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedAcaciaLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedAcaciaLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedAcaciaLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedBambooBlock:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedBambooBlock;
		case EBlockFace::Back:
			return EBlockTexture::StrippedBambooBlock;
		case EBlockFace::Front:
			return EBlockTexture::StrippedBambooBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedBambooBlockX:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedBambooBlock;
		case EBlockFace::Back:
			return EBlockTexture::StrippedBambooBlock;
		case EBlockFace::Front:
			return EBlockTexture::StrippedBambooBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedBambooBlockY:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedBambooBlock;
		case EBlockFace::Back:
			return EBlockTexture::StrippedBambooBlock;
		case EBlockFace::Front:
			return EBlockTexture::StrippedBambooBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedBambooBlockZ:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedBambooBlock;
		case EBlockFace::Back:
			return EBlockTexture::StrippedBambooBlock;
		case EBlockFace::Front:
			return EBlockTexture::StrippedBambooBlock;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedBirchLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedBirchLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedBirchLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedBirchLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedBirchLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedBirchLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedBirchLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedBirchLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedBirchWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedBirchLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedBirchLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedBirchLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedCherryLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedCherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedCherryLogX:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedCherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedCherryLogY:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedCherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedCherryLogZ:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedCherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedCherryWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedCherryLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedCherryLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedCrimsonHyphae:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedCrimsonStem;
		case EBlockFace::Back:
			return EBlockTexture::StrippedCrimsonStem;
		case EBlockFace::Front:
			return EBlockTexture::StrippedCrimsonStem;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedCrimsonStem:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedCrimsonStem;
		case EBlockFace::Back:
			return EBlockTexture::StrippedCrimsonStem;
		case EBlockFace::Front:
			return EBlockTexture::StrippedCrimsonStem;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedDarkOakLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedDarkOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedDarkOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedDarkOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedDarkOakLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedDarkOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedDarkOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedDarkOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedDarkOakWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedDarkOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedDarkOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedDarkOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedJungleLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedJungleLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedJungleLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedJungleLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedJungleLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedJungleLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedJungleLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedJungleLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedJungleWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedJungleLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedJungleLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedJungleLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedMangroveLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedMangroveLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedMangroveLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedMangroveLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedMangroveLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedMangroveLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedMangroveLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedMangroveLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedMangroveWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedMangroveLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedMangroveLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedMangroveLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedOakLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedOakLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedOakWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedPaleOakLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedPaleOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedPaleOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedPaleOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedPaleOakLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedPaleOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedPaleOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedPaleOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedPaleOakWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedPaleOakLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedPaleOakLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedPaleOakLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedSpruceLog:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedSpruceLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedSpruceLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedSpruceLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedSpruceLogHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedSpruceLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedSpruceLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedSpruceLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedSpruceWood:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedSpruceLog;
		case EBlockFace::Back:
			return EBlockTexture::StrippedSpruceLog;
		case EBlockFace::Front:
			return EBlockTexture::StrippedSpruceLog;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedWarpedHyphae:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedWarpedStem;
		case EBlockFace::Back:
			return EBlockTexture::StrippedWarpedStem;
		case EBlockFace::Front:
			return EBlockTexture::StrippedWarpedStem;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StrippedWarpedStem:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::StrippedWarpedStem;
		case EBlockFace::Back:
			return EBlockTexture::StrippedWarpedStem;
		case EBlockFace::Front:
			return EBlockTexture::StrippedWarpedStem;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::StructureBlock:
	{
		return EBlockTexture::StructureBlock;
	}
	case EBlockType::StructureBlockCorner:
	{
		return EBlockTexture::StructureBlockCorner;
	}
	case EBlockType::StructureBlockData:
	{
		return EBlockTexture::StructureBlockData;
	}
	case EBlockType::StructureBlockLoad:
	{
		return EBlockTexture::StructureBlockLoad;
	}
	case EBlockType::StructureBlockSave:
	{
		return EBlockTexture::StructureBlockSave;
	}
	case EBlockType::StructureVoid:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SugarCane:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SunflowerBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SunflowerTop:
	{
		switch (face)
		{
		case EBlockFace::Back:
			return EBlockTexture::SunflowerBack;
		case EBlockFace::Front:
			return EBlockTexture::SunflowerFront;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::SuspiciousGravel0:
	{
		return EBlockTexture::SuspiciousGravel0;
	}
	case EBlockType::SuspiciousGravel1:
	{
		return EBlockTexture::SuspiciousGravel1;
	}
	case EBlockType::SuspiciousGravel2:
	{
		return EBlockTexture::SuspiciousGravel2;
	}
	case EBlockType::SuspiciousGravel3:
	{
		return EBlockTexture::SuspiciousGravel3;
	}
	case EBlockType::SuspiciousSand0:
	{
		return EBlockTexture::SuspiciousSand0;
	}
	case EBlockType::SuspiciousSand1:
	{
		return EBlockTexture::SuspiciousSand1;
	}
	case EBlockType::SuspiciousSand2:
	{
		return EBlockTexture::SuspiciousSand2;
	}
	case EBlockType::SuspiciousSand3:
	{
		return EBlockTexture::SuspiciousSand3;
	}
	case EBlockType::SweetBerryBushStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SweetBerryBushStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SweetBerryBushStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::SweetBerryBushStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TallDryGrass:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TallGrassBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TallGrassTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TallSeagrassBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TallSeagrassTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Target:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::TargetSide;
		case EBlockFace::Back:
			return EBlockTexture::TargetSide;
		case EBlockFace::Front:
			return EBlockTexture::TargetSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TemplateAnvil:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateAzalea:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateBarsCap:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateBarsCapAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateBarsPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateBarsPostEnds:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateBarsSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateBarsSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateCakeWithCandle:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TemplateCampfire:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateCandle:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateCauldronFull:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TemplateCauldronLevel1:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TemplateCauldronLevel2:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TemplateChiseledBookshelfSlotBottomLeft:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateChiseledBookshelfSlotBottomMid:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateChiseledBookshelfSlotBottomRight:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateChiseledBookshelfSlotTopLeft:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateChiseledBookshelfSlotTopMid:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateChiseledBookshelfSlotTopRight:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateChorusFlower:
	{
		switch (face)
		{
		case EBlockFace::Bottom:
			return EBlockTexture::ChorusPlant;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TemplateCommandBlock:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateCustomFenceGate:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateCustomFenceGateOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateCustomFenceGateWall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateCustomFenceGateWallOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateDaylightDetector:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFarmland:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFenceGate:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFenceGateOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFenceGateWall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFenceGateWallOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFireFloor:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFireSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFireSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFireUp:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFireUpAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFourCandles:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateFourTurtleEggs:
	{
		return EBlockTexture::TurtleEgg;
	}
	case EBlockType::TemplateGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateHangingLantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateItemFrame:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateItemFrameMap:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateLantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateLeafLitter1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateLeafLitter2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateLeafLitter3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateLeafLitter4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateLightningRod:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateOrientableTrapdoorBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateOrientableTrapdoorOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateOrientableTrapdoorTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplatePiston:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplatePistonHead:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplatePistonHeadShort:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplatePottedAzaleaBush:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateRailRaisedNe:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateRailRaisedSw:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateRedstoneTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateRedstoneTorchWall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateSculkShrieker:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::SculkShriekerTop;
		case EBlockFace::Bottom:
			return EBlockTexture::SculkShriekerBottom;
		case EBlockFace::Side:
			return EBlockTexture::SculkShriekerSide;
		case EBlockFace::Back:
			return EBlockTexture::SculkShriekerSide;
		case EBlockFace::Front:
			return EBlockTexture::SculkShriekerSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TemplateSeagrass:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateSingleFace:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateThreeCandles:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateThreeTurtleEggs:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTorchUnlit:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTorchWall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTorchWallUnlit:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTrapdoorBottom:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTrapdoorOpen:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTrapdoorTop:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTurtleEgg:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTwoCandles:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateTwoTurtleEggs:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateVault:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TemplateWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Terracotta:
	{
		return EBlockTexture::Terracotta;
	}
	case EBlockType::TestBlockAccept:
	{
		return EBlockTexture::TestBlockAccept;
	}
	case EBlockType::TestBlockFail:
	{
		return EBlockTexture::TestBlockFail;
	}
	case EBlockType::TestBlockLog:
	{
		return EBlockTexture::TestBlockLog;
	}
	case EBlockType::TestBlockStart:
	{
		return EBlockTexture::TestBlockStart;
	}
	case EBlockType::TestInstanceBlock:
	{
		return EBlockTexture::TestInstanceBlock;
	}
	case EBlockType::ThinBlock:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::ThreeDeadSeaPickles:
	{
		return EBlockTexture::SeaPickle;
	}
	case EBlockType::ThreeSeaPickles:
	{
		return EBlockTexture::SeaPickle;
	}
	case EBlockType::ThreeSlightlyCrackedTurtleEggs:
	{
		return EBlockTexture::TurtleEggSlightlyCracked;
	}
	case EBlockType::ThreeTurtleEggs:
	{
		return EBlockTexture::TurtleEgg;
	}
	case EBlockType::ThreeVeryCrackedTurtleEggs:
	{
		return EBlockTexture::TurtleEggVeryCracked;
	}
	case EBlockType::TintedCross:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TintedFlowerPotCross:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TintedGlass:
	{
		return EBlockTexture::TintedGlass;
	}
	case EBlockType::Tnt:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TntTop;
		case EBlockFace::Bottom:
			return EBlockTexture::TntBottom;
		case EBlockFace::Side:
			return EBlockTexture::TntSide;
		case EBlockFace::Back:
			return EBlockTexture::TntSide;
		case EBlockFace::Front:
			return EBlockTexture::TntSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::Torch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Torchflower:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TorchflowerCropStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TorchflowerCropStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TrappedChest:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TrialSpawner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TrialSpawnerTopInactive;
		case EBlockFace::Bottom:
			return EBlockTexture::TrialSpawnerBottom;
		case EBlockFace::Side:
			return EBlockTexture::TrialSpawnerSideInactive;
		case EBlockFace::Back:
			return EBlockTexture::TrialSpawnerSideInactive;
		case EBlockFace::Front:
			return EBlockTexture::TrialSpawnerSideInactive;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TrialSpawnerActive:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TrialSpawnerTopActive;
		case EBlockFace::Bottom:
			return EBlockTexture::TrialSpawnerBottom;
		case EBlockFace::Side:
			return EBlockTexture::TrialSpawnerSideActive;
		case EBlockFace::Back:
			return EBlockTexture::TrialSpawnerSideActive;
		case EBlockFace::Front:
			return EBlockTexture::TrialSpawnerSideActive;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TrialSpawnerActiveOminous:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TrialSpawnerTopActiveOminous;
		case EBlockFace::Bottom:
			return EBlockTexture::TrialSpawnerBottom;
		case EBlockFace::Side:
			return EBlockTexture::TrialSpawnerSideActiveOminous;
		case EBlockFace::Back:
			return EBlockTexture::TrialSpawnerSideActiveOminous;
		case EBlockFace::Front:
			return EBlockTexture::TrialSpawnerSideActiveOminous;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TrialSpawnerEjectingReward:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TrialSpawnerTopEjectingReward;
		case EBlockFace::Bottom:
			return EBlockTexture::TrialSpawnerBottom;
		case EBlockFace::Side:
			return EBlockTexture::TrialSpawnerSideActive;
		case EBlockFace::Back:
			return EBlockTexture::TrialSpawnerSideActive;
		case EBlockFace::Front:
			return EBlockTexture::TrialSpawnerSideActive;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TrialSpawnerEjectingRewardOminous:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TrialSpawnerTopEjectingRewardOminous;
		case EBlockFace::Bottom:
			return EBlockTexture::TrialSpawnerBottom;
		case EBlockFace::Side:
			return EBlockTexture::TrialSpawnerSideActiveOminous;
		case EBlockFace::Back:
			return EBlockTexture::TrialSpawnerSideActiveOminous;
		case EBlockFace::Front:
			return EBlockTexture::TrialSpawnerSideActiveOminous;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TrialSpawnerInactiveOminous:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TrialSpawnerTopInactiveOminous;
		case EBlockFace::Bottom:
			return EBlockTexture::TrialSpawnerBottom;
		case EBlockFace::Side:
			return EBlockTexture::TrialSpawnerSideInactiveOminous;
		case EBlockFace::Back:
			return EBlockTexture::TrialSpawnerSideInactiveOminous;
		case EBlockFace::Front:
			return EBlockTexture::TrialSpawnerSideInactiveOminous;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TripwireAttachedN:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireAttachedNe:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireAttachedNs:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireAttachedNse:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireAttachedNsew:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireHook:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TripwireHookAttached:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TripwireHookAttachedOn:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TripwireHookOn:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TripwireN:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireNe:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireNs:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireNse:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TripwireNsew:
	{
		return EBlockTexture::Tripwire;
	}
	case EBlockType::TubeCoral:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TubeCoralBlock:
	{
		return EBlockTexture::TubeCoralBlock;
	}
	case EBlockType::TubeCoralFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TubeCoralWallFan:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Tuff:
	{
		return EBlockTexture::Tuff;
	}
	case EBlockType::TuffBrickSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Side:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Back:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Front:
			return EBlockTexture::TuffBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffBrickSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Side:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Back:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Front:
			return EBlockTexture::TuffBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffBrickStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Side:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Back:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Front:
			return EBlockTexture::TuffBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffBrickStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Side:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Back:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Front:
			return EBlockTexture::TuffBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffBrickStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Bottom:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Side:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Back:
			return EBlockTexture::TuffBricks;
		case EBlockFace::Front:
			return EBlockTexture::TuffBricks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffBrickWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TuffBrickWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TuffBrickWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TuffBrickWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TuffBricks:
	{
		return EBlockTexture::TuffBricks;
	}
	case EBlockType::TuffSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Tuff;
		case EBlockFace::Bottom:
			return EBlockTexture::Tuff;
		case EBlockFace::Side:
			return EBlockTexture::Tuff;
		case EBlockFace::Back:
			return EBlockTexture::Tuff;
		case EBlockFace::Front:
			return EBlockTexture::Tuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Tuff;
		case EBlockFace::Bottom:
			return EBlockTexture::Tuff;
		case EBlockFace::Side:
			return EBlockTexture::Tuff;
		case EBlockFace::Back:
			return EBlockTexture::Tuff;
		case EBlockFace::Front:
			return EBlockTexture::Tuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Tuff;
		case EBlockFace::Bottom:
			return EBlockTexture::Tuff;
		case EBlockFace::Side:
			return EBlockTexture::Tuff;
		case EBlockFace::Back:
			return EBlockTexture::Tuff;
		case EBlockFace::Front:
			return EBlockTexture::Tuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Tuff;
		case EBlockFace::Bottom:
			return EBlockTexture::Tuff;
		case EBlockFace::Side:
			return EBlockTexture::Tuff;
		case EBlockFace::Back:
			return EBlockTexture::Tuff;
		case EBlockFace::Front:
			return EBlockTexture::Tuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::Tuff;
		case EBlockFace::Bottom:
			return EBlockTexture::Tuff;
		case EBlockFace::Side:
			return EBlockTexture::Tuff;
		case EBlockFace::Back:
			return EBlockTexture::Tuff;
		case EBlockFace::Front:
			return EBlockTexture::Tuff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::TuffWallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TuffWallPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TuffWallSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TuffWallSideTall:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TurtleEgg:
	{
		return EBlockTexture::TurtleEgg;
	}
	case EBlockType::TwistingVines:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TwistingVinesPlant:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::TwoDeadSeaPickles:
	{
		return EBlockTexture::SeaPickle;
	}
	case EBlockType::TwoSeaPickles:
	{
		return EBlockTexture::SeaPickle;
	}
	case EBlockType::TwoSlightlyCrackedTurtleEggs:
	{
		return EBlockTexture::TurtleEggSlightlyCracked;
	}
	case EBlockType::TwoTurtleEggs:
	{
		return EBlockTexture::TurtleEgg;
	}
	case EBlockType::TwoVeryCrackedTurtleEggs:
	{
		return EBlockTexture::TurtleEggVeryCracked;
	}
	case EBlockType::Vault:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::VaultTop;
		case EBlockFace::Bottom:
			return EBlockTexture::VaultBottom;
		case EBlockFace::Side:
			return EBlockTexture::VaultSideOff;
		case EBlockFace::Back:
			return EBlockTexture::VaultSideOff;
		case EBlockFace::Front:
			return EBlockTexture::VaultFrontOff;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VaultActive:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::VaultTop;
		case EBlockFace::Bottom:
			return EBlockTexture::VaultBottom;
		case EBlockFace::Side:
			return EBlockTexture::VaultSideOn;
		case EBlockFace::Back:
			return EBlockTexture::VaultSideOn;
		case EBlockFace::Front:
			return EBlockTexture::VaultFrontOn;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VaultActiveOminous:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::VaultTopOminous;
		case EBlockFace::Bottom:
			return EBlockTexture::VaultBottomOminous;
		case EBlockFace::Side:
			return EBlockTexture::VaultSideOnOminous;
		case EBlockFace::Back:
			return EBlockTexture::VaultSideOnOminous;
		case EBlockFace::Front:
			return EBlockTexture::VaultFrontOnOminous;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VaultEjectingReward:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::VaultTopEjecting;
		case EBlockFace::Bottom:
			return EBlockTexture::VaultBottom;
		case EBlockFace::Side:
			return EBlockTexture::VaultSideOn;
		case EBlockFace::Back:
			return EBlockTexture::VaultSideOn;
		case EBlockFace::Front:
			return EBlockTexture::VaultFrontEjecting;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VaultEjectingRewardOminous:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::VaultTopEjectingOminous;
		case EBlockFace::Bottom:
			return EBlockTexture::VaultBottomOminous;
		case EBlockFace::Side:
			return EBlockTexture::VaultSideOnOminous;
		case EBlockFace::Back:
			return EBlockTexture::VaultSideOnOminous;
		case EBlockFace::Front:
			return EBlockTexture::VaultFrontEjectingOminous;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VaultOminous:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::VaultTopOminous;
		case EBlockFace::Bottom:
			return EBlockTexture::VaultBottomOminous;
		case EBlockFace::Side:
			return EBlockTexture::VaultSideOffOminous;
		case EBlockFace::Back:
			return EBlockTexture::VaultSideOffOminous;
		case EBlockFace::Front:
			return EBlockTexture::VaultFrontOffOminous;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VaultUnlocking:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::VaultTop;
		case EBlockFace::Bottom:
			return EBlockTexture::VaultBottom;
		case EBlockFace::Side:
			return EBlockTexture::VaultSideOn;
		case EBlockFace::Back:
			return EBlockTexture::VaultSideOn;
		case EBlockFace::Front:
			return EBlockTexture::VaultFrontEjecting;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VaultUnlockingOminous:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::VaultTopOminous;
		case EBlockFace::Bottom:
			return EBlockTexture::VaultBottomOminous;
		case EBlockFace::Side:
			return EBlockTexture::VaultSideOnOminous;
		case EBlockFace::Back:
			return EBlockTexture::VaultSideOnOminous;
		case EBlockFace::Front:
			return EBlockTexture::VaultFrontEjectingOminous;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VerdantFroglight:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::VerdantFroglightSide;
		case EBlockFace::Back:
			return EBlockTexture::VerdantFroglightSide;
		case EBlockFace::Front:
			return EBlockTexture::VerdantFroglightSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VerdantFroglightHorizontal:
	{
		switch (face)
		{
		case EBlockFace::Side:
			return EBlockTexture::VerdantFroglightSide;
		case EBlockFace::Back:
			return EBlockTexture::VerdantFroglightSide;
		case EBlockFace::Front:
			return EBlockTexture::VerdantFroglightSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::VeryCrackedTurtleEgg:
	{
		return EBlockTexture::TurtleEggVeryCracked;
	}
	case EBlockType::Vine:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WallInventory:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WallTorch:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WarpedButton:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedButtonInventory:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedButtonPressed:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedFenceGate:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedFenceGateOpen:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedFenceGateWall:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedFenceGateWallOpen:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedFenceInventory:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedFencePost:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedFenceSide:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedFungus:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WarpedHangingSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WarpedHyphae:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WarpedNylium:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedNylium;
		case EBlockFace::Bottom:
			return EBlockTexture::Netherrack;
		case EBlockFace::Side:
			return EBlockTexture::WarpedNyliumSide;
		case EBlockFace::Back:
			return EBlockTexture::WarpedNyliumSide;
		case EBlockFace::Front:
			return EBlockTexture::WarpedNyliumSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedPlanks:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedPressurePlate:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedPressurePlateDown:
	{
		return EBlockTexture::WarpedPlanks;
	}
	case EBlockType::WarpedRoots:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WarpedSign:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WarpedSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Side:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Back:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Front:
			return EBlockTexture::WarpedPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Side:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Back:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Front:
			return EBlockTexture::WarpedPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Side:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Back:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Front:
			return EBlockTexture::WarpedPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Side:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Back:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Front:
			return EBlockTexture::WarpedPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Bottom:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Side:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Back:
			return EBlockTexture::WarpedPlanks;
		case EBlockFace::Front:
			return EBlockTexture::WarpedPlanks;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WarpedStem:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WarpedTrapdoorBottom:
	{
		return EBlockTexture::WarpedTrapdoor;
	}
	case EBlockType::WarpedTrapdoorOpen:
	{
		return EBlockTexture::WarpedTrapdoor;
	}
	case EBlockType::WarpedTrapdoorTop:
	{
		return EBlockTexture::WarpedTrapdoor;
	}
	case EBlockType::WarpedWartBlock:
	{
		return EBlockTexture::WarpedWartBlock;
	}
	case EBlockType::Water:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WaterCauldronFull:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WaterCauldronLevel1:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WaterCauldronLevel2:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CauldronTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CauldronBottom;
		case EBlockFace::Side:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Back:
			return EBlockTexture::CauldronSide;
		case EBlockFace::Front:
			return EBlockTexture::CauldronSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredChiseledCopper:
	{
		return EBlockTexture::WeatheredChiseledCopper;
	}
	case EBlockType::WeatheredCopper:
	{
		return EBlockTexture::WeatheredCopper;
	}
	case EBlockType::WeatheredCopperBarsCap:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperBarsCapAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperBarsPost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperBarsPostEnds:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperBarsSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperBarsSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperBulb:
	{
		return EBlockTexture::WeatheredCopperBulb;
	}
	case EBlockType::WeatheredCopperBulbLit:
	{
		return EBlockTexture::WeatheredCopperBulbLit;
	}
	case EBlockType::WeatheredCopperBulbLitPowered:
	{
		return EBlockTexture::WeatheredCopperBulbLitPowered;
	}
	case EBlockType::WeatheredCopperBulbPowered:
	{
		return EBlockTexture::WeatheredCopperBulbPowered;
	}
	case EBlockType::WeatheredCopperChain:
	{
		return EBlockTexture::WeatheredCopperChain;
	}
	case EBlockType::WeatheredCopperChest:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperDoorBottomLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCopperDoorBottomLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCopperDoorBottomRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCopperDoorBottomRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCopperDoorTopLeft:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCopperDoorTopLeftOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCopperDoorTopRight:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCopperDoorTopRightOpen:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCopperDoorTop;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCopperDoorBottom;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCopperGolemStatue:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperGrate:
	{
		return EBlockTexture::WeatheredCopperGrate;
	}
	case EBlockType::WeatheredCopperLantern:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperLanternHanging:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeatheredCopperTrapdoorBottom:
	{
		return EBlockTexture::WeatheredCopperTrapdoor;
	}
	case EBlockType::WeatheredCopperTrapdoorOpen:
	{
		return EBlockTexture::WeatheredCopperTrapdoor;
	}
	case EBlockType::WeatheredCopperTrapdoorTop:
	{
		return EBlockTexture::WeatheredCopperTrapdoor;
	}
	case EBlockType::WeatheredCutCopper:
	{
		return EBlockTexture::WeatheredCutCopper;
	}
	case EBlockType::WeatheredCutCopperSlab:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::WeatheredCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCutCopperSlabTop:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::WeatheredCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCutCopperStairs:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::WeatheredCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCutCopperStairsInner:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::WeatheredCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredCutCopperStairsOuter:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Bottom:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Side:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Back:
			return EBlockTexture::WeatheredCutCopper;
		case EBlockFace::Front:
			return EBlockTexture::WeatheredCutCopper;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WeatheredLightningRod:
	{
		return EBlockTexture::WeatheredLightningRod;
	}
	case EBlockType::WeepingVines:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WeepingVinesPlant:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WetSponge:
	{
		return EBlockTexture::WetSponge;
	}
	case EBlockType::WheatStage0:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WheatStage1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WheatStage2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WheatStage3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WheatStage4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WheatStage5:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WheatStage6:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WheatStage7:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WhiteCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::WhiteCandleFourCandles:
	{
		return EBlockTexture::WhiteCandle;
	}
	case EBlockType::WhiteCandleFourCandlesLit:
	{
		return EBlockTexture::WhiteCandleLit;
	}
	case EBlockType::WhiteCandleOneCandle:
	{
		return EBlockTexture::WhiteCandle;
	}
	case EBlockType::WhiteCandleOneCandleLit:
	{
		return EBlockTexture::WhiteCandleLit;
	}
	case EBlockType::WhiteCandleThreeCandles:
	{
		return EBlockTexture::WhiteCandle;
	}
	case EBlockType::WhiteCandleThreeCandlesLit:
	{
		return EBlockTexture::WhiteCandleLit;
	}
	case EBlockType::WhiteCandleTwoCandles:
	{
		return EBlockTexture::WhiteCandle;
	}
	case EBlockType::WhiteCandleTwoCandlesLit:
	{
		return EBlockTexture::WhiteCandleLit;
	}
	case EBlockType::WhiteCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteConcrete:
	{
		return EBlockTexture::WhiteConcrete;
	}
	case EBlockType::WhiteConcretePowder:
	{
		return EBlockTexture::WhiteConcretePowder;
	}
	case EBlockType::WhiteGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteStainedGlass:
	{
		return EBlockTexture::WhiteStainedGlass;
	}
	case EBlockType::WhiteStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteTerracotta:
	{
		return EBlockTexture::WhiteTerracotta;
	}
	case EBlockType::WhiteTulip:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WhiteWool:
	{
		return EBlockTexture::WhiteWool;
	}
	case EBlockType::Wildflowers1:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Wildflowers2:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Wildflowers3:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::Wildflowers4:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::WitherRose:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowCandleCake:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::YellowCandleCakeLit:
	{
		switch (face)
		{
		case EBlockFace::Top:
			return EBlockTexture::CakeTop;
		case EBlockFace::Bottom:
			return EBlockTexture::CakeBottom;
		case EBlockFace::Side:
			return EBlockTexture::CakeSide;
		case EBlockFace::Back:
			return EBlockTexture::CakeSide;
		case EBlockFace::Front:
			return EBlockTexture::CakeSide;
		default:
			return EBlockTexture::Invalid;
		}
	}
	case EBlockType::YellowCandleFourCandles:
	{
		return EBlockTexture::YellowCandle;
	}
	case EBlockType::YellowCandleFourCandlesLit:
	{
		return EBlockTexture::YellowCandleLit;
	}
	case EBlockType::YellowCandleOneCandle:
	{
		return EBlockTexture::YellowCandle;
	}
	case EBlockType::YellowCandleOneCandleLit:
	{
		return EBlockTexture::YellowCandleLit;
	}
	case EBlockType::YellowCandleThreeCandles:
	{
		return EBlockTexture::YellowCandle;
	}
	case EBlockType::YellowCandleThreeCandlesLit:
	{
		return EBlockTexture::YellowCandleLit;
	}
	case EBlockType::YellowCandleTwoCandles:
	{
		return EBlockTexture::YellowCandle;
	}
	case EBlockType::YellowCandleTwoCandlesLit:
	{
		return EBlockTexture::YellowCandleLit;
	}
	case EBlockType::YellowCarpet:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowConcrete:
	{
		return EBlockTexture::YellowConcrete;
	}
	case EBlockType::YellowConcretePowder:
	{
		return EBlockTexture::YellowConcretePowder;
	}
	case EBlockType::YellowGlazedTerracotta:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowShulkerBox:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowStainedGlass:
	{
		return EBlockTexture::YellowStainedGlass;
	}
	case EBlockType::YellowStainedGlassPaneNoside:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowStainedGlassPaneNosideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowStainedGlassPanePost:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowStainedGlassPaneSide:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowStainedGlassPaneSideAlt:
	{
		return EBlockTexture::Invalid;
	}
	case EBlockType::YellowTerracotta:
	{
		return EBlockTexture::YellowTerracotta;
	}
	case EBlockType::YellowWool:
	{
		return EBlockTexture::YellowWool;
	}
	default:
		return EBlockTexture::Invalid;
	}
}

EBlockTexture GetBlockOverlayTexture(EBlockType block, EBlockFace face)
{
	switch (block)
	{
	case EBlockType::GrassBlock:
	{
		if (face != EBlockFace::Top && face != EBlockFace::Bottom)
		{
			return EBlockTexture::GrassBlockSideOverlay;
		}
		else
		{
			return EBlockTexture::Transparent;
		}
	}
	case EBlockType::RedstoneDustDot:
	{
		if (face != EBlockFace::Top && face != EBlockFace::Bottom)
		{
			return EBlockTexture::RedstoneDustOverlay;
		}
		else
		{
			return EBlockTexture::Transparent;
		}
	}
	case EBlockType::RedstoneDustSide:
	{
		if (face != EBlockFace::Top && face != EBlockFace::Bottom)
		{
			return EBlockTexture::RedstoneDustOverlay;
		}
		else
		{
			return EBlockTexture::Transparent;
		}
	}
	case EBlockType::RedstoneDustSideAlt:
	{
		if (face != EBlockFace::Top && face != EBlockFace::Bottom)
		{
			return EBlockTexture::RedstoneDustOverlay;
		}
		else
		{
			return EBlockTexture::Transparent;
		}
	}
	case EBlockType::RedstoneDustUp:
	{
		if (face != EBlockFace::Top && face != EBlockFace::Bottom)
		{
			return EBlockTexture::RedstoneDustOverlay;
		}
		else
		{
			return EBlockTexture::Transparent;
		}
	}
	default:
		return EBlockTexture::Transparent;
	}
}
