#include <iostream>
#include <vector>

using namespace std;

template <typename T> int upper_bound(const vector<T>& cont, const T& x) { // a[i] <= x
    int l = -1;
    int r = cont.size();

    while ((l + 1) < r) {
        auto mid = (r + l) / 2;
        if (cont[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return l + 1;
}

#ifndef LOCAL_TESTS

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n = 0, k = 0;
    int x = 0;

    cin >> n >> k;
    vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while ((k--) > 0) {
        cin >> x;
        cout << ::upper_bound<int>(a, x) << "\n";
    }

    return 0;
}

#else
#include <algorithm>
#include <gtest/gtest.h>
#include <random>

TEST(UpperBoundTest, StatementSample) {
    vector<int> a = {3, 3, 5, 8, 9};

    EXPECT_EQ(::upper_bound(a, 2), 0);
    EXPECT_EQ(::upper_bound(a, 4), 2);
    EXPECT_EQ(::upper_bound(a, 8), 4);
    EXPECT_EQ(::upper_bound(a, 1), 0);
    EXPECT_EQ(::upper_bound(a, 10), 5);
}

TEST(UpperBoundTest, EdgeCases) {
    vector<int> empty;
    EXPECT_EQ(::upper_bound(empty, 0), 0);

    vector<int> same = {5, 5, 5, 5};
    EXPECT_EQ(::upper_bound(same, 4), 0);
    EXPECT_EQ(::upper_bound(same, 5), 4);
    EXPECT_EQ(::upper_bound(same, 6), 4);
}

TEST(UpperBoundTest, StressAgainstStd) {
    mt19937 rng(42);
    for (int iter = 0; iter < 500; ++iter) {
        int n = rng() % 50;
        vector<int> a(n);
        for (int& v : a) {
            v = static_cast<int>(rng() % 41) - 20;
        }
        sort(a.begin(), a.end());

        for (int q = 0; q < 20; ++q) {
            int x = static_cast<int>(rng() % 51) - 25;
            int expected = static_cast<int>(std::upper_bound(a.begin(), a.end(), x) - a.begin());
            ASSERT_EQ(::upper_bound(a, x), expected)
                << "Failed on iter=" << iter << ", x=" << x;
        }
    }
}

#endif