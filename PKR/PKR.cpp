// PKR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include "Card.h"
#include "Hand.h"



int main()
{

    std::cout << "Welcome to PKR!\n";

    //Check out Card.h for all the predefined card definitions to make testing easier :)

    //Make your cards here
    std::vector<Card> cards1;
    cards1.push_back(HEART_7);
    cards1.push_back(CLUBS_6);
    cards1.push_back(DIAMOND_6);
    cards1.push_back(SPADES_7);
    cards1.push_back(HEART_5);

    std::vector<Card> cards2;
    cards2.push_back(DIAMOND_A);
    cards2.push_back(CLUBS_6);
    cards2.push_back(DIAMOND_3);
    cards2.push_back(DIAMOND_4);
    cards2.push_back(DIAMOND_5);

    //Create our two test hands
    const Hand hand1 = Hand(cards1);
    const Hand hand2 = Hand(cards2);

    //Test Highest Card Function
    Card::Face highestFaceCard = Hand::HighestFaceCard(hand1);
    std::cout << "Highest Face Card: " << Card::FaceToString(highestFaceCard) << "\n";

    //Test if Hand is Flush
    bool isFlush = Hand::IsFlush(hand1);
    std::cout << "Hand has flush: " << isFlush << "\n";

    //Test if Hand is Straight
    bool isStraight = Hand::IsStraight(hand1);
    std::cout << "Hand has straight: " << isStraight << "\n";

    //Test if Hand is StraightFlush
    bool isStraightFlush = Hand::IsStraightFlush(hand2);
    std::cout << "Hand has straight flush: " << isStraightFlush << "\n";

    //Test if Hand is TOAK
    bool isTOAK = Hand::HasPair(hand1, 3);
    std::cout << "Hand has TOAK: " << isTOAK << "\n";

    //Test if Hand has pair
    bool hasPair = Hand::HasPair(hand1, 2);
    std::cout << "Hand has pair: " << hasPair << "\n";

    //Get Highest pair, defaults to first card if no pair
    Card::Face highestFacePair = Hand::HighestFacePair(hand1, 2);
    std::cout << "Highest face of pair: " << Card::FaceToString(highestFacePair) << "\n";

    //Rank both hands
    Hand::HandRank pair1Rank = Hand::RankHand(hand1);
    std::cout << "Rank of hand 1: " << Hand::RankToString(pair1Rank) << "\n";

    Hand::HandRank pair2Rank = Hand::RankHand(hand2);
    std::cout << "Rank of hand 2: " << Hand::RankToString(pair2Rank) << "\n";


    //Test Final Hand Comparisons
    int result = hand1.CompareHand(hand2);
    if (result < 0)
    {
        std::cout << "Hand 1 lost.\n";
    }
    else if (result == 0)
    {
        std::cout << "Hands are equal\n";
    }
    else
    {
        std::cout << "Hand 1 won!\n";
    }

    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
