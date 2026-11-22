#include <iostream>
#include <vector>

using namespace std;

bool check_distance(int n, int k, vector<long long> a, long long m) {
    int cows = 1;
    int last_pos = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] - a[last_pos] >= m) {
            ++cows;
            last_pos = i;
        }
    }

    return cows >= k;
}

long long find_min_distance(int n, int k, vector<long long> a) {
    long long l = 0;
    long long r = 1;
    long long m = 0;

    while (check_distance(n, k, a, r))
        r *= 2;

    while ((l + 1) < r) {
        m = (r + l) / 2;

        if (check_distance(n, k, a, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

#ifndef LOCAL_TESTS

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << find_min_distance(n, k, a); 

    return 0;
}

#else

#include <gtest/gtest.h>

TEST(FindMinDistanceTest, SampleTest) {
    int n = 6, k = 3;
    vector<long long> a = {2, 5, 7, 11, 15, 20};
    EXPECT_EQ(find_min_distance(n, k, a), 9LL);
}

#endif