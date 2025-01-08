#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, string holderName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = holderName;
        balance = initialBalance;
    }

    // Getters
    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    // Deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    // Display Account Information
    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class
class SavingsAccount : public BankAccount {
private:
    double interestRate; // Interest rate as a percentage

public:
    // Constructor
    SavingsAccount(string accNum, string holderName, double initialBalance, double rate)
        : BankAccount(accNum, holderName, initialBalance), interestRate(rate) {}

    // Method to calculate interest
    void calculateInterest() const {
        double interest = (getBalance() * interestRate) / 100;
        cout << "Interest earned: " << interest << endl;
    }

    // Override displayAccountInfo to include interest rate
    void displayAccountInfo() const {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    // Sample account details
    SavingsAccount mySavings("1234567890", "mahir", 1000.0, 3.5);

    string enteredAccountNumber;
    string enteredAccountHolder;
    cout << "***** LOGIN *****" << endl;
    cout << "Enter Account Number: ";
    cin >> enteredAccountNumber;
    cout << "Enter Account Holder Name: ";
   cout << "Enter Account Holder Name: ";
   cin >> enteredAccountHolder;

    if (enteredAccountNumber == mySavings.getAccountNumber() &&
        enteredAccountHolder == mySavings.getAccountHolderName()) {
        cout << "Login Successful!" << endl;

        int choice;
        do {
            cout << "\nSavings Account Management System" << endl;
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
                    mySavings.deposit(amount);
                    break;
                }
                case 2: {
                    double amount;
                    cout << "Enter Withdrawal Amount: ";
                    cin >> amount;
                    mySavings.withdraw(amount);
                    break;
                }
                case 3: {
                    mySavings.displayAccountInfo();
                    break;
                }
                case 4: {
                    mySavings.calculateInterest();
                    break;
                }
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
            }
        } while (choice != 5);
    } else {
        cout << "Login Failed. Incorrect account details." << endl;
    }

    return 0;
}
