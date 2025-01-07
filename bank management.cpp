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

int main() {
    // Sample account details (for demonstration purposes)
    BankAccount myAccount("1234567890", "mahir", 20000.0);

    string enteredAccountNumber;
    string enteredAccountHolder;
    cout << "***** LOGIN *****"<<endl;
    cout << "Enter Account Number: ";
    cin >> enteredAccountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore(); // Clear newline character
    getline(cin, enteredAccountHolder);

    // Simple login check (replace with more secure methods)
    if (enteredAccountNumber == myAccount.getAccountNumber() &&
        enteredAccountHolder == myAccount.getAccountHolderName()) {
        cout << "Login Successful!" << endl;

        int choice;
        do {
            cout << "\nBank Account Management System" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Display Account Information" << endl;
            cout << "4. Exit" << endl;
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
                case 4:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
            }
        } while (choice != 4);
    } else {
        cout << "Login Failed. Incorrect account details." << endl;
    }

    return 0;
}

