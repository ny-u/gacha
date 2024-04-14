/**
* @file: Gacha.cpp
* @author: weijie
* @date: 14 Apr 2024
* @brief: gacha code
*/

#include "pch.h"
#include "Gacha.h"

GachaPrize GachaSlot::Pull()
{
	int roll{ m_intDistrib(m_gen)};

	if (roll == 100) return GachaPrize::RED_PIXEL;
	else if (roll <= 99 && roll >= 80)	return GachaPrize::BLUE_PIXEL;
	else if (roll <= 79 && roll >= 20)	return GachaPrize::GREEN_PIXEL;
	return GachaPrize::POOP_PIXEL;
}

std::array<GachaPrize, 10> GachaSlot::Pull_10()
{
	std::array<GachaPrize, 10> roll{};
	for (GachaPrize i : roll)
		i = Pull();

	return roll;
}

void GachaSlot::ConsolePrint(GachaPrize _prize)
{
	switch (_prize)
	{
	case(GachaPrize::RED_PIXEL):
		printf("\033[1;31mRed Pixel!!!!!\n");
		break;
	case(GachaPrize::BLUE_PIXEL):
		printf("\033[1;34mBlue Pixel!!!!\n");
		break;
	case(GachaPrize::GREEN_PIXEL):
		printf("\033[1;32mGreen Pixel!!!\n");
		break;
	case(GachaPrize::POOP_PIXEL):
		printf("\033[0;33mPoop!!\n");
		break;
	default:
		break;
	}
}

void GachaSlot::DrawPrize(GachaPrize _prize, TTF_Font* _font)
{
	Vec3<float> centre{ PK_WINDOW_WIDTH / 2, PK_WINDOW_HEIGHT / 2, 0 };



	switch (_prize)
	{
	case(GachaPrize::RED_PIXEL):
		PonkoEnv::TextureManager::Get().TextDraw("RED", _font, PK_COLOR_RED, Vec3<float>(360, 300, 0), Vec3<float>(140, 55, 0));
		break;
	case(GachaPrize::BLUE_PIXEL):
		PonkoEnv::TextureManager::Get().TextDraw("GREEN", _font, PK_COLOR_GREEN, Vec3<float>(360, 300, 0), Vec3<float>(140, 55, 0));
		break;
	case(GachaPrize::GREEN_PIXEL):
		PonkoEnv::TextureManager::Get().TextDraw("BLUE", _font, PK_COLOR_BLUE, Vec3<float>(360, 300, 0), Vec3<float>(140, 55, 0));
		break;
	case(GachaPrize::POOP_PIXEL):
		PonkoEnv::TextureManager::Get().TextDraw("POOP!", _font, PK_COLOR_POOP, Vec3<float>(360, 300, 0), Vec3<float>(140, 55, 0));
		break;
	default:
		break;
	}
}

std::string GachaSlot::PrizeToString(GachaPrize _prize)
{
	std::string str{};

	switch (_prize)
	{
	case(GachaPrize::RED_PIXEL):
		str = "RED";
		break;
	case(GachaPrize::BLUE_PIXEL):
		str = "BLUE";
		break;
	case(GachaPrize::GREEN_PIXEL):
		str = "GREEN";
		break;
	case(GachaPrize::POOP_PIXEL):
		str = "POOP";
		break;
	default:
		break;
	}

	return str;
}
