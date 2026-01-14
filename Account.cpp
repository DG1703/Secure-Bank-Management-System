#include "account.h"
#include <iostream>
#include <cstring>
using namespace std;

// Create a new account
void Account::createAccount(int accNo) {
    accountNumber = accNo;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Set Password: ";
    cin.getline(password, 20);
    cout << "Enter Initial Balance: ";
    cin >> balance;
}

// Authenticate user password
bool Account::authenticate(const char* pass) const {
    return strcmp(password, pass) == 0;
}

// Deposit money
void Account::deposit(double amount) {
    balance += amount;
}

// Withdraw money with balance check
bool Account::withdraw(double amount) {
    if (amount > balance)
    {return false;}
    balance -= amount;
    return true;
}

// Display account details
void Account::display() const {
    cout << "\nAccount Number : " << accountNumber;
    cout << "\nAccount Holder: " << name;
    cout << "\nBalance        : " << balance << endl;
}

// Getter for account number
int Account::getAccountNumber() const {
    return accountNumber;
}

// Getter for balance
double Account::getBalance() const {
    return balance;
}

// Setter for balance
void Account::setBalance(double amount) {
    balance = amount;
}
