//	Husam Alsheikh

#include <iostream>
#include <string>
#include <fstream>
#include "ParseGame.h"

using namespace std;

//	Description:	Constructor function
//	Pre-Condition:	none
//	Post-Condition:	Will create instance of class and set output file location
ParseGame::ParseGame() {
    output.open("C:\\Users\\alshe\\Box Sync\\UMD\\CIS 200 (C++)\\Project 3\\cis200Solitaire.txt", ios::out);
}

//	Description:	Member function that will run some of game logic and commands
//	Pre-Condition:	String input and Game object parameters
//	Post-Condition:	Run game commands and some logic
void ParseGame::parse(string input, Game* myGame) {
    string data = "";

    //convert everything to caps
    for (int x = 0; x < input.length(); x++) {
        data += toupper(input[x]);//converts by char
    }

    data += " ";    //prevents nullpointer crashes when looking at next char

    int len = data.length() - 1;

    string word = data.substr(0, 4);

    if (word == "DEAL") {
        myGame->deal();
        myGame->printBoard();
    }
    else if (word == "LOAD") {
        // x designates char operating on
        char current;
        int rank;
        int term;
        Card* toLoad[52];
        term = 0;

        for (int x = 4; x < len; x++) {
            current = data.at(x);
            rank = 0;

            switch (current) {
            case 'A': rank = 1; break;  // Rank = A
            case '2': rank = 2; break;  // Rank = 2
            case '3': rank = 3; break;  // Rank = 3
            case '4': rank = 4; break;  // Rank = 4
            case '5': rank = 5; break;  // Rank = 5
            case '6': rank = 6; break;  // Rank = 6
            case '7': rank = 7; break;  // Rank = 7
            case '8': rank = 8; break;  // Rank = 8
            case '9': rank = 9; break;  // Rank = 9
            case 'J': rank = 11; break; //Rank = J
            case 'Q': rank = 12; break; //Rank = Q
            case 'K': rank = 13; break; //Rank = K
            case ' ': break;
            default: cout << "\nInvalid rank:" << current << " at position:" << x - 1;

            case '1':
                x++;
                current = data.at(x);

                if (current == '0') {
                    rank = 10; break; //Rank = 10
                }
                //handles error if invalid rank 1X,
                else {
                    cout << "\nExpected rank '10' instead of '" << current << "' at position:" << x - 1;

                    if (current == 'H' || current == 'D' || current == 'C' || current == 'S') {
                        cout << ". Assuming A was meant.";
                        x--;
                        rank = 1; break;
                    }
                    else if (current == '1') {
                        cout << ". Assuming J was meant.";
                        x--;
                        rank = 11; break;
                    }
                    else if (current == '2') {
                        cout << ". Assuming Q was meant.";
                        x--;
                        rank = 12; break;
                    }
                    else if (current == '3') {
                        cout << ". Assuming K was meant.";
                        x--;
                        rank = 13; break;
                    }
                    else {
                        x--; break;
                    }
                }
            }

            //if valid rank found
            if (rank) {
                x++;
                current = data.at(x);

                if (current == 'H' || current == 'D' || current == 'C' || current == 'S') {
                    toLoad[term] = new Card(current, rank); //create a new Card
                    term++; //increment Card count
                }
                else {
                    cout << "\nInvalid suit:" << current << " at position:" << x - 1;
                }
            }
        }

        if (term < 28) {
            cout << "\nPlease enter MORE cards than " << term << ", amount of cards can only be from 28-52.";
        }
        else if (term > 52) {
            cout << "\nPlease enter LESS cards than " << term << ", amount of cards can only be from 26-52.";
        }
        else {
            // load cards into myGame
            myGame->load(toLoad);
        }
    }
    else if (word == "MOVE"){
        Pile* from;
        Pile* to;
        int source = 0;
        int destination = 0;
        bool pastToDelim = false;
        char current;

        from = nullptr;
        to = nullptr;

        for (int x = 4; x < len; x++){
            current = data.at(x);

            //find from
            if(!from){
                switch(current){
                    case 'T': from = &myGame->deck;break;
                    case '1': from = &myGame->playing[0]; source = 1; break;
                    case '2': from = &myGame->playing[1]; source = 2; break;
                    case '3': from = &myGame->playing[2]; source = 3; break;
                    case '4': from = &myGame->playing[3]; source = 4; break;
                    case '5': from = &myGame->playing[4]; source = 5; break;
                    case '6': from = &myGame->playing[5]; source = 6; break;
                    case '7': from = &myGame->playing[6]; source = 7; break;
                    case ' ': break;    //ignore spaces
                    default:
                        //  errorString+="\nInvalid FROM parameter in move command:";
                        //  errorString+=current;
                        break;
                }
            }
            else if(!to) {
                //move past 'TO'
                if(pastToDelim){
                    //find destination Pile
                    switch(current){
                        case '1': to = &myGame->playing[0]; destination = 1; break;
                        case '2': to = &myGame->playing[1]; destination = 2; break;
                        case '3': to = &myGame->playing[2]; destination = 3; break;
                        case '4': to = &myGame->playing[3]; destination = 4; break;
                        case '5': to = &myGame->playing[4]; destination = 5; break;
                        case '6': to = &myGame->playing[5]; destination = 6; break;
                        case '7': to = &myGame->playing[6]; destination = 7; break;
                        case 'H': to = &myGame->reserved[0]; destination = 1; break;
                        case 'D': to = &myGame->reserved[1]; destination = 2; break;
                        case 'S': to = &myGame->reserved[2]; destination = 3; break;
                        case 'C': to = &myGame->reserved[3]; destination = 4; break;
                        case ' ': break;    //ignore spaces
                        default: break;
                    }
                }

                //if 'TO' is the next term (check data length to prevent crash from
                if (data.at(x) == 'T' && data.at(x + 1) == 'O') {
                    pastToDelim = true;
                    x++;    //flag that delimiter has been found and move along)
                }
            }
        }

        //if validly parsed move, perform the move
        if(from && to ){
            from->moveTo(to);

            output << "Moved " << from->show() << " from " << from->type << source << " to " << to->type << destination << endl << endl;
        }

        myGame->printBoard();
    }
    else if (word=="QUIT"||word=="EXIT"){
        myGame->quit();
    }
    else {
        cout << "\nInvalid Command!";
    }
}