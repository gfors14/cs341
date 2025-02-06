#include "card.h"
#include <string>
#include <iostream>
#include <fstream>
#include "standardDeck.h"

int main()
{
	StandardDeck deck;
	StandardDeck deck1;
	//int count = 0;
/*
	for(int i=1; i<5; i++)
	{
		for(int n=1; n<14; n++)
		{

			Card card1 = Card(n, i);
			//phase 1 shit idk if even need anymore but just keep in case
			//deck[count] = card1;
			//count++;
			//std::cout << card1.print() << std::endl;
		}

	} */
	//phase 2 shit
	deck.initializeDeck();
	int temp = 0;
	temp = deck.isEmpty();
	std::cout << temp << std::endl;
	deck.displayCard(15);
	std::cout << deck.getNumCards() << std::endl;;
	deck.printDeck();
	
	//addcard 
	//Card card2 = Card(3, 2);
	//deck.addCard(card2);
	std::cout << "NEWNEWNEWNEWNEWNNEW" << std::endl;
	deck.shuffle();
	deck.printDeck();
	std::cout << "NEWNEWNEWNEWNEWNNEW\n" << std::endl;
	deck1.printDeck();
	//deck1.initializeDeck();
	deck1.mergeDecks(deck, true);
	
	deck1.printDeck();
	
	//deck.printDeck();
//	deck2.initalizeDeck();
	








}