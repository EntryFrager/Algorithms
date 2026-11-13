#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f(int count, int n, vector<int> t, vector<int> z, vector<int> y, int t) {
    
    return >= count;
}

long long find_best(int count, int n, vector<int> t, vector<int> z, vector<int> y) {
    int l = 0;
    int r = 1;

    while (!f(count, n, t, z, y, r))
        r *= 2;

    int m = 0;
    while ((l + 1) < r) {
        m = (l + r) / 2;

        if (f(count, n, t, z, y, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    return r;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> t(n);
    vector<int> z(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> z[i] >> y[i];
    }

    cout << find_best(m, n, t, z, y) << "\n";

    return 0;
}