//	Husam Alsheikh

#pragma once
#include <iostream>
#include "Card.h"

using namespace std;

class Pile {
public:
	Card* top;
	char type;

	Pile();

	Pile(char type);

	bool isEmpty();

	int size();

	void add(char suit, char rank);

	void add(Card* newC);

	void push(Card* newC);

	bool moveTo(Pile* to);

	string show();

	void burn();
};