//	Husam Alsheikh

#pragma once
#include <iostream>

using namespace std;

class Card {
private:
	char suit;
	int rank;

public:
	Card* next;
	Card* prev;
	bool flipped;

	Card();

	Card(char rank, char suit);

	void flip(int flipped);

	bool isRed();

	char getSuit();

	int getRank();

	string getCard();
};