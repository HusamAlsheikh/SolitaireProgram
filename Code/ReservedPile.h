//	Husam Alsheikh

#pragma once
#include <iostream>
#include "Pile.h"
#include "Card.h"

class ReservedPile : public Pile{
public:
	ReservedPile();

	string show();
};