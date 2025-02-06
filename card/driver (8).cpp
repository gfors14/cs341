#include "card.h"
#include <string>
#include <iostream>
#include <fstream>
#include "standardDeck.h"

int main()
{
	srand(time(0));
	
	double score1 = 0;
	double score2 = 0;

	
	int player1Win = 0;
	int player2Win = 0;

	for(int i=0; i<50; i++)
	{
	Card card1;
	Card card2;
	Card card3;
	StandardDeck deck;
	deck.initializeDeck();
	StandardDeck player1;
	StandardDeck player2;
	deck.shuffle();
	
	//deck.printDeck();
	//std::cout << "PRINT DECK DONE....  \n\n" << std::endl;
	for(int i=0;i<26;i++)
	{
		card1 = deck.dealCard();
		player1.addCard(card1);
		card1 = deck.dealCard();
		player2.addCard(card1);
	}
	player1.shuffle();
	player2.shuffle();
		
		
	while(player1.getNumCards() > 0 && player2.getNumCards() > 0)
	{
		card1 = player1.dealCard();
		//std::cout << "test2" << std::endl;
		//std::cout << player2.getNumCards() << std::endl;
		
		if(card1.getFace() == card2.getFace())
		{
			player1.mergeDecks(deck, true);
		//	player1.shuffle();
			continue;
		}
		else
		{
			deck.addCard(card1);
		}
		card2 = player2.dealCard();
		
		if(card1.getFace() == card2.getFace())
		{
			player2.mergeDecks(deck, true);
		//	player2.shuffle();
			if(player1.getNumCards() > 0)
			{
				card2 = player2.dealCard();
				deck.addCard(card2);
			}
			else
			{
				
			}
		}
		else
		{
			deck.addCard(card2);
		}
		
		
	}
	if(player1.getNumCards() == 0)
	{
	
		player2Win = player2Win + 1;
		score2 = score2 + player2.getNumCards();
		//deck.mergeDecks(player2, true);
	}
	else
	{

		player1Win = player1Win + 1;
		score1 = score1 + player1.getNumCards();
	//	deck.mergeDecks(player1, true);
	}
	//delete[] player2;
	//delete[] player1;
	//delete[] deck;
	//std::cout << "test" << std::endl;
	
	}
	
	
	score1 = score1 / player1Win;
	score2 = score2 / player2Win;
	
	if(player1Win > player2Win)
	{
		std::cout << "Player 1 was the champion with " << player1Win << " wins!" << std::endl;
	}
	else if(player1Win < player2Win)
	{
		std::cout << "Player 2 was the champion with " << player2Win << " wins!" << std::endl;
	}
	else
	{
		std::cout << "It was a tie!" << std::endl;
	}

	std::cout << "Player 1 average score: " << score1 << std::endl;
	std::cout << "Player 2 average score: " << score2 << std::endl;


	/*player1.printDeck();
	std::cout << "player 1 deck\n" << std::endl;
	player2.printDeck();
	std::cout << "player 2 deck\n" << std::endl;
	deck.printDeck(); */
	
	//	std::cout << "PRINT DECK DONE.2...  \n\n" << std::endl;
	//card1 = deck.dealCard();
	//player2.addCard(card1);
	//
	//player1.printDeck();
//	std::cout << "PLAYER 1 DONE... \n" << std::endl;
	//player2.printDeck();


	//dealCard(deck);
	
	
	//StandardDeck deck;
	//StandardDeck deck1;
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
	/*deck.initializeDeck();
	int temp = 0;
	temp = deck.isEmpty();
	std::cout << temp << std::endl;
	deck.displayCard(15);
	std::cout << deck.getNumCards() << std::endl;;
	deck.printDeck(); */
	
	//addcard 
	//Card card2 = Card(3, 2);
	//deck.addCard(card2);
	
	/*std::cout << "NEWNEWNEWNEWNEWNNEW" << std::endl;
	deck.shuffle();
	deck.printDeck();
	std::cout << "NEWNEWNEWNEWNEWNNEW\n" << std::endl;
	deck1.printDeck();
	//deck1.initializeDeck();
	deck1.mergeDecks(deck, true); */
	
	//Card card2 = Card(3, 2);
	//deck1.addCard(card2);
	//deck1.printDeck();
	
	//deck.printDeck();
	//deck2.initalizeDeck();
	







return 0;
}