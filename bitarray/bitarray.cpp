#include "bitarray.h"
#include <iostream>


BitArray::BitArray(int size) //Initializing Constructor
{
	//Defining bytes/length
	BYTES = size;
	LENGTH = BYTES * BIT_IN_BYTE;

}

BitArray::BitArray(const BitArray & array) //Constructor
{
	//Assigning length/bytes to array
	LENGTH = array.LENGTH;
	BYTES = array.BYTES;
	
	data_ = new char[BYTES];

	// std::cout << "Number of bits: " << LENGTH << std::endl; //Print statement for number of bits
	
}

BitArray::~BitArray() //Deconstructor
{
	if(data_ != NULL) //If there's data in the bitarray, delete that data
	{
		delete [] data_;
	}
}

bool BitArray::get(int position) const //Get method
{
	if((data_[position/BIT_IN_BYTE] & (1 << (7 - (position % BIT_IN_BYTE))))==0) //Returns character from array
	{
		return false;
	}
	else
	{
		return true;
	}
}

void BitArray::print() //Print method
{	
	std::cout << "|";
	
	for (int i=0; i<BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}

void BitArray::initialize(char * word, int size) //Initialize method to take in word/size of word
{
	delete [] data_;
	data_ = new char[size];
	
	for(int i=0; i<size; i++)
	{
		data_[i] = word[i];
	}
	
}

bool BitArray::flip(int position) //Flip method
{
	char bitmask = (1 << (7 - (position % BIT_IN_BYTE))); //Bitmask
	int index = position/BIT_IN_BYTE; //Index
		
	if(position < LENGTH & position >=0)
	{
		data_[index] = data_[index] ^ bitmask; //Takes the BitArray and does an XOR operation w/ the bitmask
		return true;
	}
	else
	{
		return false;
	}
}

bool BitArray::set(int position, int bit) //Set method
{
	char bitmask = (1 << (7 - (position % BIT_IN_BYTE))); //Bitmask
	int index = position/BIT_IN_BYTE; //Index
		
	if(position < LENGTH & position >=0)
	{
		if(bit == 1)
		{
			data_[index] = data_[index] | bitmask; //Takes the BitArray and does an OR operation w/ bitmask

		}
		else
		{
			data_[index] = data_[index] & (bitmask ^ 255); //Takes the BitArray and does an AND operation with the bits from the XOR operation of the bitmask and a bitmask full of 1's
		}
		return true;

	}
	else
	{
		return false;
	}
}

char BitArray::get8(int position) const //Get8 method
{
	return data_[position/BIT_IN_BYTE]; //Returns character from array
}

void BitArray::complement() //Complement method
{
	char bitmask = 255;
	for(int i=0; i<BYTES; i++)
	{
		data_[i] = data_[i] ^ bitmask; //Takes the BitArray and does an XOR operation w/ a bitmask full of 1's
	}
}

void BitArray::clear() //Clear method
{
	for(int i=0; i<BYTES; i++)
	{
		data_[i] = 0; //Sets all bits to 0
	}
}

void BitArray::set8(char c, int index)
{
	data_[index] = c;
}



	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors