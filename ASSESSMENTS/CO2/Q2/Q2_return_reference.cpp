#include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int best = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}

// Intentionally unsafe: compile separately to capture the compiler warning.
// Do not call this function and use the returned reference.
int& badLocalReference() {
    int local = 75;
    return local;
}

int highestIndex(const int marks[], int size) {
    int best = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[best]) best = i;
    return best;
}
int* highestPointer(int marks[], int size) {
    int best = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[best]) best = i;
    return &marks[best];
}

int main() {
    int marks[] = {78, 91, 84, 88};
    cout << "Highest before moderation: " << highestMark(marks, 4) << '\n';
    highestMark(marks, 4) += 2;
    cout << "Highest after moderation: " << highestMark(marks, 4) << '\n';

    int index = highestIndex(marks, 4);
    cout << "Highest index: " << index << '\n';
    *highestPointer(marks, 4) += 1;
    cout << "After pointer update: " << highestMark(marks, 4) << '\n';
}