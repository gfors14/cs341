#include "set.h"

Set::Set(int size) : data_(size) //Constructor
{
	
}

Set::~Set() //Deconstructor
{

}

void Set::initialize(char * word, int size) //Initialize method
{
	data_.initialize(word, size); //Uses bitarray class' initalize to initialize the data_ bitarray
}

int Set::getCardinality() const //GetCardinality method
{
	int count=0;
	
	for(int i=0; i<data_.length(); i++)
	{
		if(data_.get(i) == 1)
		{
			count++;
		}
	}
	return count; //Returns cardinality
}

BitArray & Set::getData() //GetData method
{
	return data_; //Returns data bitarray
}

bool Set::setUnion(Set & B) //SetUnion method
{
	char c;
	if (data_.bytes() >= B.getData().bytes())
	{
		for(int i=0; i<B.getData().bytes(); i++)
		{
			c = (data_.get8(i*8)) | (B.getData().get8(i*8));
			data_.set8(c,i);
		}
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Set::setIntersection(Set & B) //SetIntersection method
{
	char c;
	if (data_.bytes() >= B.getData().bytes())
	{
		for(int i=0; i<B.getData().bytes(); i++)
		{
			c = (data_.get8(i*8)) & (B.getData().get8(i*8));
			data_.set8(c,i);
		}
		return true;
	}
	else
	{
		return false;
	}
}

	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors
