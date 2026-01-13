#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "account.h"
#include <fstream>

// Binary file name
const char FILE_NAME[] = "accounts.dat";

// File handling functions
int getNextAccountNumber();
bool findAccount(int accNo, Account &acc, std::streampos &pos);
void updateAccount(const Account &acc, std::streampos pos);
void deleteAccount(int accNo);

#endif
