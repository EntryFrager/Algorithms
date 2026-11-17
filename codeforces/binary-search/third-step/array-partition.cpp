#include <iostream>
#include <vector>

using namespace std;

bool check_sum(int n, int k, vector<long long> a, long long m) {
    long long sum = 0;
    int count = 1;

    for (int i = 0; i < n; ++i) {
        if (a[i] > m)
            return false;
        
        sum += a[i];

        if (sum > m) {
            ++count;
            sum = a[i];
        }
    }

    return count <= k;
}

long long find_min_sum(int n, int k, vector<long long> a) {
    long long l = 0;
    long long r = 1;
    long long m = 0;

    while (!check_sum(n, k, a, r))
        r *= 2;

    while ((l + 1) < r) {
        m = (r + l) / 2;

        if (check_sum(n, k, a, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    return r;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << find_min_sum(n, k, a); 

    return 0;
}