#include <iostream>
#include <fstream>
#include "account.h"
#include "file_utils.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n---- BANK MANAGEMENT SYSTEM ----";
        cout << "\n1. Create Account";
        cout << "\n2. Login";
        cout << "\n3. Close Account";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            Account acc;
            int accNo = getNextAccountNumber();
            acc.createAccount(accNo);
            ofstream out(FILE_NAME, ios::binary | ios::app);
            out.write((char*)&acc, sizeof(acc));
            out.close();
            cout << "\nAccount Created Successfully!";
            cout << "\nYour Account Number is: " << accNo << endl;
        }

        else if (choice == 2) {
            int accNo;
            char pass[20];
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Password: ";
            cin >> pass;
            Account acc;
            streampos pos;
            if (!findAccount(accNo, acc, pos) || !acc.authenticate(pass)) {
                cout << "\nInvalid Account Number or Password\n";
                continue;
            }
            
            int option;
            do {
                cout << "\n---- ACCOUNT MENU ----";
                cout << "\n1. Deposit";
                cout << "\n2. Withdraw";
                cout << "\n3. View Account";
                cout << "\n4. Logout";
                cout << "\nEnter option: ";
                cin >> option;
                if (option == 1) {
                    double amt;
                    cout << "Enter amount: ";
                    cin >> amt;
                    acc.deposit(amt);
                    updateAccount(acc, pos);
                    cout << "Amount Deposited\n";
                }

                else if (option == 2) {
                    double amt;
                    cout << "Enter amount: ";
                    cin >> amt;

                    if (!acc.withdraw(amt)) {
                        cout << "Insufficient Balance\n";
                    }
                        
                    else {
                        updateAccount(acc, pos);
                        cout << "Amount Withdrawn\n";
                    }
                }

                else if (option == 3) {
                    acc.display();
                }
            } while (option != 4);
        }

        else if (choice == 3) {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;
            Account acc;
            streampos pos;

            if (!findAccount(accNo, acc, pos)) {
                cout << "Account Not Found\n";
            }
                
            else if (acc.getBalance() != 0) {
                cout << "Account balance must be zero to close account\n";
            }
                
            else {
                deleteAccount(accNo);
                cout << "Account Closed Successfully\n";
            }
        }
    } while (choice != 4);
    cout << "\nThank you for using the system.\n";
    return 0;
}
