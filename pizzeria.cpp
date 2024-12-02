#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double totalCost = 0.0;

    double margarita = 7.00;
    double prosciutto = 8.00;
    double calabrese = 8.50;
    double carbonara = 8.00;
    double alacrem = 8.00;
    double water = 0.50;
    double coca = 2.00;

    int order;
    char somethingElse;
    bool validInput;

    do {
        cout << setw(20) << "--- Welcome to My Pizzeria ---" << endl;
        cout << setw(15) << "-! Menu !-" << endl;
        cout << "1.\tPizza Margarita\t\t$7.00" << endl;
        cout << "2.\tPizza Prosciutto\t$8.00" << endl;
        cout << "3.\tPizza Calabrese\t\t$8.50" << endl;
        cout << "4.\tSpaghetti Carbonara\t$8.00" << endl;
        cout << "5.\tSpaghetti Ala Crem\t$8.00" << endl;
        cout << "6.\tWater\t\t\t$0.50" << endl;
        cout << "7.\tCoca-Cola 0.5L\t\t$2.00" << endl;
        cout << "8.\tExit" << endl;

        cout << "Select your order (1-8): ";
        cin >> order;

        switch (order) {
            case 1:
                cout << "You chose Pizza Margarita." << endl;
                totalCost += margarita;
                break;
            case 2:
                cout << "You chose Pizza Prosciutto." << endl;
                totalCost += prosciutto;
                break;
            case 3:
                cout << "You chose Pizza Calabrese." << endl;
                totalCost += calabrese;
                break;
            case 4:
                cout << "You chose Spaghetti Carbonara." << endl;
                totalCost += carbonara;
                break;
            case 5:
                cout << "You chose Spaghetti Ala Crem." << endl;
                totalCost += alacrem;
                break;
            case 6:
                cout << "You chose Water." << endl;
                totalCost += water;
                break;
            case 7:
                cout << "You chose Coca-Cola." << endl;
                totalCost += coca;
                break;
            case 8:
                cout << "Exiting the menu..." << endl;
                break;
            default:
                cout << "Invalid selection. Please choose a valid option." << endl;
                continue;
        }

        cout << "Your current total cost: $" << fixed << setprecision(2) << totalCost << endl;
        
        if (order != 8) {
            do {
                cout << "Do you want to order something else? (y/n): ";
                cin >> somethingElse;
                validInput = (somethingElse == 'y' || somethingElse == 'n');
                if (!validInput) cout << "Invalid input. Please enter 'y' or 'n'.\n";
            } while (!validInput);
        }

    } while (order != 8 && somethingElse != 'n');

    double cash, cardBalance = 50.00;
    int paymentChoice;

    do {
        cout << "How would you like to pay?\n1. Cash\n2. Card\n";
        cin >> paymentChoice;
    } while (paymentChoice != 1 && paymentChoice != 2);

    if (paymentChoice == 1) {
        cout << "Enter cash amount: ";
        cin >> cash;
        if (cash >= totalCost) {
            cout << "Payment successful! Your change: $" << cash - totalCost << endl;
        } else {
            cout << "Not enough cash. Payment failed.\n";
        }
    } else {
        string cardUsername;
        int cardCode;
        
        cout << "Enter card username: ";
        cin >> cardUsername;
        cout << "Enter card code: ";
        cin >> cardCode;
        
        if (cardBalance >= totalCost) {
            cout << "Payment successful! Your remaining balance: $" << cardBalance - totalCost << endl;
        } else {
            cout << "Not enough funds on the card. Payment failed.\n";
        }
    }

    cout << "------------ Goodbye! ------------" << endl;

    return 0;
}
