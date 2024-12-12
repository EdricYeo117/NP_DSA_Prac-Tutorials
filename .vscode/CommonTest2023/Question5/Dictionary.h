#pragma once
#include <string>
#define SIZE 5
using namespace std;

class Dictionary
{
private:
	struct KeyValuePair
	{
		int key;
		string value;
		KeyValuePair* next;
	};
	KeyValuePair* table[SIZE];

public:
	// constructor
	Dictionary();

	// destructor
	~Dictionary();

	// returns the hash value of a given key.
	int hashFunction(int key);

	// inserts a new key-value pair to the table array.
	void insert(int key, string value);

};

#include "Dictionary.cpp"