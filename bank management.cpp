#include <iostream>
#include <string>

using namespace std;

// Base Class: BankAccount
class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNum, string holderName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = holderName;
        balance = initialBalance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived Class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string holderName, double initialBalance, double rate) 
        : BankAccount(accNum, holderName, initialBalance) {
        interestRate = rate;
    }

    void calculateInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Interest calculated. New balance: " << balance << endl;
    }
};

int main() {
    // Sample account details
    SavingsAccount myAccount("1234567890", "mahir", 10000.0, 0.05); 

    string enteredAccountNumber;
    string enteredAccountHolder;

    cout << "***** LOGIN *****" << endl;
    cout << "Enter Account Number: ";
    cin >> enteredAccountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore(); // Clear newline character
    getline(cin, enteredAccountHolder);

    // Login check
    if (enteredAccountNumber == myAccount.getAccountNumber() && 
        enteredAccountHolder == myAccount.getAccountHolderName()) {
        cout << "Login Successful!" << endl;

        int choice;
        do {
            cout << "\nBank Account Management System" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Display Account Information" << endl;
            cout << "4. Calculate Interest" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    double amount;
                    cout << "Enter Deposit Amount: ";
                    cin >> amount;
                    myAccount.deposit(amount);
                    break;
                }
                case 2: {
                    double amount;
                    cout << "Enter Withdrawal Amount: ";
                    cin >> amount;
                    myAccount.withdraw(amount);
                    break;
                }
                case 3: {
                    myAccount.displayAccountInfo();
                    break;
                }
                case 4: {
                    myAccount.calculateInterest();
                    break;
                }
                case 5: {
                    cout << "Exiting..." << endl;
                    break;
                }
                default: {
                    cout << "Invalid choice." << endl;
                }
            }
        } while (choice != 5);
    } else {
        cout << "Login Failed. Incorrect account details." << endl;
    }

    return 0;
}
