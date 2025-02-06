#include "card.h"
#include <string>
#include <iostream>

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
					   
					   
Card::Card()
{
	suitVal_ = 0;
	faceVal_ = 0;
	
}


Card::Card(int face, int suit)
{
	faceVal_ = face;
	suitVal_ = suit;
}

Card::~Card()
{
	
}

std::string Card::getSuit()
{
	return SUIT[suitVal_];
}

std::string Card::getFace()
{
	return FACE[faceVal_];
}

std::string Card::print()
{
	std::string output = FACE[faceVal_] + " of " + SUIT[suitVal_];
	return output;
}

void Card::initialize(int suit, int face)
{
	faceVal_ = face;
	suitVal_ = suit;
} 



