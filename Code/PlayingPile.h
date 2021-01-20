//	Husam Alsheikh

#pragma once
#include <iostream>
#include "Pile.h"

using namespace std;

class PlayingPile : public Pile{
public:
	Card* display;

	PlayingPile();

	string show();

	string showNext();
};