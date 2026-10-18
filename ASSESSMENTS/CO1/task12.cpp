#include <iostream>
using namespace std;

enum class Zone { Inner = 1, Middle, Outer, Airport };

constexpr long long BASE_FARE[] = {
    0, 1000, 2000, 3000, 6000
};

constexpr int PEAK_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
constexpr long long MIN_BALANCE = 5000;

class MonthlyPass {
private:
    Zone first;
    Zone second;

public:
    MonthlyPass(Zone a, Zone b) : first(a), second(b) {}

    bool covers(Zone zone) const {
        return zone == first || zone == second;
    }
};

long long calculateFare(Zone zone, bool peak, bool weekend,
                        const MonthlyPass* pass = nullptr) {
    int index = static_cast<int>(zone);

    if (index < 1 || index > 4)
        return -1;

    if (pass != nullptr && pass->covers(zone))
        return 0;

    long long fare = BASE_FARE[index];

    // Weekend discount and peak surcharge do not combine.
    if (weekend)
        fare -= fare * WEEKEND_DISCOUNT_PERCENT / 100;
    else if (peak)
        fare += fare * PEAK_PERCENT / 100;

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
    MonthlyPass pass(Zone::Inner, Zone::Middle);
    SmartCard card(20000);

    struct Test {
        Zone zone;
        bool peak;
        bool weekend;
        bool usePass;
        const char* name;
    };

    Test tests[] = {
        {Zone::Airport, false, false, false, "Airport off-peak"},
        {Zone::Outer, true, false, false, "Outer peak"},
        {Zone::Outer, true, true, false, "Outer weekend peak"},
        {Zone::Inner, true, false, true, "Inner with monthly pass"},
        {Zone::Middle, false, true, true, "Middle with monthly pass"}
    };

    for (const Test& t : tests) {
        long long fare = calculateFare(
            t.zone, t.peak, t.weekend, t.usePass ? &pass : nullptr
        );

        cout << t.name << ": ";

        if (card.deduct(fare))
            cout << fare / 100 << '.'
                 << (fare % 100 < 10 ? "0" : "")
                 << fare % 100 << " rupees";
        else
            cout << "Denied (minimum balance rule)";

        cout << ", balance " << card.getBalance() << " paise\n";
    }

    return 0;
}