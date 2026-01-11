# Secure Bank Management System
A console-based Secure Bank Management System developed in C++ using binary file handling. This project simulates basic banking operations with persistent data storage and simple authentication.

# Project Overview
The Secure Bank Management System allows users to create and manage bank accounts securely through a menu-driven command-line interface. All account data is stored in a binary file, ensuring that information is preserved even after the program terminates. This project is developed as part of the Foundation C/C++ Programming Track to demonstrate understanding of file handling, structured programming, and transaction logic.

# Features
- Create a new bank account
- Secure login using account number and password
- Deposit money
- Withdraw money with overdraft protection
- Transfer funds between accounts
- View account details
- Close account (only if balance is zero)
- Persistent storage using binary files
  
# Technologies Used
- Language: C++
- Concepts Used:
  - Binary File Handling
  - Classes and Objects
  - File Pointer Manipulation
  - Menu-driven Program
  - Data Persistence

# Project Structure
  |
  |->Secure-Bank-Management-System
  |->main.cpp → Program entry point and menu handling
  |->Account.h → Account class declaration
  |->Account.cpp → Account class implementation
  |->README.md → Project documentation

# How to Compile and Run
- Using g++:
  g++ main.cpp Account.cpp -o bank
  ./bank
- Using Code::Blocks:
  - Create a new console application project
  - Add main.cpp, Account.h, and Account.cpp
  - Build and run the project

# Data Storage
- Account data is stored in a binary file named accounts.dat
- The file is created automatically when the program runs
- Data remains persistent across multiple executions

# Developer
  Divya Garg
Author

Divya Garg
