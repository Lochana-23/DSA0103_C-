#include <iostream>
using namespace std;

class ShiftingHistory {
    static const int CAPACITY = 10;
    int values[CAPACITY]{};
    int count = 0;
public:
    void add(int value) {
        if (count < CAPACITY) values[count++] = value;
        else {
            for (int i = 1; i < CAPACITY; ++i) values[i - 1] = values[i];
            values[CAPACITY - 1] = value;
        }
    }
    void print() const {
        for (int i = 0; i < count; ++i) cout << values[i] << ' ';
        cout << '\n';
    }
};

class CircularHistory {
    static const int CAPACITY = 10;
    int values[CAPACITY]{};
    int count = 0;
    int next = 0;
public:
    void add(int value) {
        values[next] = value;
        next = (next + 1) % CAPACITY;
        if (count < CAPACITY) ++count;
    }
    void print() const {
        int start = (next - count + CAPACITY) % CAPACITY;
        for (int i = 0; i < count; ++i)
            cout << values[(start + i) % CAPACITY] << ' ';
        cout << '\n';
    }
};

int main() {
    ShiftingHistory original;
    CircularHistory redesigned;
    for (int i = 1; i <= 15; ++i) {
        original.add(i);
        redesigned.add(i);
    }
    cout << "Original latest 10: ";
    original.print();
    cout << "Circular latest 10: ";
    redesigned.print();
}