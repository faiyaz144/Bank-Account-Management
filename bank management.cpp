#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;

public:
    Account(string accNum, string holderName)
        : accountNumber(accNum), accountHolderName(holderName) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayAccountInfo() const = 0;
};

class SavingsAccount : public Account {
private:
    double balance;
    double interestRate;

public:
    SavingsAccount(string accNum, string holderName, double initialBalance, double rate)
        : Account(accNum, holderName), balance(initialBalance), interestRate(rate) {}

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    void displayAccountInfo() const override {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Holder: " << getAccountHolderName() << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    // Create a SavingsAccount object
    SavingsAccount myAccount("1234567890", "John Doe", 1000.0, 2.5);

    int choice;
    do {
        cout << "\nBank Account Management System" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Account Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
//mypart
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

    return 0;
}
