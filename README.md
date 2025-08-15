# Bank Management System (C++)

A console-based Bank Management System developed as a 3rd semester Diploma project.  
It allows users to create accounts, perform transactions, and store all data in files for persistence.

## Features

- **Account Creation**: Create a new bank account with unique account number
- **Deposit / Withdraw**: Perform money transactions securely
- **Balance Inquiry**: View current balance for any account
- **Transaction History**: Each account has its own file storing all transaction details
- **Account List**: Separate file storing all account numbers for quick access
- **Persistent Storage**: All data is saved to `.txt` files for future use

## How It Works

1. The system stores all account numbers in a single file (`accounts.txt`)
2. Each account has its own file (`account_<accountNo>.txt`) containing:
   - Account holder details
   - All deposit and withdrawal transactions

## How to Run

1. Use any C++11+ compiler (g++, Visual Studio, Code::Blocks, etc.)
2. Compile and run:

```bash
g++ main.cpp -o BankManagement
./BankManagement
