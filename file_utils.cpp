#include "file_utils.h"
#include <iostream>
#include <cstdio>
using namespace std;

// Generate next account number
int getNextAccountNumber() {
    ifstream in(FILE_NAME, ios::binary);
    int count = 0;
    Account acc;

    while (in.read((char*)&acc, sizeof(acc))) {
        count++;
    }
    in.close();
    return 1001 + count;
}

// Find account and return its file position
bool findAccount(int accNo, Account &acc, streampos &pos) {
    fstream file(FILE_NAME, ios::in | ios::binary);

    while (file.read((char*)&acc, sizeof(acc))) {
        if (acc.getAccountNumber() == accNo) {
            pos = file.tellg() - static_cast<streampos>(sizeof(acc));
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Update account record in-place
void updateAccount(const Account &acc, streampos pos) {
    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);
    file.seekp(pos);
    file.write((char*)&acc, sizeof(acc));
    file.close();
}

// Delete account safely using temp file
void deleteAccount(int accNo) {
    ifstream in(FILE_NAME, ios::binary);
    ofstream out("temp.dat", ios::binary);
    Account acc;

    while (in.read((char*)&acc, sizeof(acc))) {
        if (acc.getAccountNumber() != accNo) {
            out.write((char*)&acc, sizeof(acc));
        }
    }
    in.close();
    out.close();
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);
}
