#include <iostream>
#include "tictacto.h"
using namespace std;
bool flag1 = false;
bool flag2 = false;


void tictacto::Board()
{
    cout << "1   2   3" << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if(j == 0)
            {
                cout << " | ";
            }
            if(j == 1)
            {
                cout << " | ";
            }
            if(j == 2)
            {
                cout << "  " << i + 1 << endl;
            }
        }
        if(i == 0)
        {
            cout << "----------" << endl;
        }
        if(i == 1)
        {
            cout << "----------" << endl;
        }
    }
    cout << endl;
}

void tictacto::player1()
{
    int row1;
    int col1;
    for( ; ; )
    {
        cout << "Enter a row: ";
        if(cin >> row1)
        {               
            break;
        }                 
        else                 
        {
            cin.clear();
            cin.ignore();         
            cout << "Invalid input, please enter again!" << endl;
            row1 = 0;          
        }      
    }

    for( ; ; )
    {
        cout << "Enter a col: ";
        if(cin >> col1 && col1 >= 1 && col1 <= 3)
        {                     
            break;
        }                 
        else                 
        {
            cin.clear();
            cin.ignore();         
            cout << "Invalid input, please enter again!" << endl;
            col1 = 0;          
        }
          
    }
 
    
    while(board[row1 - 1][col1 - 1] != ' ')
    {
        cout << "Invalid input, please enter again!" << endl;
        cout << "Enter a row: ";
        cin >> row1;
        cout << "Enter a col: ";
        cin >> col1;
    }
    board[row1 - 1][col1 - 1] = 'O';
}

void tictacto::player2()
{
    int row2;
    int col2;
    for( ; ; )
    {
        cout << "Enter a row: ";
        if(cin >> row2)
        {                       
            break;
        }                 
        else                 
        {
            cin.clear();
            cin.ignore();         
            cout << "Invalid input, please enter again!" << endl;
            row2 = 0;          
        }      
    }

    for( ; ; )
    {
        cout << "Enter a col: ";
        if(cin >> col2 && col2 >= 1 && col2 <= 3)
        {                     
            break;
        }                 
        else                 
        {
            cin.clear();
            cin.ignore();         
            cout << "Invalid input, please enter again!" << endl;
            col2 = 0;          
        }
          
    }  

    while(board[row2 - 1][col2 - 1] != ' ')
    {
        cout << "Enter a row: ";
        cin >> row2;
        cout << "Enter a col: ";
        cin >> col2;
    }
    board[row2 - 1][col2 - 1] = 'X';
}

void tictacto::winningcondition()
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            if(board[i][0] == 'O')
            {
                flag1 = true;
            }
            else
            {
                flag2 = true;
            }
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
        {
            if(board[0][i] == 'O')
            {
                flag1 = true;
            }
            else
            {
                flag2 = true;
            }
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == board[2][0] && board[2][0] != ' ')
        {
            if(board[1][1] == 'O')
            {
                flag1 = true;
            }
            else
            {
                flag2 = true;
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == board[2][2] && board[0][0] != ' ')
        {
            if(board[1][1] == 'O')
            {
                flag1 = true;
            }
            else
            {
                flag2 = true;
            }
        }
    }
}


void tictacto::begin()
{
    int num = 0;
    bool flag = false;
    while(num < 9 && flag1 == false && flag2 == false)
    {
        if(flag == false)
        {
            cout << "It's player1's turn now!" << endl;
            player1();
            flag = true;
        }
        else
        {
            cout << "It's player2's turn now!" << endl;
            player2();
            flag = false;
        }
        winningcondition();
        Board();
        num = num + 1;
    }
}

void tictacto::run()
{
    Board();
    begin();
    if(flag1 == true)
    {
        cout << "player1 wins!" << endl;
        flag1 = false;
    }
    else if(flag2 == true)
    {
        cout << "player2 wins!" << endl;
        flag2 = false;
    }
    else if(flag1 == flag2)
    {
        cout << "No one wins!" << endl;
    }

}
