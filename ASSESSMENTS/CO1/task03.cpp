#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    bool peak = true;
    char zoneCode = 'O';
    int hour = 18;
    unsigned int journeyCount = 3000000;
    long long balancePaise = 10000;
    float approximateFare = 36.5f;
    double fareRupees = 36.50;
    auto calculatedFarePaise = 3650LL;

    double doubleTotal = 0.0;
    long long paiseTotal = 0;

    for (int i = 0; i < 10; ++i) {
        doubleTotal += 0.1;
        paiseTotal += 10;
    }

    cout << "Data type sizes (bytes)\n";
    cout << "bool: " << sizeof(bool) << '\n';
    cout << "char: " << sizeof(char) << '\n';
    cout << "int: " << sizeof(int) << '\n';
    cout << "unsigned int: " << sizeof(unsigned int) << '\n';
    cout << "long long: " << sizeof(long long) << '\n';
    cout << "float: " << sizeof(float) << '\n';
    cout << "double: " << sizeof(double) << '\n';
    cout << "auto variable type size: " << sizeof(calculatedFarePaise) << '\n';

    cout << "\nINT range: " << INT_MIN << " to " << INT_MAX << '\n';
    cout << "LONG_LONG range: " << LLONG_MIN << " to " << LLONG_MAX << '\n';

    cout << "\nDouble total: " << setprecision(17) << doubleTotal << '\n';
    cout << "Integer-paise total: " << paiseTotal << " paise\n";

    cout << "\nSample values: " << peak << ' ' << zoneCode << ' '
         << hour << ' ' << journeyCount << ' ' << balancePaise << ' '
         << approximateFare << ' ' << fixed << setprecision(2)
         << fareRupees << '\n';

    return 0;
}