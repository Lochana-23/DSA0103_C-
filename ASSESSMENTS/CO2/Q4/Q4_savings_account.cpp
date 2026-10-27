#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    long long balance;
    long long transactions[10];
    int count;

    void record(long long amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 1; i < 10; ++i)
                transactions[i - 1] = transactions[i];
            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(const string& number, long long openingBalance)
        : accountNumber(number), balance(openingBalance), transactions{}, count(0) {}

    void deposit(long long amount) {
        if (amount <= 0) return;
        balance += amount;
        record(amount);
    }

    bool withdraw(long long amount);

    void miniStatement() const {
        cout << "Account: " << accountNumber << "\nBalance: " << balance << '\n';
        cout << "Recent transactions (oldest to newest):\n";
        for (int i = 0; i < count; ++i) cout << transactions[i] << '\n';
    }
};

bool SavingsAccount::withdraw(long long amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    record(-amount);
    return true;
}

int main() {
    SavingsAccount account("SB1001", 1000);
    account.deposit(100);
    account.withdraw(50);
    for (int i = 0; i < 10; ++i) account.deposit(10);
    account.miniStatement();
}