//	Husam Alsheikh

#pragma once
#include <iostream>
#include <fstream>
#include "Card.h"
#include "PlayingPile.h"
#include "ReservedPile.h"
#include "DeckPile.h"

using namespace std;

class Game {
public:
	int finish;
	int points;
	int count;
	PlayingPile playing[7];
	ReservedPile reserved[4];
	DeckPile deck;
	Card allCards[52];
	ofstream output;

	Game();

	void sortAsc();

	void sortDesc();

	void sortSuit();

	void printDeck();

	int getValue(Card temp);

	void burn();

	void deal();

	void load(Card* toLoad[]);

	void quit();

	void printBoard();

	void checkWin();

	void closeFile();
};