//hangman.h
#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>
using namespace std;


class hangman {
public:
/**
*@pre: none
*@post: returns a random word from an array of strings of cs related words
*@param: none
*@throw: none 
*/
string randomlyGenerateWord();

/**
*@pre: expects valid integer as parameter
*@post: returns true if there have been less than 6 guesses or 6 guesses and false otherwise
*@param: an integer that represents the number of wrong guesses is passed as a parameter
*@throw: none 
*/
bool funcForWrongGuess(int numGuesses);

/**
*@pre: expects valid integer as parameter
*@post: void function that outputs the stick figure corresponding to the number of wrong guesses the player has made
*@param: an integer that represents the number of wrong guesses
*@throw: none 
*/
void displayStickFigure(int numGuesses);

/**
*@pre: hangman is the game the player chooses to play
*@post: allows the user to guess letters of a secret word until they either guess all the letters correctly or run out of guesses
*@param: none
*@throw: cleany exits game if something that isn't an integer (such as a char) is given when the program is asking for an integer 
*/
hangman();

};
#endif


