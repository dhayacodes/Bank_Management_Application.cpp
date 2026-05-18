# Bank_Management_Application.cpp

## Introduction
The Bank Management System is a console-based application developed using C++. The project is designed to simulate basic banking operations such as account creation, deposit, withdrawal, and balance inquiry.

The system uses Object-Oriented Programming (OOP) concepts and file handling to store customer records permanently.

---

## Objectives
- To understand Object-Oriented Programming concepts.
- To implement file handling in C++.
- To simulate basic banking operations.
- To maintain customer records permanently using files.

---

## Features
- Create new bank account
- Deposit money
- Withdraw money
- Balance inquiry
- Display all account details
- Permanent data storage using file handling

---

## Technologies Used
- Language: C++
- Concepts:
  - Classes and Objects
  - Encapsulation
  - File Handling
  - Functions

---

## OOP Concepts Used
### 1. Class and Object
The project uses a `BankAccount` class to represent customer accounts.

### 2. Encapsulation
Account details such as account number, customer name, and balance are stored as private data members.

### 3. Member Functions
Functions are used to perform banking operations like deposit and withdrawal.

---

## File Handling
The project uses:
- `ifstream`
- `ofstream`
- `fstream`

Customer records are stored in:
```text
bank.dat
