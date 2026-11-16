#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

bool check_distance(int n, vector<long long> x, vector<long long> v, long double m) {
    long double maxL = (-1.0) * std::numeric_limits<double>::max();
    long double minR = std::numeric_limits<double>::max();

    long double curL = 0;
    long double curR = 0;

    for (int i = 0; i < n; ++i) {
        curL = x[i] - v[i] * m;
        curR = x[i] + v[i] * m;

        if (maxL < curL)
            maxL = curL;
        if (minR > curR)
            minR = curR;
    }

    return (maxL < minR);
}

long double find_min_time(int n, vector<long long> x, vector<long long> v) {
    long double l = 0;
    long double r = 1;
    long double m = 0;

    while (!check_distance(n, x, v, r))
        r *= 2;

    for (int i = 0; i < 100; ++i) {
        m = (r + l) / 2;

        if (check_distance(n, x, v, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    return r;
}

int main() {
    int n;
    cin >> n;

    vector<long long> x(n);
    vector<long long> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        cin >> v[i];
    }

    cout << fixed << setprecision(6) << find_min_time(n, x ,v); 

    return 0;
}