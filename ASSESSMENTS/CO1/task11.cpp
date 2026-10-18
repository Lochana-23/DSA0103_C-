#include <iostream>
using namespace std;

enum class Zone { Inner = 1, Middle, Outer };

constexpr long long BASE_FARE[] = {0, 1000, 2000, 3000};
constexpr int SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE = 5000;

long long calculateFare(Zone zone, bool peak) {
    int index = static_cast<int>(zone);

    if (index < 1 || index > 3)
        return -1;

    long long fare = BASE_FARE[index];

    if (peak)
        fare += fare * SURCHARGE_PERCENT / 100;

    return fare;
}

class SmartCard {
private:
    long long balance;

public:
    explicit SmartCard(long long initialBalance)
        : balance(initialBalance) {}

    bool deduct(long long fare) {
        if (fare < 0 || balance < fare ||
            balance - fare < MIN_BALANCE)
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

int main() {
    SmartCard card(10000);

    long long fares[] = {
        calculateFare(Zone::Inner, false),
        calculateFare(Zone::Outer, true),
        calculateFare(Zone::Middle, false)
    };

    long long total = 0;

    for (long long fare : fares) {
        total += fare;
        cout << "Fare: " << fare << " paise\n";
    }

    cout << "Total fare: " << total << " paise\n";

    for (long long fare : fares) {
        if (card.deduct(fare))
            cout << "Journey approved\n";
        else
            cout << "Journey denied\n";
    }

    cout << "Final balance: " << card.getBalance() << " paise\n";
    return 0;
}