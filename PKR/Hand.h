#pragma once
#include <vector>
#include "Card.h"
class Hand
{
private:
	std::vector<Card> m_cardArr;
	const static char* HANDRANK_STRINGS[];

public:
	Hand(const std::vector<Card>& p_cards);
	Hand();
	~Hand();

	enum HandRank : uint { HIGHEST_CARD = 0, PAIR = 1, STRAIGHT = 2, FLUSH = 3, TOAK = 4, STRAIGHTFLUSH = 5};

	int CompareHand(const Hand& p_otherHand) const;

	static Hand::HandRank RankHand(const Hand& p_Hand);
	static Card::Face HighestFaceCard(const Hand& p_Hand);
	static Card::Face HighestFacePair(const Hand& p_Hand, const uint);
	static bool IsFlush(const Hand& p_Hand);
	static bool IsStraight(const Hand& p_Hand);
	static bool IsStraightFlush(const Hand& p_Hand);
	static bool HasPair(const Hand& p_Hand, const uint);

	static const char* RankToString(const Hand::HandRank&);
};

