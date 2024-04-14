/**
* @file: Gacha.h
* @author: weijie
* @date: 14 Apr 2024
* @brief: gacha code
*/

#ifndef GACHA_H
#define GACHA_H

#include <random>
#include <array>

enum class GachaPrize
{
	NO_PIXEL = 0,
	RED_PIXEL,
	BLUE_PIXEL,
	GREEN_PIXEL,
	POOP_PIXEL
};

class GachaSlot
{
public:
	GachaSlot() : m_rd{}, m_gen{ m_rd() }, m_intDistrib{ 1, 100 } {};

	GachaPrize Pull();
	std::array<GachaPrize, 10> Pull_10();
	void ConsolePrint(GachaPrize _prize);
	void DrawPrize(GachaPrize _prize, TTF_Font* _font);
	std::string PrizeToString(GachaPrize _prize);

	size_t counter{}; // lazi to put in private for now

private:
	std::random_device m_rd{};
	std::mt19937_64 m_gen{};
	std::uniform_int_distribution<int> m_intDistrib{ };
};

#endif // !GACHA_H
