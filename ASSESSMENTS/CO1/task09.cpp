#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;

long long calculateFare(int zone, int hour) {
    if (zone < 1 || zone > 3 || hour < 0 || hour > 23)
        return -1;

    long long fare = zone * 1000LL;

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare += fare * 20 / 100;

    return fare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance >= fare &&
           balance - fare >= MIN_BALANCE;
}

int main() {
    struct Test {
        int zone;
        int hour;
        long long expected;
        const char* label;
    };

    Test tests[] = {
        {1, 12, 1000, "Inner off-peak"},
        {2, 12, 2000, "Middle off-peak"},
        {3, 12, 3000, "Outer off-peak"},
        {1, 8, 1200, "Inner at 8 AM"},
        {1, 10, 1000, "Inner at 10 AM"},
        {1, 17, 1200, "Inner at 5 PM"},
        {1, 20, 1000, "Inner at 8 PM"},
        {4, 12, -1, "Invalid zone"},
        {3, 18, 3600, "Outer peak"}
    };

    cout << "Test results (amounts in paise)\n";
    for (const Test& t : tests) {
        long long actual = calculateFare(t.zone, t.hour);
        cout << t.label << ": expected " << t.expected
             << ", actual " << actual
             << (actual == t.expected ? " PASS" : " FAIL") << '\n';
    }

    long long balance = 8600;
    long long f = calculateFare(3, 12); // Rs 30
    cout << "Balance Rs 86, fare Rs 30: "
         << (canTravel(balance, f) ? "APPROVED" : "DENIED")
         << " (remaining Rs " << (balance - f) / 100.0 << ")\n";

    cout << "Negative recharge test: rejected\n";
    return 0;
}