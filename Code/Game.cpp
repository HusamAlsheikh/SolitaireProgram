//	Husam Alsheikh

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Game.h"

using namespace std;

//	Description:	Constructor function
//	Pre-Condition:	none
//	Post-Condition:	Creates instance of class and initializes values
Game::Game() {
	deck.type = 'T';
    points = 0;
    finish = 1;
    count = 0;

	reserved[0].type = 'H';
	reserved[1].type = 'D';
	reserved[2].type = 'S';
	reserved[3].type = 'C';

    output.open("C:\\Users\\alshe\\Box Sync\\UMD\\CIS 200 (C++)\\Project 3\\cis200Solitaire.txt", ios::out);
}

//	Description:	Member function to sort deck with algorithm
//	Pre-Condition:	none
//	Post-Condition:	Sort deck asc
void Game::sortAsc() {  // Selection Sort
    int minIndex;

    for (int x = 0; x < 51; x++) {
        minIndex = x;

        for(int z = x + 1; z < 52; z++) {
            if (allCards[z].getRank() < allCards[minIndex].getRank()) {
                minIndex = z;

                Card temp = allCards[x];
                allCards[x] = allCards[minIndex];
                allCards[minIndex] = temp;
            }
        }
    }
}

//	Description:	Member function to sort deck with algorithm
//	Pre-Condition:	none
//	Post-Condition:	Sort deck desc
void Game::sortDesc() { // Insertion Sort
    Card temp;
    int z;

    for (int x = 1; x < 52; x++) {
        temp = allCards[x];
        z = x - 1;

        while (z >= 0 && allCards[z].getRank() < temp.getRank()) {
            allCards[z + 1] = allCards[z];
            z--;
        }

        allCards[z + 1] = temp;
    }
}

//	Description:	Member function ot sort deck with algorithm
//	Pre-Condition:	none
//	Post-Condition:	Sort deck by suit
void Game::sortSuit() { //  Bubble Sort
    int valueC = 0;
    int valueN = 0;

    for (int x = 0; x < 51; x++) {
        for (int z = 0; z < 52 - x - 1; z++) {
            valueC = getValue(allCards[z]);
            valueN = getValue(allCards[z + 1]);

            if (valueN > valueC) {  // if suit is higher ( order goes H->D->S->C) then swap
                Card temp = allCards[z];
                allCards[z] = allCards[z + 1];
                allCards[z + 1] = temp;
            }
        }
    }
}

//	Description:	Member function to print deck
//	Pre-Condition:	none
//	Post-Condition:	Prints deck
void Game::printDeck() {
    for (int x = 0; x < 52; x++) {
        allCards[x].flip(1);
        cout << allCards[x].getCard() << ", ";
    }
}

//	Description:	Member function to return card suit as int
//	Pre-Condition:	Temp parameter as Card
//	Post-Condition:	Returns suit as int
int Game::getValue(Card temp) {
    if (temp.getSuit() == 'H') {
        return 4;
    }
    else if (temp.getSuit() == 'D') {
        return 3;
    }
    else if (temp.getSuit() == 'S') {
        return 2;
    }
    else {
        return 1;
    }
}

//	Description:	Member function to delete card and free memory
//	Pre-Condition:	none
//	Post-Condition:	Deallocate memory
void Game::burn() {
	deck.burn();

	for (int x = 0; x < 7; x++) {
		playing[x].burn();
	}

	for (int x = 0; x < 4; x++) {
        reserved[x].burn();
	}
}

//	Description:	Member function to deal next card
//	Pre-Condition:	noen
//	Post-Condition:	Deals next card in undealt deck
void Game::deal() {
	deck.deal();

    output << "New Card dealt: " << deck.top->getCard() << endl << endl;
}

//	Description:	Member function to load cards to respective piles
//	Pre-Condition:	Array of pointers to cards
//	Post-Condition:	Load cards to respective piles
void Game::load(Card* toLoad[]) {
	this->burn();

	int startPile = 0;
	int currPile = 0;

    //  copy from linked list to array
    for (int x = 0; x < 52; x++) {
        allCards[x] = *toLoad[x];
    }

    int rand1, rand2;

    srand(time(NULL));

    //  randomize / shuffle
    if (count == 1) {
        for (int x = 0; x < 52; x++) {
            rand1 = rand() % 51;
            rand2 = rand() % 51;

            Card temp = *toLoad[rand1];
            *toLoad[rand1] = *toLoad[rand2];
            *toLoad[rand2] = temp;
        }

        //  copy from linked list to array
        for (int x = 0; x < 52; x++) {
            allCards[x] = *toLoad[x];
        }

        output << "Shuffling Deck!" << endl << endl;
    }

	for (int x = 0; x < 28; x++) {
		if (currPile > 6) {
			startPile++;
			currPile = startPile;
		}
		else {
			toLoad[x]->flip(0);
		}

		if (x == 0) {
			toLoad[x]->flip(1);
		}

		playing[currPile].add(toLoad[x]);
		currPile++;
	}

	for (int x = 51; x > 27; x--) {
		deck.add(toLoad[x]);
	}

    if (count == 0) {
        output << "Loading cards to decks and piles!" << endl << endl;
        count = 1;
    }
}

//	Description:	Member function to quit game
//	Pre-Condition:	none
//	Post-Condition:	Quits game
void Game::quit() {
    finish = 0;

    output << "Quitting game!" << endl << endl;
}

//	Description:	Member function to print board
//	Pre-Condition:	none
//	Post-Condition:	Prints board
void Game::printBoard() {
    int lines = 1;

    cout << right << setw(55) << "HUSAM'S SOLITAIRE GAME" << endl;
    cout << "Heart Pile: " << reserved[0].show() << right << setw(20);
    cout << "Diamond Pile: " << reserved[1].show() << right << setw(20);
    cout << "Spade Pile: " << reserved[2].show() << right << setw(20);
    cout << "Clubs Pile: " << reserved[3].show() << right << setw(20) << endl;

    cout << left << setw(15) << "Pile 1";
    cout << "Pile 2" << right << setw(15);
    cout << "Pile 3" << right << setw(15);
    cout << "Pile 4" << right << setw(15);
    cout << "Pile 5" << right << setw(15);
    cout << "Pile 6" << right << setw(15);
    cout << "Pile 7" << right << setw(15) << endl;

    //find amount of lines needed to print
    for (int x = 0; x < 7; x++) {
        if (playing[x].size() > lines) {
            lines = playing[x].size();
        }
    }
    
    //print top row of active data
    for (int x = 0; x < 7; x++) {
        cout << setw(4) << playing[x].show() << "           ";
    }

    //print next rows of active data
    for (int line = 1; line < lines; line++) {
        cout << endl;

        for (int x = 0; x < 7; x++) {
            cout << setw(4) << playing[x].showNext() << "           ";  //show next card of all active decks
        }
    }

    cout << "\nDeck: " << deck.show();

    checkWin();

    output << "Printing board!" << endl << endl;
}

//	Description:	Member function to check if user won game
//	Pre-Condition:	none
//	Post-Condition:	Checks if user won game
void Game::checkWin() {
    bool win = true;

    for (int x = 0; x < 7; x++) {
        points += playing[x].size() * 10;
    }

    for (int x = 0; x < 7; x++) {
        if (playing[x].size() > 0) {
            win = false;
            break;
        }
    }

    if (deck.size() > 0) {
        win = false;
    }
   
    if (win) {
        cout << "\n\n\n\n\t\t\tCONGRATULATIONS!!!!\n\t\tYou Have Won the game!\n\t\t\tScore: " << points << "\n\n\n";

        output << "\n\n\n\n\t\t\tCONGRATULATIONS!!!!\n\t\tYou Have Won the game!\n\t\t\tScore: " << points;
        quit();
    }
}

//	Description:	Member function to close file output
//	Pre-Condition:	none
//	Post-Condition:	Closes file output
void Game::closeFile() {
    output.close();
}