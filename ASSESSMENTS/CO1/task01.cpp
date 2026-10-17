
#include <iomanip>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr long long MIN_BALANCE = 5000;
constexpr int SURCHARGE_PERCENT = 20;

class FareTable {
public:
    static long long calculateFare(Zone zone, bool peak) {
        long long fare = 0;

        switch (zone) {
            case Zone::Inner:  fare = 1000; break;
            case Zone::Middle: fare = 2000; break;
            case Zone::Outer:  fare = 3000; break;
        }

        if (peak)
            fare += fare * SURCHARGE_PERCENT / 100;

        return fare;
    }
};

class SmartCard {
private:
    long long balance;

public:
    explicit SmartCard(long long amount) : balance(amount) {}

    bool canTravel(long long fare) const {
        return fare >= 0 &&
               balance >= fare &&
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

class Journey {
private:
    Zone zone;
    bool peak;

public:
    Journey(Zone z, bool p) : zone(z), peak(p) {}

    long long calculateFare() const {
        return FareTable::calculateFare(zone, peak);
    }
};

void printMoney(long long paise) {
    cout << "Rs " << paise / 100 << '.'
         << setw(2) << setfill('0') << paise % 100
         << setfill(' ');
}

int main() {
    SmartCard card(10000); // Rs 100
    Journey trip(Zone::Outer, true);

    long long fare = trip.calculateFare();

    cout << "Fare: ";
    printMoney(fare);
    cout << '\n';

    if (card.deduct(fare))
        cout << "Journey approved\n";
    else
        cout << "Journey denied\n";

    cout << "Remaining balance: ";
    printMoney(card.getBalance());
    cout << '\n';

    return 0;
}
