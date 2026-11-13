#include <iostream>
#include <algorithm>

using namespace std;

bool f(long long n, int min, int max, int m) {
    if (m < min)
        return false;
    m -= min;

    return ((m / min) + (m / max) + 1) >= n;
}

long long find_best(long long n, int x, int y) {
    auto [min, max] = std::minmax(x, y);
    int l = 0;
    int r = 1;

    while (!f(n, min, max, r))
        r *= 2;

    int m = 0;
    while ((l + 1) < r) {
        m = (l + r) / 2;

        if (f(n, min, max, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    return r;
}

int main() {
    long long n = 0;
    int x = 0, y = 0;
    cin >> n >> x >> y;

    cout << find_best(n, x, y) << "\n";

    return 0;
}