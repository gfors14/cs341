driver.o: driver.cpp card.o standardDeck.o
	g++ driver.cpp card.o standardDeck.o -o blah 

card.o: card.cpp card.h
	g++ -c card.cpp -o card.o
	
standardDeck.o: standardDeck.cpp standardDeck.h
	g++ -c standardDeck.cpp -o standardDeck.o

clean:
	rm -f card.o