#include "Card.h"

Card::Card(Suit suit, Face face)
{
	m_id = (suit * SUIT_OFFSET) + face;
}

Card::Card(std::string p_cardID)
{
	//TODO: Do some string parsing and convert it to an id
	m_id = 0;
}

Card::Card(const Card& p_otherCard)
{
	m_id = p_otherCard.m_id;
}

Card::~Card(){}

Card Card::operator=(const Card& p_otherCard)
{
	//Done for today, resume here. Need to write suit/face funcs from a card's m_id. % and / for suit/face.
	return Card("");
}

bool Card::operator==(const Card& p_otherCard)
{
	return p_otherCard.m_id == m_id;
}

bool Card::operator<(const Card& p_otherCard)
{
	return p_otherCard.m_id < m_id;
}

bool Card::operator>(const Card& p_otherCard)
{
	return p_otherCard.m_id > m_id;
}

Card::Suit Card::GetSuit(const Card& p_otherCard)
{
	Card::Suit suit = (Card::Suit)(p_otherCard.m_id / SUIT_OFFSET);
	return suit;
}

Card::Face Card::GetFace(const Card& p_otherCard) 
{
	Card::Face face = (Card::Face)(p_otherCard.m_id % SUIT_OFFSET);
	return face;
}
