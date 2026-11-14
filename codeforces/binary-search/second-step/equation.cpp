#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double equation_solver(long double m) {
    return (m * m + sqrt(m));
}

long double my_find(long double c) {
    if (c == 0)
        return 0;

    long double l = 0.0;
    long double r = sqrt(c);

    long double m = 0.0;
    for (int i = 0; i < 200; ++i) {
        m = (r + l) / 2;

        if (equation_solver(m) > c) {
            r = m;
        } else {
            l = m;
        }
    }

    return (r + l) / 2;
}

int main() {
    long double c = 0.0;
    cin >> c;

    cout << fixed << setprecision(6) << my_find(c) << "\n";

    return 0;
}