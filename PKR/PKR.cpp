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
    cards1.push_back(HEART_A);
    cards1.push_back(HEART_2);
    cards1.push_back(HEART_3);
    cards1.push_back(HEART_4);
    cards1.push_back(HEART_5);

    std::vector<Card> cards2;
    cards1.push_back(DIAMOND_A);
    cards1.push_back(DIAMOND_2);
    cards1.push_back(DIAMOND_3);
    cards1.push_back(DIAMOND_4);
    cards1.push_back(DIAMOND_5);

    //Create our two test hands
    const Hand hand1 = Hand(cards1);
    const Hand hand2 = Hand(cards2);

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
