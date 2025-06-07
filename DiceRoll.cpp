#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>

using namespace std;

int main()
{
    srand(time(0));
    char ch;
    
    do
    {
        // user rolls dice
        cout << "Press any key to roll the dice" << endl;
        _getch();
        cout << "Rolling.";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << "." << endl;

        int userRoll = (rand() % 6) + 1;
        cout << "You rolled : " << userRoll << endl;

        //computer rolls dice
        cout << "Computer is rolling a dice.";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << "." << endl;

        int computerRoll = (rand() % 6) + 1;
        cout << "Computer rolled : " << computerRoll << endl;

        if(userRoll == computerRoll)
            cout << "Draw" << endl;
        else if(userRoll > computerRoll)
            cout << "You win" << endl;
        else
            cout << "You lose" << endl;

        cout << "Do you want to continue? (y/n) : ";
        cin >> ch;
        ch = tolower(ch);

    } while (ch == 'y');
    
}