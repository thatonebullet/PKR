#pragma once
#include <vector>
#include "Card.h"
class Hand
{
private:
	std::vector<Card> m_cardArr;

public:
	Hand(const std::vector<Card>& p_cards);
	Hand();
	~Hand();

	int CompareHand(const Hand& p_otherHand) const;
	static int RankHand(const Hand& p_Hand);
	static Card::Face HighestFaceCard(const Hand& p_Hand);
	static Card::Face HighestFacePair(const Hand& p_Hand);
	static bool IsFlush(const Hand& p_Hand);
	static bool IsStraight(const Hand& p_Hand);
	static bool IsStraightFlush(const Hand& p_Hand);
	static bool IsTOAK(const Hand& p_Hand);
	static bool HasPair(const Hand& p_Hand);
};

