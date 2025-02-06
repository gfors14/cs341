#include "card.h"
#include <string>
#include <iostream>
#include <stdlib.h> 


Deck::Deck() : numCards_(0)
{
	
	
}


Deck::Deck(int size) : numCards_(0)
{
	size_ = size;
	deck_ = new Card[size_];

}





Deck::~Deck()
{
	delete [] deck_;
	
	
}










bool Deck::isEmpty();
{
	if(numCards_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}



int Deck::getNumCards();
{
	return numCards_;
}



void Deck::displayCard(int i);
{
	std::cout << deck_[i].print() << std::endl;
}



bool Deck::addCard(Card c);
{
	if (numCards_ < 52)
	{
		deck_[numCards_] = c;
		numCards_++;	
		return true;
	}
	else
	{
		return false;
	}
}


void Deck::shuffle();
{
	for(int x=0; x<3; x++)
	{
		for(int i=0; i<numCards_; i++)
		{
			int j = (rand() % (numCards_-1)) + 1;
			Card temp;
			temp = deck_[j];
			deck_[j] = deck_[i];
			deck_[i] = temp;
		}
	}
}







Card Deck::dealCard()
{
	Card topCard;
	topCard = deck_[numCards_-1];
	numCards_--;
	return topCard;
}


void Deck::printDeck()
{
	for (int i=0; i<numCards_; i++)
	{
		std::cout << deck_[i].print() << std::endl;
	}
}