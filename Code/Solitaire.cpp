//	Husam Alsheikh

#include <iostream>
#include <iomanip>
#include <string>
#include "Game.h"
#include "ParseGame.h"

using namespace std;

//	Card:			Cards used in game, acts as node
//	Pile:			Superclass card node handler implementing different functions
//	ReservedPile:	Reserved Piles (4) used for scoring points
//	PlayingPile:	Playing Piles (7)
//	DeckPile:		Deck of undealt cards to browse through and use through the game

//	Description:	Main of program
//	Pre-Condition:	Game and ParseGame classes
//	Post-Condition:	Runs Solitaire program
void main() {
	Game myGame;
	ParseGame parser;

	string input;
	parser.parse("load KC KD KH QC QD QH JC JD JH 10C 10D 10H 9C 9D 9H 8C 8D 8H 7C 7D 7H 6C 6D 6H 5C 5D 5H 4C 4D 4H 3C 3D 3H 2C 2D 2H AC AD AH KS QS JS 10S 9S 8S 7S 6S 5S 4S 3S 2S AS", &myGame);
	
	//	Normal Messed Up Deck
	cout << "\tDeck: " << endl;
	myGame.printDeck();

	//	sort by suit and print
	cout << "\n\n\tSorted by Suit using Bubble Sort: " << endl;
	myGame.sortSuit();
	myGame.printDeck();

	//	sort ascending and print
	cout << "\n\n\tSorted Ascending by rank using Selection Sort: " << endl;
	myGame.sortAsc();
	myGame.printDeck();

	//	sort descending and print
	cout << "\n\n\tSorted Descending by rank using Insertion Sort: " << endl;
	myGame.sortDesc();
	myGame.printDeck();

	//	cards are shuffled when parsed then print
	cout << "\n\n\tDeck Shuffled: " << endl;

	//	re parsing to re shuffle after sorting messed up shuffling (too deep into program to go back and fix)
	parser.parse("load KC KD KH QC QD QH JC JD JH 10C 10D 10H 9C 9D 9H 8C 8D 8H 7C 7D 7H 6C 6D 6H 5C 5D 5H 4C 4D 4H 3C 3D 3H 2C 2D 2H AC AD AH KS QS JS 10S 9S 8S 7S 6S 5S 4S 3S 2S AS", &myGame);
	myGame.printDeck();

	cout << endl << endl;
	myGame.printBoard();

	while (myGame.finish != 0) {
		cout << "\nOptions:" << endl;
		cout << "\t1) Type 'MOVE' then [from] 'TO' [to] to move whole pile from deck/playing pile\n"
			 << "\tto playing pile (Example: move 3 to 4, or move t( represents undealt cards ) to 3)" << endl;
		cout << "\t2) Move a card in pile" << endl;
		cout << "\t3) Type 'Deal' to Deal next card in deck" << endl;
		cout << "\t4) Type 'Quit' or 'Exit' at any time to end game" << endl;
		cout << "\nYour Choice: ";
		getline(cin, input);

		parser.parse(input, &myGame);

		input = "";
	}

	myGame.closeFile();

	cout << endl;
	system("pause");
}