# SolitaireProgram
Solitaire Program for Computer Science 2 class. Program contains implementation of solitaire card game.

## INTRODUCTION: SOLITAIRE THE CARD GAME

For this programing assignment you will re-create a simple card game called solitaire . The image  below shows the traditional set-up for the game. It is played with a standard 56 card deck comprised of 4 suites: (D)iamonds, (H)earts, (S)pades, and (C)lubs. Each suite has 14 cards: (A)ce, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, (J)ack, (Q)ueen, (K)ing. The 4 suites are organized in to two colors: Red (D,H) and Black(S,C).  

To start the game, one shuffles the deck and deals six cards face down each in a different pile and one face up displaying the card. Next, the player deals four cards face down and one upright and so on until each pile has a face up card. When finished setting up the game looks as the image below although face up cards may vary.  
 
A space for 4 piles is reserved at the side or top of the playing area. As the user plays the game they will add the cards to the reserved piles (thus scoring points). Each pile only holds one suite and cards must be stacked in the pile from Ace to King in order. Cards may be moved to the pile when they are the last face up card on the stack or from the draw pile (the rest of the undealt cards). In order to sort the cards in to the 4 piles users must move the cards on the playing surface or flip over cards from the undealt deck.  

Cards may be placed on each if they are one-less than and the opposite color to the card it is being placed on. For example, in the image below the user could pick up and place the 3H on the 4S, or the user could place the 9C on 10D. However, the user could not place the 10D on the JD. When there are no face-up cards covering a face-down card (?) then the user can flip the card over. If no cards exist in a pile, then the user may only start a new pile in its place with a King of any suite. Multiple cards can be picked up at one time and moved to another pile. For example: A stack from top to bottom (10D, 9S, 8H) could be placed on a face-up JC making the new stack (JC, 10D, 9S, 8H).  

Lastly, users can make use of the undealt cards. The undealt cards start face-down. The user may then flip through the deck three cards (or if not-divisible by 3 the remainder) at a time. The third card is shown to the user on the top of the discard pile. The user may then make use of this top card by adding it to a scoring pile or placing in the playing area on another pile of cards as appropriate. The next card in the discard pile may then be used in a similar manner.

*Solitaire Wiki: https://en.wikipedia.org/wiki/Patience_(game)*  
*Google Solitaire: https://www.google.com/search?q=solitare&ie=utf-8&oe=utf-8&client=firefox-b-1#clb=clb*

The user wins the game when all of the cards have been sorted in to the 4 sort piles. The user loses the game if they are unable to sort the cards in to the pile after three complete flips through the undealt card deck. The user is awarded 10 points per card in the sort pile which is displayed to the user with a victory being equal to 560 points.

![alt text](https://github.com/HusamAlsheikh/SolitaireProgram/blob/main/Images/Picture1.png?raw=true)  


## ASSIGNMENT REQUIRMENTS  

You will be required to implement a card deck and the game of solitaire in C++ using the console window to show the playing board. The game will be implemented as follows:  
- Use MUST use stacks or queues (your choice) to store the card deck, the discard pile, the 7 playing area piles, and the 4 sort piles.  
  - You MUST write a custom stack and queue class using a linked-list implementation that you wrote.   
  - The Standard Template Library may NOT be used for these data structures (stack / que / linked-list).  
  - The stack or queue MUST store the cards in the following format: Card Number or Letter followed by the Suite Letter.  
    - The Card Numbers (from lowest to highest): A, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K  
    - The Suites: H, D, C, S  
    - Examples: 10 of Diamonds = 10D, Ace of Spades = AS, Queen of Hearts = QH  
- You MUST implement the UI as shown below.  
  - Your game must look like this with nice formatting. Hint:  <iomanip>  setw() function  
  - You must implement the options specified (how is up to you)  
    - 1: Moves a selected card to the sort pile of its suite (If a valid move) Hint: Exception Handling)  
    - 2: Move a card or cards from specified pile or discard to some other pile (If a valid Move)  
    - 3: Flip cards in discard pile  
- You MUST implement all of the rules of the card game Solitaire as stated in introduction section.  
- You MUST additionally write a custom shuffle function to randomize the cards before play starts.  
  - Hint: Use the rand()  function with a seed from computer’s clock to perform randomization.  
    - Uses standard library and time library: <stdlib> and <time>  
    - The cards are not random each flip. As soon as the deck is randomized once it will stay in that order throughout the game.   
- You MUST write a function to print out the cards in the deck.   
- You MUST write a function to sort the cards in increasing order: A,A,A,A,1,1,1,1,2,2,2,2….K,K,K.K  
  - You may use the following algorithms to perform the sort: Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Merge Sort, Heap Sort  
    - Note: You must write the code for the algorithms yourself. No STL or other library.  
- You MUST write a function to sort the cards in decreasing order: K,K,K,K,Q,Q,Q,Q,J,J,J,J….1,1,1,1,A,A,A,A  
  - Same rules for the increasing sort applies.
- You MUST do the following before the start of the game:
  - Print out deck order by suite (How you should initialize the array)
    - For example: AH,1H,2H,…KH,AD,1D,2D,…KD….KS…KC
  - Sort the deck in increasing order and print out to screen.
  - Sort the deck in decreasing order and print out to screen.
  - Shuffle (randomize) the deck and print out to screen.
  - Then you may begin the game logic. 
- You MUST display a victory or game over (lost game) message which also displays the user’s final score.
- You MUST output every action of your program to a file called cis200Solitare.txt
- You MUST use class-based programming. If you use global parameters or any function not named main outside of a class you will receive 0 points on this assignment. 

*IO Manipulation Library C++.com: http://www.cplusplus.com/reference/iomanip/*  

Sample Start of Game Screen  
![alt text](https://github.com/HusamAlsheikh/SolitaireProgram/blob/main/Images/Picture2.png?raw=true)  

*Rand() C++.com: http://www.cplusplus.com/reference/cstdlib/rand/*  

Sample Game A Few Moves Later  
![alt text](https://github.com/HusamAlsheikh/SolitaireProgram/blob/main/Images/Picture3.png?raw=true)  

Don’t do everything in main.  You should use functions (more than one) to make the code cleaner and better organized.  
