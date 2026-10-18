#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const int counts[] = {20000, 500000, 3000000};
    const long long FARE_PAISE = 1200; // Rs 12.00

    cout << fixed << setprecision(2);

    for (int n : counts) {
        double doubleTotal = 0.0;
        long long paiseTotal = 0;

        for (int i = 0; i < n; ++i) {
            doubleTotal += 12.00;
            paiseTotal += FARE_PAISE;
        }

        cout << "Journeys: " << n << '\n';
        cout << "Double total: Rs " << doubleTotal << '\n';
        cout << "Paise total: Rs " << paiseTotal / 100.0 << '\n';
        cout << "Difference: Rs "
             << doubleTotal - paiseTotal / 100.0 << "\n\n";
    }

    int intTotal = 0;
    int farePaise = 1200;
    // Deliberately do not accumulate 3,000,000 fares in int:
    // that would exceed INT_MAX.

    cout << "One fare in paise: " << farePaise << '\n';
    cout << "INT_MAX: " << numeric_limits<int>::max() << '\n';

    return 0;
}