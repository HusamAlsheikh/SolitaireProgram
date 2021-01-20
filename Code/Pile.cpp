//	Husam Alsheikh

#include <iostream>
#include "Pile.h"

//	Description:	Constructor function
//	Pre-Condition:	none
//	Post-Condition:	Creates instance of class
Pile::Pile() {
	top = nullptr;
	type = 'X';
}

//	Description:	Overriden constructor function
//	Pre-Condition:	Char type parameter	
//	Post-Condition:	Creates instance of class and sets type to parameter
Pile::Pile(char type) {
	Pile();
	this->type = type;
}

//	Description:	Member function to return whether pile is empty or not
//	Pre-Condition:	none
//	Post-Condition:	Returns bool whether pile empty or not
bool Pile::isEmpty() {
	if (top == nullptr) {
		return true;
	}

	return false;
}

//	Description:	Member function to return size of pile
//	Pre-Condition:	none
//	Post-Condition:	Return pile size
int Pile::size() {
	if (!isEmpty()) {
		int temp = 1;
		Card* current = this->top;

		while (current && current->next) {
			temp++;
			current = current->next;
		}

		return temp;
	}

	return 0;
}

//	Description:	Member function to add card
//	Pre-Condition:	Suit and rank parameters as char
//	Post-Condition:	Add card
void Pile::add(char suit, char rank) {
	Card* newC = new Card(suit, rank);

	if (!isEmpty()) {	// if pile is not empty, add new card to top of pile
		newC->next = this->top;

		this->top->prev = newC;
		this->top = newC;

		newC->prev = nullptr;
	}
	else {	// start pile with new card
		newC->next = nullptr;
		newC->prev = nullptr;

		this->top = newC;
	}
}

//	Description:	Overriden member function to add card
//	Pre-Condition:	Pointer parameter to card
//	Post-Condition:	Add card
void Pile::add(Card* newC) {
	if (newC->next) {	// set new cards next card prev to nullpointer
		newC->next->prev = nullptr;
	}

	if (!isEmpty()) {	// if empty set top prev to new card
		this->top->prev = newC;
	}

	newC->next = this->top;	// set new card next to top
	newC->prev = nullptr;	// set new card prev to nullpointer

	this->top = newC;	// set top to be newC
}

//	Description:	Member functiont to add to stack
//	Pre-Condition:	Pointer parameter to card
//	Post-Condition:	Pushes card to stack
void Pile::push(Card* newC) {
	Card* newTop = newC;

	while (newTop->prev) {
		newTop = newTop->prev;
	}

	if (newC->next) {
		newC->next->prev = nullptr;
	}

	if (this->top) {
		this->top->prev = newC;
	}

	newC->next = this->top;
	this->top = newTop;
}

//	Description:	Member funcion to return whether move is valid
//	Pre-Condition:	Pointer parameter to pile
//	Post-Condition:	Return bool whether move is valid
bool Pile::moveTo(Pile* to) {
	Card* newC = this->top;
	bool valid = false;
	char toType = to->type;

	if (isEmpty()) {	// throw invalid if pile is empty
		return false;
	}

	switch (this->type) {
	case 'T':	// from Deck Pile
		if (toType == 'P') {	// move deck to playing pile
			if(!to->isEmpty()){	// if to pile is not empty
				if (this->top->getRank() + 1 == to->top->getRank() && (this->top->isRed() != to->top->isRed())) {	// valid move since less rank and opp color
					valid = true;
				}
			}
			else {	// if to pile is empty check if card is king
				if (this->top->getRank() == 13) {
					valid = true;
				}
			}
		}
		else if (toType == 'T') {

		}
		else if (toType == this->top->getSuit()) {	// if to pile is completed and same suit
			if (!to->isEmpty()) {	// if to pile is not empty
				if (this->top->getRank() == to->top->getRank() + 1) {
					valid = true;
				}
			}
			else {	// if to pile is empty check if card is ace
				if (this->top->getRank() == 1) {
					valid = true;
				}
			}
		}

		if (valid) {
			if (newC->next) {
				this->top = newC->next;
				to->add(newC);
			}
			else if (newC->next == nullptr) {
				this->top = new Card('?', '?');
				to->add(newC);
			}
		}

		break;
	case 'P':	// from Playing Pile
		if (toType == 'P') {
			if (to->top) {
				while (newC && !valid && newC->flipped) {
					if (newC->getRank() + 1 == to->top->getRank() && (newC->isRed() != to->top->isRed())) {	// valid move since less rank and opp color
						valid = true;
						break;
					}

					newC = newC->next;
				}
			}
			else {
				while (newC && !valid) {
					if (newC->getRank() == 13) {	// if to pile is empty check if card is king
						valid = true;
						break;
					}

					newC = newC->next;
				}
			}
		}
		else if (toType == 'T') {

		}
		else if (toType == this->top->getSuit()) {
			if (to->top) {
				if (this->top->getRank() == to->top->getRank() + 1) {	// valid move since higher rank
					valid = true;
				}
			}
			else {
				if (this->top->getRank() == 1) {	// if to pile is empty check if card is ace
					valid = true;
				}
			}
		}

		if (valid) {
			if (newC) {
				this->top = newC->next;

				if (this->top) {
					this->top->flip(1);
				}
			}
			else {
				this->top = nullptr;
			}

			to->push(newC);
		}

		break;
	default:
		cout << "Invalid from pile!";
		return false;
	}
}

//	Description:	Member function to return card on pile
//	Pre-Condition:	none
//	Post-Condition:	Return card as string
string Pile::show() {
	if (top) {
		return top->getCard();
	}
	
	return "?";
}

//	Description:	Member function to delete card and free memory
//	Pre-Condition:	none
//	Post-Condition:	Frees memory deallocating memory
void Pile::burn() {
	while (top && top->next) {
		top = top->next;

		delete top->prev;
	}

	delete top;
	top = nullptr;
}