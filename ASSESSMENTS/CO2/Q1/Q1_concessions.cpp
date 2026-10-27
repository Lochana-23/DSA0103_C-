#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}
void applyByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}
void applyByPointer(long long* fee, int percent) {
    if (fee != nullptr) *fee -= *fee * percent / 100;
}

void change(int a, int& b, int* c) {
    a += 10;
    b += 10;
    *c += 10;
}
int& bigger(int& p, int& q) { return p > q ? p : q; }
void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << ' ';
}

int main() {
    long long value = 45000, reference = 45000, pointer = 45000;
    applyByValue(value, 10);
    applyByReference(reference, 10);
    applyByPointer(&pointer, 10);
    cout << "By value: " << value << '\n';
    cout << "By reference: " << reference << '\n';
    cout << "By pointer: " << pointer << '\n';

    int a = 1, b = 2, c = 3;
    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';
    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';
    show(1); show(1, 2); show(1, 2, 3);
    cout << '\n';

    long long hostelFee = 45000;
    applyByValue(hostelFee, 10);
    cout << "after call by value : " << hostelFee << '\n';
    applyByReference(hostelFee, 10);
    cout << "after call by reference: " << hostelFee << '\n';
}