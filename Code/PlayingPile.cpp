//	Husam Alsheikh

#include <iostream>
#include "PlayingPile.h"
#include "Pile.h"

//	Description:	Constructor function
//	Pre-Condition:	none
//	Post-Condition:	Create instance of PlayingPile and Pile, also initialize some variables
PlayingPile::PlayingPile() {
	Pile();

	type = 'P';

	display = nullptr;
}

//	Description:	Member function to return bottom card on playing pile as string
//	Pre-Condition:	none
//	Post-Condition:	Returns bottom card on playing pile as string
string PlayingPile::show() {
	Card* last = this->top;

	while (last && last->next) {
		last = last->next;
	}

	display = last;

	if (display) {
		return display->getCard();
	}
	
	return "";
}

//	Description:	Member function to return next card as string
//	Pre-Condition:	none
//	Post-Condition:	Return next card as string
string PlayingPile::showNext() {
	if (display && display->prev) {
		display = display->prev;

		return display->getCard();
	}

	return "";
}