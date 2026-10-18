#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int zone, hour;

    cout << "Enter zone (1=Inner, 2=Middle, 3=Outer): ";
    while (!(cin >> zone) || zone < 1 || zone > 3) {
        cout << "Invalid zone. Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter hour (0-23): ";
    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter 0-23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long fare[] = {0, 1000, 2000, 3000};
    long long amount = fare[zone];

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        amount += amount * 20 / 100;

    cout << fixed << setprecision(2);
    cout << "\n--- Journey Report ---\n";
    cout << "Zone: " << zone << '\n';
    cout << "Hour: " << hour << ":00\n";
    cout << "Peak: " << boolalpha << peak << '\n';
    cout << "Fare: Rs " << amount / 100.0 << '\n';

    return 0;
}