#include "Hand.h"
#include <algorithm>    // std::sort

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

const char* Hand::HANDRANK_STRINGS[] =
{
	"HIGHEST_CARD",
	"PAIR",
	"STRAIGHT",
	"FLUSH",
	"TOAK",
	"STRAIGHT FLUSH"
};

//-1 means worse hand, 1 means better hand, 0 means tie
int Hand::CompareHand(const Hand& p_otherHand) const
{
	Hand::HandRank my_rank = RankHand(*this);
	Hand::HandRank other_rank = RankHand(p_otherHand);
	
	if (my_rank < other_rank)
	{
		return -1;
	}
	else if(my_rank > other_rank)
	{
		return 1;
	}
	//Same ranks, so some additional logic needed to finalize winner
	else
	{
		//Check if we have pairs
		if (my_rank == Hand::HandRank::TOAK || my_rank == Hand::HandRank::PAIR)
		{
			
			uint pair_type = 2;
			if (my_rank == Hand::HandRank::TOAK)
			{
				uint pair_type = 3;
			}

			auto my_highest_card = Hand::HighestFacePair(*this, pair_type);
			auto other_highest_card = Hand::HighestFacePair(p_otherHand, pair_type);
			if (my_highest_card < other_highest_card)
			{
				return -1;
			}
			else if (my_highest_card > other_highest_card)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		//Default to highest card in all other ties
		else
		{
			auto my_highest_card = Hand::HighestFaceCard(*this);
			auto other_highest_card = Hand::HighestFaceCard(p_otherHand);
			if (my_highest_card < other_highest_card)
			{
				return -1;
			}
			else if (my_highest_card > other_highest_card)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

Hand::HandRank Hand::RankHand(const Hand& p_Hand)
{
	if(Hand::IsStraightFlush(p_Hand))
	{ 
		return Hand::HandRank::STRAIGHTFLUSH;
	}
	else if (Hand::HasPair(p_Hand, 3))
	{
		return Hand::HandRank::TOAK;
	}
	else if (Hand::IsFlush(p_Hand))
	{
		return Hand::HandRank::FLUSH;
	}
	else if (Hand::IsStraight(p_Hand))
	{
		return Hand::HandRank::STRAIGHT;
	}
	else if (Hand::HasPair(p_Hand, 2))
	{
		return Hand::HandRank::PAIR;
	}
	else
	{
		return Hand::HandRank::HIGHEST_CARD;
	}
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

//If there is no pair this will just default to the first card
Card::Face Hand::HighestFacePair (const Hand& p_Hand, const uint p_pairSize)
{
	Card::Face highest_face;
	for (int i = 0; i < p_Hand.m_cardArr.size(); i++)
	{
		uint pair_counter = 0;
		
		Card c = p_Hand.m_cardArr[i];
		Card::Face c_face = Card::GetFace(c);
		
		if (i == 0)
		{
			highest_face = c_face;
		}

		for (int j = i + 1; j < p_Hand.m_cardArr.size(); j++)
		{
			Card matched_card = p_Hand.m_cardArr[j];
			Card::Face matched_face = Card::GetFace(matched_card);
			if (c_face == matched_face)
			{
				pair_counter++;
			}
		}

		if (pair_counter == p_pairSize && c_face > highest_face)
		{
			highest_face = c_face;
		}
		else
		{
			pair_counter = 0;
		}

	}

	return highest_face;
}

bool Hand::IsFlush(const Hand& p_Hand)
{
	bool isFlush = true;
	Card::Suit trackedSuit;
	for (int i = 0; i < p_Hand.m_cardArr.size(); i++)
	{
		Card c = p_Hand.m_cardArr[i];
		if (i == 0)
		{
			trackedSuit = Card::GetSuit(c);
		}
		else
		{
			if (trackedSuit != Card::GetSuit(c))
			{
				return false;
			}
		}
	}
	return isFlush;
}


//Apparently looping straights is not a thing, and i thought it was at first...
//So this just checking them in order with no looping
bool Hand::IsStraight(const Hand& p_Hand)
{
	bool isStraight = true;
	
	std::vector<Card::Face> face_vector;

	for (int i = 0; i < p_Hand.m_cardArr.size(); i++)
	{
		Card c = p_Hand.m_cardArr[i];
		Card::Face c_face = Card::GetFace(c);
		face_vector.push_back(c_face);
	}

	std::sort(face_vector.begin(), face_vector.begin() + face_vector.size());
	Card::Face current_face;
	for (int i = 0; i < face_vector.size(); i++)
	{
		
		if (i == 0)
		{
			current_face = face_vector[i];
		}
		else
		{
			if (!Card::AreFacesConsecutive(current_face, face_vector[i]))
			{
				isStraight = false;
				break;
			}
			else
			{
				current_face = face_vector[i];
			}
		}

		
	}

	if (isStraight == false)
	{
		//Final check for special case Ace low
		std::vector<Card::Face> aceLow = { Card::Face::TWO, Card::Face::THREE, Card::Face::FOUR, Card::Face::FIVE, Card::Face::ACE };
		isStraight = aceLow == face_vector;
	}

	return isStraight;
}

bool Hand::IsStraightFlush(const Hand& p_Hand)
{
	return IsStraight(p_Hand) && IsFlush(p_Hand);
}

bool Hand::HasPair(const Hand& p_Hand, const uint p_pairSize)
{
	bool isPair = false;

	uint pair_counter = 0;
	for (int i = 0; i < p_Hand.m_cardArr.size(); i++)
	{
		Card c = p_Hand.m_cardArr[i];
		Card::Face c_face = Card::GetFace(c);
		pair_counter++;

		for (int j = i + 1; j < p_Hand.m_cardArr.size(); j++)
		{
			Card matched_card = p_Hand.m_cardArr[j];
			Card::Face matched_face = Card::GetFace(matched_card);
			if (c_face == matched_face)
			{
				pair_counter++;
			}
		}

		if (pair_counter == p_pairSize)
		{
			return true;
		}
		else
		{
			pair_counter = 0;
		}

	}
	return isPair;
}

const char* Hand::RankToString(const Hand::HandRank& p_HandRank)
{
	return HANDRANK_STRINGS[p_HandRank];
}



