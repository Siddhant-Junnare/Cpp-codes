#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<numeric>
#include<windows.h>
using namespace std;

int main()
{
    srand(time(0));

    int arr[6] = {0};
    char ch;
    do
    {
        // rolling dice simulation
        cout << "Press any key to roll the dice\n\n " ;
        _getch();
        cout << "Rolling.";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";


        
        // rolling two dice simultaneously
        int firstDice = (rand() % 6) + 1;
        
        int secondDice = (rand() % 6) + 1;
        
        cout << endl << endl << "You rolled a " << firstDice << " and a " << secondDice << endl;
        cout << "Total : " << firstDice + secondDice << endl;

        arr[firstDice - 1]++;
        arr[secondDice - 1]++;

        cout << "Do you want to roll more(y/n) : ";
        
        cin >> ch;
        ch = tolower(ch);
    } while (ch == 'y');
    
    for(int i = 0 ; i < 6 ; i++)
        if (arr[i])
            cout << "You rolled " << i + 1 << " " <<arr[i] << " times" << endl;

    int totalRolls = accumulate(arr, arr + (sizeof(arr)/sizeof(int)), 0);
    cout << "Total rolls : " << totalRolls << endl;
}