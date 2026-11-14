#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ballon_worker(int t, int z, int y, int m) {
    int loopTime = t * z + y;
    int countWorkLoops = m / loopTime;
    int rem = m % loopTime;

    return countWorkLoops * z + (int) min(rem, z * t) / t;
}

bool f(int count, int n, vector<int>& t, vector<int>& z, vector<int>& y, int m) {
    int curCount = 0;

    for (int i = 0; i < n; ++i) {
        curCount += ballon_worker(t[i], z[i], y[i], m);
        if (curCount >= count)
            return true;
    }
    
    return false;
}

long long find_best(int count, int n, vector<int>& t, vector<int>& z, vector<int>& y) {
    if (count == 0)
        return 0;

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

    auto time = find_best(m, n, t, z, y);
    
    cout << time << "\n";
    int remBal = m;
    for (int i = 0; i < n; ++i) {
        int bal = min(remBal, ballon_worker(t[i], z[i], y[i], time));
        cout << bal << " ";
        remBal -= bal;
    }
    
    return 0;
}