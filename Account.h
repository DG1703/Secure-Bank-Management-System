#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    int accountNumber;
    char name[50];
    char password[20];
    double balance;
public:
    // Account creation & authentication
    void createAccount(int accNo);
    bool authenticate(const char* pass) const;

    // Transactions
    void deposit(double amount);
    bool withdraw(double amount);

    // Display
    void display() const;

    // Getters
    int getAccountNumber() const;
    double getBalance() const;

    // Setter (used internally by file logic)
    void setBalance(double amount);
};
#endif
