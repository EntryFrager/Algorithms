#include <iostream>
#include <vector>

using namespace std;

template <typename T> int lower_bound(const vector<T>& cont, const T& x) { // a[i] >= x
    int l = -1;
    int r = cont.size();

    while ((l + 1) < r) {
        auto mid = (r + l) / 2;
        if (cont[mid] >= x) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return r + 1;
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
        cout << ::lower_bound<int>(a, x) << "\n";
    }

    return 0;
}

#else
#include <algorithm>
#include <gtest/gtest.h>
#include <random>

TEST(LowerBoundTest, StatementSample) {
    vector<int> a = {3, 3, 5, 8, 9};

    EXPECT_EQ(::lower_bound(a, 2), 1);
    EXPECT_EQ(::lower_bound(a, 4), 3);
    EXPECT_EQ(::lower_bound(a, 8), 4);
    EXPECT_EQ(::lower_bound(a, 1), 1);
    EXPECT_EQ(::lower_bound(a, 10), 6);
}

TEST(LowerBoundTest, EdgeCases) {
    vector<int> empty;
    EXPECT_EQ(::lower_bound(empty, 0), 1);

    vector<int> same = {5, 5, 5, 5};
    EXPECT_EQ(::lower_bound(same, 4), 1);
    EXPECT_EQ(::lower_bound(same, 5), 1);
    EXPECT_EQ(::lower_bound(same, 6), 5);
}

TEST(LowerBoundTest, StressAgainstStd) {
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
            int expected = static_cast<int>(std::lower_bound(a.begin(), a.end(), x) - a.begin()) + 1;
            ASSERT_EQ(::lower_bound(a, x), expected)
                << "Failed on iter=" << iter << ", x=" << x;
        }
    }
}

#endif