#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;

// Procedural approach
bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance >= fare &&
           balance - fare >= MIN_BALANCE;
}

// Object-oriented approach
class SmartCard {
private:
    long long balance;

public:
    explicit SmartCard(long long initialBalance)
        : balance(initialBalance) {}

    bool canTravel(long long fare) const {
        return fare >= 0 && balance >= fare &&
               balance - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare))
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

int main() {
    long long proceduralBalance = 10000;
    long long fare = 3000;

    cout << "Procedural approach\n";
    if (proceduralCanTravel(proceduralBalance, fare)) {
        proceduralBalance -= fare;
        cout << "Journey approved\n";
    } else {
        cout << "Journey denied\n";
    }
    cout << "Balance: " << proceduralBalance << " paise\n";

    cout << "\nObject-oriented approach\n";
    SmartCard card(10000);

    if (card.deduct(fare))
        cout << "Journey approved\n";
    else
        cout << "Journey denied\n";

    cout << "Balance: " << card.getBalance() << " paise\n";
    return 0;
}