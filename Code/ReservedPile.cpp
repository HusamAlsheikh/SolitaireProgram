//	Husam Alsheikh

#include <iostream>
#include "ReservedPile.h"
#include "Pile.h"

using namespace std;

//	Description:	Constructor function
//	Pre-Condition:	none
//	Post-Condition:	Creates instance of ReservedPile and Pile
ReservedPile::ReservedPile() {
	Pile();
}

//	Description:	Member function to return card as string
//	Pre-Condition:	none
//	Post-Condition:	Returns card on top of sorting pile as string
string ReservedPile::show() {
	if (top) {
		return top->getCard();
	}

	return "O    ";
}