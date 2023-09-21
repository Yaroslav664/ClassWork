#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string ownerName;
    int accountNumber;
    double balance;

public:
    BankAccount(const string& name, int number, double initialBalance) {
        ownerName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " USD into account " << accountNumber << ".\n";
        }
        else {
            cout << "Invalid operation.\n";
        }
    }

    void Withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << " USD from account " << accountNumber << ".\n";
        }
        else {
            cout << "Invalid operation.\n";
        }
    }

    double GetBalance() {
        return balance;
    }

    void DisplayInfo() {
        cout << "Owner's Name: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account1("first", 1001, 1000.0);
    BankAccount account2("second", 1002, 1500.0);

    account1.DisplayInfo();
    account1.Deposit(500.0);
    account1.Withdraw(200.0);
    account1.DisplayInfo();

    account2.DisplayInfo();
    account2.Deposit(1000.0);
    account2.Withdraw(2000.0);
    account2.DisplayInfo();
}
