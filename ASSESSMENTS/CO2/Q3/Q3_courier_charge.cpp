#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

double charge(double weightKg, bool express = false, bool insured = false) {
    double total = 40.0 + weightKg * 20.0;
    if (express) total += 25.0;
    if (insured) total += 10.0;
    return total;
}
double charge(int weightGrams, bool express = false, bool insured = false) {
    return charge(static_cast<double>(weightGrams) / 1000.0, express, insured);
}
double charge(const Parcel& p) {
    return charge(p.weightKg, p.express, p.insured);
}

int main() {
    Parcel p{2.5, true, true};
    cout << "charge(500): " << charge(500) << '\n';
    cout << "charge(2): " << charge(2) << '\n';
    cout << "charge(2.0): " << charge(2.0) << '\n';
    cout << "charge(2.0f): " << charge(2.0f) << '\n';
    cout << "charge(750, true): " << charge(750, true) << '\n';
    cout << "charge(p): " << charge(p) << '\n';
}