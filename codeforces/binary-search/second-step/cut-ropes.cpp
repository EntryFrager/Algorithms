#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

bool f(int n, int k, vector<int>& length, double m) {
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        count += length[i] / m;
    }
    
    return count >= k;
}

double find_max(int n, int k, vector<int>& length) {
    double l = 0;
    double r = 1;
    while (f(n, k, length, r))
        r *= 2;
    
    double m = 0;
    for (int i = 0; i < 100; ++i) {
        m = (l + r) / 2.0;

        if (f(n, k, length, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

#ifndef LOCAL_TESTS

int main() {
    int n = 0, k = 0;
    cin >> n >> k;

    vector<int> length(n);
    for (int i = 0; i < n; ++i) {
        cin >> length[i];
    }

    cout << setprecision(10) << find_max(n, k, length) << "\n";

    return 0;
}

#else

#include <gtest/gtest.h>

TEST(FindMaxTest, SampleTest) {
    int n = 4, k = 11;
    vector<int> length = {802, 743, 457, 539};
    EXPECT_NEAR(find_max(n, k, length), 200.5, 1e-6);
}

#endif