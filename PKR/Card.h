#pragma once
#include <string>
using uint = unsigned int;





struct Card
{
private:
	uint m_id;
	//BECAUSE IN PKR there's only A + 2-9, each suit will take up 9 spaces
	//These constants represent the starting padding where each suit lives
	//Ace will start at 0 offset.
	//HEARTS are 0-8
	//DIAMOND are 9-16
	//and so on...
	static const uint SUIT_OFFSET = 9;
	
public:
	enum Suit : uint { HEARTS = 0, DIAMONDS = 1, CLUBS = 2, SPADES = 3 };
	enum Face : uint { ACE = 0, TWO = 1, THREE = 2, FOUR = 3, FIVE = 4, SIX = 5, SEVEN = 6, EIGHT = 7, NINE = 8 };
	Card(Suit suit, Face face);
	Card(std::string p_cardID);
	Card(const Card&);
	~Card();

	Card operator=(const Card&);
	bool operator==(const Card&);
	bool operator<(const Card&);
	bool operator>(const Card&);

	static Card::Face GetFace(const Card&);
	static Card::Suit GetSuit(const Card&);

};

//Lets stick the preprossesor garbage below:
#define HEART_A Card(Card::Suit::HEARTS, Card::Face::ACE)
#define HEART_2 Card(Card::Suit::HEARTS, Card::Face::TWO)
#define HEART_3 Card(Card::Suit::HEARTS, Card::Face::THREE)
#define HEART_4 Card(Card::Suit::HEARTS, Card::Face::FOUR)
#define HEART_5 Card(Card::Suit::HEARTS, Card::Face::FIVE)
#define HEART_6 Card(Card::Suit::HEARTS, Card::Face::SIX)
#define HEART_7 Card(Card::Suit::HEARTS, Card::Face::SEVEN)
#define HEART_8 Card(Card::Suit::HEARTS, Card::Face::EIGHT)
#define HEART_9 Card(Card::Suit::HEARTS, Card::Face::NINE)

#define DIAMOND_A Card(Card::Suit::DIAMONDS, Card::Face::ACE)
#define DIAMOND_2 Card(Card::Suit::DIAMONDS, Card::Face::TWO)
#define DIAMOND_3 Card(Card::Suit::DIAMONDS, Card::Face::THREE)
#define DIAMOND_4 Card(Card::Suit::DIAMONDS, Card::Face::FOUR)
#define DIAMOND_5 Card(Card::Suit::DIAMONDS, Card::Face::FIVE)
#define DIAMOND_6 Card(Card::Suit::DIAMONDS, Card::Face::SIX)
#define DIAMOND_7 Card(Card::Suit::DIAMONDS, Card::Face::SEVEN)
#define DIAMOND_8 Card(Card::Suit::DIAMONDS, Card::Face::EIGHT)
#define DIAMOND_9 Card(Card::Suit::DIAMONDS, Card::Face::NINE)

#define CLUBS_A Card(Card::Suit::CLUBS, Card::Face::ACE)
#define CLUBS_2 Card(Card::Suit::CLUBS, Card::Face::TWO)
#define CLUBS_3 Card(Card::Suit::CLUBS, Card::Face::THREE)
#define CLUBS_4 Card(Card::Suit::CLUBS, Card::Face::FOUR)
#define CLUBS_5 Card(Card::Suit::CLUBS, Card::Face::FIVE)
#define CLUBS_6 Card(Card::Suit::CLUBS, Card::Face::SIX)
#define CLUBS_7 Card(Card::Suit::CLUBS, Card::Face::SEVEN)
#define CLUBS_8 Card(Card::Suit::CLUBS, Card::Face::EIGHT)
#define CLUBS_9 Card(Card::Suit::CLUBS, Card::Face::NINE)

#define SPADES_A Card(Card::Suit::SPADES, Card::Face::ACE)
#define SPADES_2 Card(Card::Suit::SPADES, Card::Face::TWO)
#define SPADES_3 Card(Card::Suit::SPADES, Card::Face::THREE)
#define SPADES_4 Card(Card::Suit::SPADES, Card::Face::FOUR)
#define SPADES_5 Card(Card::Suit::SPADES, Card::Face::FIVE)
#define SPADES_6 Card(Card::Suit::SPADES, Card::Face::SIX)
#define SPADES_7 Card(Card::Suit::SPADES, Card::Face::SEVEN)
#define SPADES_8 Card(Card::Suit::SPADES, Card::Face::EIGHT)
#define SPADES_9 Card(Card::Suit::SPADES, Card::Face::NINE)
