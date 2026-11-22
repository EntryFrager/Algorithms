#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long apple_division(int n, vector<long long>& p) {
    int totalN = 1 << (n - 1);
    vector<long long> diff{};

    long long totalSum = accumulate(p.begin(), p.end(), 0LL);
    long long curSum = 0;
    for (int mask = 0; mask < totalN; ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                curSum += p[i];
            }
        }

        diff.push_back(abs(totalSum - 2 * curSum));
        curSum = 0;
    }

    return *min_element(diff.begin(), diff.end());
}

#ifndef LOCAL_TESTS

int main() {
    int n;
    cin >> n;

    vector<long long> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    cout << apple_division(n, p);

    return 0;
}

#else

#include <gtest/gtest.h>

TEST(AppleDivisionTests, CSESTest1) {
    int n = 5;
    vector<long long> p{3, 2, 7, 4, 1};
    EXPECT_EQ(apple_division(n, p), 1LL);
}

TEST(AppleDivisionTests, CSESTest2) {
    int n = 10;
    vector<long long> p{603, 324, 573, 493, 659, 521, 654, 70, 718, 257};
    EXPECT_EQ(apple_division(n, p), 2LL);
}

#endif