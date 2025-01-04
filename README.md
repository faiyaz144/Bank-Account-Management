# Bank Account Management - C++ Project.




## Overview
 The code utilizes the OOP paradigm by defining a BankAccount class. This class encapsulates data (account number, holder name, balance) and operations (deposit, withdrawal, display information) related to a bank account.
## Features

- Deposit: The deposit() method allows you to add funds to the account balance.
- Withdrawal: The getBalance() method provides a way to retrieve the current balance of the account.
- Account Information Display: The displayAccountInfo() method displays the account number, holder name, and current balance to the console.



## Key OOP Concepts Demonstrated:
- Inheritance: SavingsAccount inherits from the Account class, inheriting common properties and methods.
- polymorphism: The use of virtual functions allows objects of SavingsAccount to be treated as objects of the base class Account where necessary.
- Abstraction: The Account class provides an abstract representation of an account, hiding the specific implementation details of each account type.
## Installation


    
## Prerequisites

- C++ Compiler (e.g., GCC, Clang)
- ext Editor/IDE (e.g., Visual Studio Code, Code::Blocks, or Eclipse)


## Steps to Set Up

1. Clone or download the repository to your local machine.
2. Open the project in your preferred IDE or text editor.
3. Compile the C++ source code using the appropriate compiler command.
4. Run the compiled program


## Code Structure

- Base Class: An abstract Account class with common attributes and pure virtual functions.
- Derived Classes: Specific account types like SavingsAccount inherit from the Account class and provide their own implementations for the virtual functions.
- Flexibility: This structure allows you to easily add new account types (e.g., CurrentAccount, CheckingAccount) by creating new derived classes.
This approach promotes code reusability, maintainability, and extensibility, which are key principles of object-oriented programming.
## Usage


## Menu option
Once the program is executed, the following options will be presented to the user:

1. Deposit: This option allows the user to deposit a specific amount into the bank account.
2. Withdraw: This option allows the user to withdraw a specific amount from the bank account.
3. Display Account Information: This option displays the account number, account holder name, and current balance of the account.
4. Exit: This option allows the user to exit the program.

- The user is presented with these options in the main function, and the program then executes the corresponding action based on the user's choice.

