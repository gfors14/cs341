
#include "standardDeck.h"


StandardDeck::StandardDeck() : StandardDeck(sizeOfDeck)
{
	
	
}

StandardDeck::StandardDeck(int size) : Deck(size)
{

}

StandardDeck::~StandardDeck()
{
	
}
/*
bool StandardDeck::isEmpty()
{
	if(numCards_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	

} */
/*
int StandardDeck::getNumCards()
{
	return numCards_;
	 */
}
/*
void StandardDeck::displayCard(int i)
{
	std::cout << deck_[i].print() << std::endl;
} */
/*
void StandardDeck::printDeck()
{
	for (int i=0; i<numCards_; i++)
	{
		std::cout << deck_[i].print() << std::endl;
	}
	
} */

void StandardDeck::initializeDeck()
{
	int count = 0;
	for(int i=1; i<5; i++)
	{
		for(int n=1; n<14; n++)
		{
			Card card1 = Card(n, i);
			deck_[count] = card1;
			count++;
			numCards_++;
		}
	}
	
}
/*
bool StandardDeck::addCard(Card c)
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
} */

/*
void StandardDeck::shuffle()
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
} */

bool StandardDeck::mergeDecks(StandardDeck & newdeck, bool shuffle)
{
	if(numCards_ < 52)
	{
		int mergeNumber(0);
		mergeNumber = 52 - numCards_;
		
		if(mergeNumber > newdeck.getNumCards())
		{
			mergeNumber = newdeck.getNumCards();
		}
		else
		{
			
		}
		
		for(int i=0;i<mergeNumber; i++)
		{
		//	std::cout << "test1" << std::endl;
			deck_[numCards_+i] = newdeck.deck_[i];
		}
		
		numCards_ += mergeNumber+1;
		newdeck.numCards_ = 0;
		
		if(shuffle)
		{
			this->shuffle();
		}
		else
		{
			
		}
		return true;
	}
	return false;
	
} 
								
/*bool StandardDeck::mergeDecks(StandardDeck & poop, bool shuf)
{
	int mergeNum = 0;
	//mergeNum = D
	//int mergeNum = 0; 
	//mergeNum = deck.getNumCards();
	//poop.numCards_;
	mergeNum = 52 - numCards_;
	for(int i=0; i<mergeNum; i++)
	{
		//if
		//if else 52 - numCards_ and use that as the for loop , if <0 then we can merge the decks. else, return false. 
		//else
			
			Card temp1;
			temp1 = poop.deck_[i];
			addCard(temp1);
			
	}
	if(shuf==true)
	{
		shuffle();
	}
	else
	{
		
	}
	
	return true;
	//return true if the entire deck can be merged
} */
/*
Card StandardDeck::dealCard()
{
	
	Card topCard;
	topCard = deck_[numCards_-1];
	numCards_--;
	return topCard;
} */


