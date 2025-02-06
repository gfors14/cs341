#include "dictionary.h"

Dictionary::Dictionary() : data_(DICTIONARY_SIZE) //Initializing constructor
{

}

Dictionary::Dictionary (const Dictionary & dict) //Copy constructor
{

}

Dictionary::~Dictionary() //Deconstructor
{
	
}

void Dictionary::initialize(char * word, int size) //Initialize method
{
	data_.initialize(word, size); //Uses bitarray class' initalize to initialize the data_ bitarray
}

int Dictionary::rank_range(int start, int end, int bit) //Rank range method
{
	int sum = 0;
	for(int i=start; i<end; i++)
	{
		if(data_.get(i) == bit)
		{
			sum++;
		}
	}
	return sum;
}

int Dictionary::select_range(int start, int end, int k, int bit) //Select range method
{
	int count=0;
	for(int i=start; i<end; i++)
	{
		if(data_.get(i) == bit)
		{
			count++;
		}
		if(count == k)
		{
			return i;
		}
	}
	return 0;
}

int Dictionary::rank(int end, int bit) //Rank method - need to implement the bit = 1
{
	int sum = 0;
	for(int i=0; i<end; i++)
	{
		if(data_.get(i) == bit)
		{
			sum++;
		}
	}
	return sum; 
}

int Dictionary::select(int k, int bit) //Select method
{
	int count=0;
	for(int i=0; i<data_.length(); i++)
	{
		if(data_.get(i) == bit)
		{
			count++;
		}
		if(count == k)
		{
			return i;
		}
	}
	return 0;
}

void Dictionary::printLookupTable(std::ostream & output)
{
	
	
	
	
}

	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors


