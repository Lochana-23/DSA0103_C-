#include <iostream>
using namespace std;

constexpr long long INNER_FARE = 1000;
constexpr long long MIDDLE_FARE = 2000;
constexpr long long OUTER_FARE = 3000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

enum class Zone { Inner, Middle, Outer };

long long getFare(Zone zone, bool peak) {
    long long fare = 0;

    switch (zone) {
        case Zone::Inner:  fare = INNER_FARE; break;
        case Zone::Middle: fare = MIDDLE_FARE; break;
        case Zone::Outer:  fare = OUTER_FARE; break;
    }

    if (peak)
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;

    return fare;
}

int main() {
    cout << "Inner fare: Rs " << INNER_FARE / 100.0 << '\n';
    cout << "Middle fare: Rs " << MIDDLE_FARE / 100.0 << '\n';
    cout << "Outer fare: Rs " << OUTER_FARE / 100.0 << '\n';
    cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
    cout << "Minimum balance: Rs " << MIN_BALANCE_PAISE / 100.0 << '\n';
    cout << "Outer peak fare: Rs " << getFare(Zone::Outer, true) / 100.0 << '\n';

    return 0;
}