#include <iostream>
#include <string>
using namespace std;


int main() {
    int pin = 1234;
    int enteredPin, transaction, amount;
    int balance = 100;
    bool loggedIn = false;
    string enterToContinue; ; // empty variable para para sa click to continue…



    while(enteredPin != 1234) {//Loop infinitely
        cout << "\033[2J\033[H";
        cout << "Enter your 4-digit pincode:\n ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            loggedIn = true;
            cout << "\033[2J\033[H"; // to ano move the terminal screen
            cout << "\nWelcome to ATM\n";
             // ATM Menu Loop
        while (loggedIn) {
            cout << "\nSelect Transaction\n\n";
            cout << "1. Withdraw\n";
            cout << "2. Deposit\n";
            cout << "3. Inquire Balance\n";
            cout << "4. Logoff\n";
            cout << "\nEnter Transaction: ";
            cin >> transaction;

            switch (transaction) {
            case 1: // Withdraw
                cout << "\033[2J\033[H";
                cout << "\nEnter amount to withdraw: \n";
                cin >> amount;
                if (amount <= balance && amount >= 500) {
                    balance -= amount;
                    cout << "\nTransaction Successful\n";
                    cout << "\nReceipt:\n";
                    cout << "=====================================\n";
                    cout << "Transaction: Withdrawal\n";
                    cout << "Amount: " << amount << "\n";
                    cout << "Remaining Balance: " << balance << "\n";
                    cout << "=====================================\n";
                    cout << "\nPress enter to continue...";
                    cin.ignore(); // para gumana ang getline
                    getline(cin, enterToContinue); // para pag enter move na
                    cout << "\033[2J\033[H"; // to ano move the terminal screen
                } else if (amount < 500 && amount <= balance){
                    cout << "\nTransaction failed \nMinimun withdrawal amount is: 500 ";
                    cout << "\n\nPress enter to continue...";
                    cin.ignore();
                    getline(cin, enterToContinue);
                    cout << "\033[2J\033[H";

                } else {
                    cout << "\033[2J\033[H";
                    cout << "\nTransaction Failed! \nYou don't have enough balance\n";
                    cout << "\nPress enter to continue...";
                    cin.ignore();
                    getline(cin, enterToContinue);
                    cout << "\033[2J\033[H";
                }
                break;

            case 2: // Deposit
                cout << "\033[2J\033[H";
                cout << "\nEnter amount to deposit: \n";
                cin >> amount;
                balance += amount;
                cout << "\nTransaction Successful\n";
                cout << "\nReceipt:\n";
                cout << "=====================================\n";
                cout << "Transaction: Deposit\n";
                cout << "Amount: " << amount << "\n";
                cout << "Remaining Balance: " << balance << "\n";
                cout << "=====================================\n";
                cout << "\nPress enter to continue...";
                    cin.ignore();
                    getline(cin, enterToContinue);
                    cout << "\033[2J\033[H";
                break;

            case 3: // Inquire Balance
                cout << "\033[2J\033[H";
                cout << "\nReceipt:\n";
                cout << "=====================================\n";
                cout << "Transaction: Inquire Balance\n";
                cout << "Remaining Balance: " << balance << "\n";
                cout << "=====================================\n";
                cout << "\nPress enter to continue...";
                    cin.ignore();
                    getline(cin, enterToContinue);
                    cout << "\033[2J\033[H";
                break;

            case 4: // Logoff
                cout << "\033[2J\033[H";
                cout << "\nLogged out\n";
                cout << "Press enter to continue...";
                cin.ignore();
                getline(cin, enterToContinue);
                loggedIn = false;
                break;

            default: // If the number entered is wrong
                cout << "\033[2J\033[H";
                cout << "Invalid transaction. Please try again.\n";
                cout << "\nPress enter to continue...";
                    cin.ignore();
                    getline(cin, enterToContinue);
                    cout << "\033[2J\033[H";
            }
        }
        } else { // if the pin code is wrong
            cout << "\nWrong pin code\n\n" ;
            cout << "\nPress enter to continue...";
                    cin.ignore();
                    getline(cin, enterToContinue);
            
        }

       
    }
    return 0;
}