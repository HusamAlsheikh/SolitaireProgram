//	Husam Alshiekh

#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

//	Description:	Constructor function to create instance of class
//	Pre-Condition:	none
//	Post-Condition:	Create instance of Card class
Card::Card() {

}

//	Description:	Overriding constructor function	
//	Pre-Condition:	Char suit and Char rank as parameters
//	Post-Condition:	Creates instance of class and initializes varaibles from parameters
Card::Card(char suit, char rank) {
	this->suit = suit;
	this->rank = rank;

	flipped = 1;

	next = nullptr;
	prev = nullptr;
}

//	Description:	Member function to flip a card
//	Pre-Condition:	Int parameter for flipped
//	Post-Condition:	Sets flipped to passed parameter
void Card::flip(int flipped) {
	this->flipped = flipped;
}

//	Description:	Member function to return card color
//	Pre-Condition:	none
//	Post-Condition:	Returns bool whether color is red or not
bool Card::isRed() {
	if (suit == 'H' || suit == 'D') {
		return true;
	}

	return false;
}

//	Description:	Member function to return suit
//	Pre-Condition:	none
//	Post-Condition:	Return suit
char Card::getSuit() { return suit; }

//	Description:	Member function to return rank
//	Pre-Condition:	none
//	Post-Condition:	Return rank
int Card::getRank() { return rank; }

//	Description:	Member function to return card rank and suit as string
//	Pre-Condition:	none
//	Post-Condition:	Return card as string
string Card::getCard() {
	string temp;

	if (flipped) {
		if (rank == 1) {
			temp = "A";
		}
		else if (rank == 11) {
			temp = "J";
		}
		else if (rank == 12) {
			temp = "Q";
		}
		else if (rank == 13) {
			temp = "K";
		}
		else {
			temp = to_string(rank);
		}

		return	temp + suit;
	}

	return "?";
}