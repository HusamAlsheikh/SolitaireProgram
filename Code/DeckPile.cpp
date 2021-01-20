//	Husam Alsheikh

#include <iostream>
#include "DeckPile.h"
#include "Pile.h"

using namespace std;

//	Description:	Constructor function
//	Pre-Condition:	none
//	Post-Condition:	Creates instance of DeckPile and Pile
DeckPile::DeckPile() {
	Pile();
}

//	Description:	Member function to deal another card from undealt cards
//	Pre-Condition:	none
//	Post-Condition:	Deals another card from undealt pile
void DeckPile::deal() {
	if (this->top && this->top->next) {
		Card* current = top;

		while (current->next) {
			current = current->next;
		}

		current->next = top;
		top->prev = current;

		top = top->next;

		current->next->next = nullptr;
		current->next->prev = current;
	}
}