#include "HashEntry.h"

HashEntry::HashEntry() //Constructor
{
	status_ = EMPTY;
}

HashEntry::~HashEntry()
{

}

int HashEntry::getKey()
{
	return key_;
}

void HashEntry::setKey(int key)
{
	key_ = key;
}

int HashEntry::getValue()
{
	return value_;
}

void HashEntry::setValue(int value)
{
	value_ = value;
}

Status HashEntry::getStatus() 
{
	return status_;
}

void HashEntry::setStatus(Status status)
{
	status_ = status;
}