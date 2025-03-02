# ATM System in C++

## Overview
This project is a simple **ATM (Automated Teller Machine) System** implemented in C++. It simulates basic banking functionalities, including account creation, deposits, withdrawals, and balance inquiries. The system interacts with users through a command-line interface and manages multiple accounts.

## Features
- **User Authentication**: Users log in using an **8-character account ID** and a **4-digit PIN**.
- **Deposit & Withdrawal**: Allows users to deposit and withdraw funds while ensuring sufficient balance.
- **Balance Inquiry**: Users can check their current account balance.
- **Multiple Account Management**: The bank system supports multiple accounts stored in a file.
- **Data Loading from File**: The system reads account details from a file.

## File Structure

## Classes and Responsibilities
1. **Account (`Account.h`, `Account.cpp`)**
   - Stores account information (ID, PIN, balance).
   - Provides methods for deposit, withdrawal, and balance check.

2. **Bank (`Bank.h`, `Bank.cpp`)**
   - Manages multiple accounts.
   - Loads accounts from a file.
   - Finds an account based on ID and PIN.

3. **ATM (`Atm.h`, `Atm.cpp`)**
   - Provides the user interface for interacting with the system.
   - Handles login, transactions, and account verification.

4. **Main Program (`prog2.cpp`)**
   - Initializes the system.
   - Loads accounts from a file.
   - Starts the ATM interface.

