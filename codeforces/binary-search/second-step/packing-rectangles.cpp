#include <iostream>

using namespace std;

bool f(long long w, long long h, long long n, long long m) {
    return (m / w) * (m / h) >= n;
}

long long find_best(long long w, long long h, long long n) {
    long long l = 0;
    long long r = 1;
    while (!f(w, h, n, r))
        r *= 3;

    long long m = 0;
    while ((l + 1) < r) {
        m = (l + r) / 2;

        if (f(w, h, n, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    return r;
}

int main() {
    long long w = 0, h = 0, n = 0;
    cin >> w >> h >> n;

    cout << find_best(w, h, n) << "\n";

    return 0;
}