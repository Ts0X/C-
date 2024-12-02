#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void casino() {
    cout << setw(40) << "Welcome to the Casino!" << endl;
    string name;
    double money = 0, moneyagain = 0;

    cout << "What's your name? : ";
    cin >> name;

    do {
        cout << "Enter your starting amount: ";
        cin >> money;
        if (money <= 0) {
            cout << "Invalid amount. Please enter a positive value.\n";
        }
    } while (money <= 0);

    cout << "Hello " << name << ", you have: $" << money << endl;
    
    int choose, numchoose, amountbet, chooseagain, randomNum;

    do {
        if (money <= 0) {
            cout << "You have no money left to play. Please add money or exit.\n";
            break;
        }
        
        cout << setw(35) << "\n!GUESS THE NUMBER!" << endl;
        cout << "1. Bet\n2. Exit\n";
        cin >> choose;

        switch (choose) {
            case 1:
                do {
                    cout << "Enter the amount you want to bet: ";
                    cin >> amountbet;
                    if (amountbet <= 0 || amountbet > money) {
                        cout << "Invalid bet. Your current balance is $" << money << ".\n";
                    }
                } while (amountbet <= 0 || amountbet > money);
                
                cout << "Choose a number between 1-10 to triple your amount: ";
                cin >> numchoose;
                while (numchoose < 1 || numchoose > 10) {
                    cout << "Invalid number. Please choose between 1-10: ";
                    cin >> numchoose;
                }

                srand(time(0));
                randomNum = rand() % 10 + 1;
                cout << "The random number is: " << randomNum << endl;

                if (numchoose == randomNum) {
                    cout << "Congratulations! You guessed it right. Your bet is tripled!\n";
                    money += amountbet * 2;
                } else {
                    cout << "Wrong guess. You lost your bet.\n";
                    money -= amountbet;
                }
                cout << "Your current balance: $" << money << endl;
                break;

            case 2:
                cout << "Exiting the game.\n";
                return;

            default:
                cout << "Invalid input. Please select a valid option.\n";
                break;
        }

    } while (choose != 2 && money > 0);

    if (money <= 0) {
        cout << "You are out of money. Game over.\n";
    }
}

int main() {
    char playAgain;
    do {
        casino();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!\n";
    return 0;
}
