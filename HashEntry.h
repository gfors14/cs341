#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>

enum Status {EMPTY, OCCUPIED, REMOVED};

class HashEntry
{
	public:
		HashEntry();
		~HashEntry();

		int getKey();
		void setKey(int key);

		int getValue();
		void setValue(int value);

		Status getStatus();
		void setStatus(Status status);

	private:
		int key_;
		int value_;
		Status status_;
};
#endif