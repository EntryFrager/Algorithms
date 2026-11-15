#include <iostream>
#include <vector>

using namespace std;

bool check_counsils(size_t k, const vector<long long>& a, long long m) {
    long long studentCount = 0;
    for (long long count : a)
        studentCount += min(count, m);
    return studentCount >= m * k;
}

long long find_counsils(size_t k, const vector<long long>& a) {
    long long l = 0;
    long long r = 1;

    while (check_counsils(k, a, r))
        r *= 2;

    long long m = 0;
    while ((l + 1) < r) {
        m = (r + l) / 2;

        if (check_counsils(k, a, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    size_t k, n;
    cin >> k >> n;
    vector<long long> a(n);
    for (size_t i = 0; i < n; ++i)
        cin >> a[i];

    cout << find_counsils(k, a);
    return 0;
}