#include <iostream>
using namespace std;

class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    int difference = first - second;
    return difference < 0 ? -difference : difference;
}
inline bool earlier(const Time& a, const Time& b) {
    return a.h < b.h || (a.h == b.h && a.m < b.m);
}

int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time noon(12, 0), beforeNoon(11, 59), same(12, 0);
    cout << minutesBetween(beforeNoon, noon) << ' '
         << earlier(beforeNoon, noon) << ' '
         << earlier(same, noon) << '\n';
}