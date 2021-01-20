//	Husam Alsheikh

#pragma once
#include <iostream>
#include <fstream>
#include "Game.h"

class ParseGame {
private:
	ofstream output;

public:
	ParseGame();

	void parse(string input, Game* myGame);
};