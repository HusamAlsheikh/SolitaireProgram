//	Husam Alsheikh

#pragma once
#include <iostream>
#include "Pile.h"

using namespace std;

class DeckPile : public Pile {
public:
	DeckPile();

	void deal();
};