//hangman.cpp
#include "hangman.h"
#include <string>
#include <cstdlib>
#include <time.h>
#include <ctime>

string hangman::randomlyGenerateWord(){
std::string arr[10];
  for (int i=0; i<10; i++)
  {
    if (i==0)
    {arr[i]="computer";}
    else if (i==1) 
    {arr[i]="software";}
    else if (i==2) 
    {arr[i]="boolean";}
    else if (i==3)
    {arr[i]="programming";}
    else if (i==4)
    {arr[i]="debug";}
    else if (i==5)
    {arr[i]="cybersecurity";}
    else if (i==6)
    {arr[i]="hardware";}
    else if (i==7) 
    {arr[i]="pointer";}
    else if (i==8) 
    {arr[i]="array";}
    else
    { arr[i]="memory";}
  }
  srand(time(NULL));
  int num = rand()%9;
  return arr[num];
}

bool hangman::funcForWrongGuess(int numGuesses){
if (numGuesses<=5)
  {
    return false;
  }
  else 
  {
    return true;
  }

}

void hangman::displayStickFigure(int numGuesses){
if (numGuesses==0)
  {

  }
  else if (numGuesses==1)
  {
    std::cout<< "O\n";
  }
  else if (numGuesses==2)
  {
    std::cout << "O\n|\n";
  }
  else if (numGuesses==3)
  {
    std::cout << " " << "O\n" << "\\" << "|" << "\n";
  }
  else if (numGuesses==4)
  {
    std::cout << " " << "O\n" << "\\" << "|" << "/" << "\n";
  }
  else if (numGuesses==5)
  {
    std::cout << " " << "O\n" << "\\" << "|" << "/" << "\n" << " /\n";
  }
  else
  {
    std::cout << " " << "O\n" << "\\" << "|" << "/" << "\n" << " /\\\n";
  }

}

hangman::hangman(){
int ans;
//bool bad = false;
  long long unsigned int count =0;
  bool flag = false;
  bool displayFlag = true;
  std::string str = randomlyGenerateWord();
  char* arr = new char [str.length()];
  std::string guessed = "";
  std::string wrongGuessed = "";
  bool wrongGuess=false;
  bool flagForAnotherGuess = false;
  for (long long unsigned int i=0; i<str.length(); i++)
  {
    arr[i]='_';
  }
  
      //bad=false;
 do{
   //  bool bad = false;
     std::cout << "Would you like to guess the whole word, note: you can only guess the whole word once and if its incorrect you lose (1) or a letter of the word (2): ";
     std::cin>>ans;
     //bad = std::cin.fail();
if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    displayFlag=false;
    flag=true;
}
  if (ans==1)
  {
    std::string guess;
    std::cout << "Input your guess of what the word is: ";
    std::cin>>guess;
    if (guess==str)
    {
      flag=true;
      displayFlag=false;
      std::cout << "You win\n";
    }
    else
    {
      flag=true;
      displayFlag=false;
      std::cout << "You lose\n";
    }

  }
  else if (ans==2)
  {
    wrongGuess=false;
    char guess;
    do {
    flagForAnotherGuess=false;
    std::cout << "Please input your guess of a letter contained in the word: ";
    std::cin >> guess;
    for (long long unsigned int i=0; i<guessed.length(); i++)
    {
      if (guess == guessed[i])
      {
        flagForAnotherGuess = true;
      }
    } } while (flagForAnotherGuess==true);
    for (long long unsigned int i=0; i<str.length(); i++)
    {
      if (guess==str[i])
      {
        arr[i]=str[i];
        count++;
        wrongGuess=true;
      }
    }
    if (wrongGuess==false)
    {
      wrongGuessed=wrongGuessed+guess;
      flag = funcForWrongGuess(wrongGuessed.length());
      if (flag==true)
      {
        std::cout << "You lose\n";
        displayFlag=false;
      }
    }
    guessed=guessed+guess;
    if (count == str.length())
    {
      flag=true;
      displayFlag=false;
      std::cout<<"You win!\n";
    }

  }
  else 
  {
    std::cout << "Not a valid input\n";
  }
  if (displayFlag==true)
  {
    displayStickFigure(wrongGuessed.length());
  for (long long unsigned int i=0; i<str.length(); i++)
  {
    std::cout<<arr[i];
  }
  std::cout<<"\nList of Guesses\n";
  for (long long unsigned int i=0; i<guessed.length(); i++)
  {
    std::cout << guessed[i] << " ";
  }
  std::cout<<"\n";
  }
  }while ((ans!=1 || ans!=2) && flag==false);

delete[] arr;  
}
