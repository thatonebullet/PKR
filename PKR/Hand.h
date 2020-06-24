#pragma once
#include <vector>
#include "Card.h"
class Hand
{
private:
	std::vector<Card> m_cardArr;

public:
	Hand(std::vector<Card>& p_cards);
	Hand();
	~Hand();

	int CompareHand(const Hand& p_otherHand);
	//bool operator==(const Hand&);

};

