#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include "hangman.h"
#include "tictacto.h"
using namespace std;

int main(){
std::cout << "\x1B[2J\x1B[H";
int menuOption = 0;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n";
cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n";
cout << "W                 W   E E E E E   L           C C C C     O  O O     M          M   E E E E E \n"  ;
cout << " W               W    E           L          C          O        O   M  M  M  M M   E\n";
cout << "   W      W     W     E E E E     L          C          O        O   M     M    M   E E E \n";
cout << "     W   WW   W       E           L          C          O        O   M          M   E \n ";
cout <<"       W   W         E E E E E   L L L L L   C C C C     O  O  O    M          M   E E E E E \n\n ";
cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n";
cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n";

cout<< "\n\nHello! Welcome to Team 9 Mini Games \n";
do{
   cout << "* * * * * * * * * * * * * * * * \n";
cout<< "*        Game Options:        * \n";
cout << "* 1) Tic-tac-toe              *\n* 2) Hangman                  *\n* 3) Exit                     *\n*";
cout << "  Player Choice: ";
cin >> menuOption;
cout << "* * * * * * * * * * * * * * * * \n";

if(menuOption == 1){
std::cout << "\x1B[2J\x1B[H";
cout << "Rules of the game:\n\n";
cout << "Two players, one in a circle (O) and one in a cross (X), take turns to play their own symbols on the 3x3 grid.\n"; 
cout << "The first to connect horizontally, straightly, and diagonally to form a line wins. If both sides play correctly, there will be a tie.\n\n";
tictacto exe;
exe.run();
//Trivia triviaGame;
//triviaGame.run();
}
if(menuOption == 2){
std::cout << "\x1B[2J\x1B[H";
cout << "You have chosen to play hangman. You will guess one letter of a secret word at a time until you either guess every\n";
cout << "letter of the word correctly or the entirety of the stick figure has been displayed\n"; 
cout << "(one body part of the stick figure will be displayed for each wrong guess).\n";
cout << "You have to figure out the word in at most 6 guesses to win. You can choose to guess the whole word once, but if you guess incorrectly you lose.\n"; 
cout << "NOTE: the words are all lowercase, so don't waste your guess with an uppercase letter.\n\n";
hangman exe;
}

if(menuOption == 3){
return(0);
}

}while(menuOption != 3);
}