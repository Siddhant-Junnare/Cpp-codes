#include<iostream>
#include<cstdlib>
using namespace std;

void RockPaperScissor()
{
    do
    {
        cout << "\n------- Rock Paper Scissor --------\n";
        cout << "1. Rock" << endl;
        cout << "2. Paper"<< endl;
        cout << "3. Scissor" << endl;
        cout << "4. Quit" << endl;

        int userChoice;
        cout << "Enter your choice : ";
        label1:
        cin >> userChoice;

        if(userChoice == 4)
        {
            char ch;
            cout << "Are you sure you want to quit? (y/n) : ";
            cin >> ch;

            if(ch == 'y' || ch == 'Y')
                return;
            cout << "Enter your choice : ";
            goto label1;
        }    

        if (userChoice < 1 || userChoice > 4)
        {
            cout << "Please, enter a valid choice : ";
            goto label1;
        }    
        
        int computerChoice = (rand() % 3) + 1;
        
        if(userChoice == computerChoice)
            cout << "Draw" << endl;
        else if(userChoice == 1 && computerChoice == 3)
            cout << "You win!" << endl;
        else if(userChoice == 2 && computerChoice == 1)
            cout << "You win!" << endl;
        else if(userChoice == 3 && computerChoice == 2)
            cout << "You win!" << endl;
        else
            cout << "Computer Wins" << endl;

    } while (1);
}

int main()
{
    RockPaperScissor();
    return 0;
}