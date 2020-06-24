#include "Hand.h"

Hand::Hand(const std::vector<Card>& p_cards)
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

int Hand::CompareHand(const Hand& p_otherHand) const
{
	return 0;
}

int Hand::RankHand(const Hand& p_Hand)
{
	return 0;
}

Card::Face Hand::HighestFaceCard (const Hand& p_Hand)
{
	Card::Face highest_face = Card::Face::ACE;

	for (int i = 0; i < p_Hand.m_cardArr.size(); i++)
	{
		Card::Face current_face = Card::GetFace(p_Hand.m_cardArr[i]);
		//Because we start with an Ace as highest card, the actual highest card can only be lower. 
		if (highest_face < current_face)
		{
			highest_face = current_face;
		}
	}

	return highest_face;
}

Card::Face Hand::HighestFacePair (const Hand& p_Hand)
{
	Card::Face highest_face = Card::Face::ACE;
	return highest_face;
}

bool Hand::IsFlush(const Hand& p_Hand)
{
	return false;
}

bool Hand::IsStraight(const Hand& p_Hand)
{
	return false;
}

bool Hand::IsStraightFlush(const Hand& p_Hand)
{
	return false;
}

bool Hand::IsTOAK(const Hand& p_Hand)
{
	return false;
}

bool Hand::HasPair(const Hand& p_Hand)
{
	return false;
}



