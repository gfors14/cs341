#ifdef DECK_H
#define DECK_H

class Deck
{
	public:
	int numCards_; // Stores the number of Cards currently in the deck.
	
	/// Default constructor.
	Deck();
	
	Deck(int size);
	
	/// Default destructor.
	~Deck();
	
	virtual void initializeDeck() = 0;
	
	/**
		* Returns True/False (1/0) whether or not the Deck is empty.
		*
		* @return          Boolean
		*/ 
	bool isEmpty();
	/**
		* Returns the number of cards remaining in the deck.
		*
		* @return          Integer value
		*/ 
	int getNumCards();
	/**
		* Displays the i'th card in the Deck.
		*
	* @param[in]      Index
		*/
	void displayCard(int i);
	

	/**
		* Prints the contents of the Deck. This method should call the 
	* print() method on each Card.
		*/
		
	bool addCard(Card c);
	// this method will return true if a card c can be added to the end of the deck, otherwise it will return false
	void shuffle();
	//using random sort perform at least 3x the number of cards in the deck swaps

	//this method takes the cards from an input standarddeck and merges them with the current standard deck. the bool paramater then indicates if we want 
	//to shuffle or not, with a default of false. the output in this case should  return true on successful addition.
	Card dealCard();
	void printDeck();
	protected: 
	Card * deck_; // Pointer to record the location of the array of 
	//Cards in memory.
	
};
#endif


#include "card.h"
#include <string>
#include <iostream>
#include <stdlib.h> 
