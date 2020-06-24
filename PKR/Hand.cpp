#include "Hand.h"

Hand::Hand(std::vector<Card>& p_cards)
{
	if (!p_cards.empty())
	{
		//Simply assigning the new vector to old one copies the vector. 
		m_cardArr = p_cards;
	}
}

Hand::Hand()
{
}

Hand::~Hand()
{
	m_cardArr.clear();
}

int Hand::CompareHand(const Hand& p_otherHand)
{
	return 0;
}


