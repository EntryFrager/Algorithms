#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> int my_upper_bound(const vector<T>& cont, const T& x) {
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

template <typename T> int my_lower_bound(const vector<T>& cont, const T& x) {
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

template <typename T> int fast_search(const vector<T>& cont, const T& l, const T& r) {
    return my_upper_bound<T>(cont, r) - my_lower_bound<T>(cont, l) + 1;
}

#ifndef LOCAL_TESTS

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n = 0, k = 0;

    cin >> n;
    vector<int> cont(n);
    for (size_t i = 0; i < n; ++i)
        cin >> cont[i];

    std::sort(cont.begin(), cont.end());
    cin >> k;
    int l = 0, r = 0;

    while ((k--) > 0) {
        cin >> l >> r;
        cout << fast_search(cont, l, r) << " ";
    }

    return 0;
}

#else
#include <gtest/gtest.h>
#include <random>

TEST(FastSearchTest, StatementSample) {
    vector<int> cont = {10, 1, 10, 3, 4};
    sort(cont.begin(), cont.end()); // {1, 3, 4, 10, 10}

    EXPECT_EQ(fast_search(cont, 1, 10), 5);
    EXPECT_EQ(fast_search(cont, 2, 9), 2);
    EXPECT_EQ(fast_search(cont, 3, 4), 2);
    EXPECT_EQ(fast_search(cont, 2, 2), 0);
}

TEST(FastSearchTest, EdgeCases) {
    vector<int> empty;
    EXPECT_EQ(fast_search(empty, -10, 10), 0);

    vector<int> same = {5, 5, 5, 5};
    EXPECT_EQ(fast_search(same, 5, 5), 4);
    EXPECT_EQ(fast_search(same, 1, 4), 0);
    EXPECT_EQ(fast_search(same, 6, 10), 0);

    vector<int> limits = {-1000000000, 0, 1000000000};
    EXPECT_EQ(fast_search(limits, -1000000000, 1000000000), 3);
    EXPECT_EQ(fast_search(limits, -1000000000, -1000000000), 1);
    EXPECT_EQ(fast_search(limits, 1000000000, 1000000000), 1);
}

TEST(FastSearchTest, StressAgainstStd) {
    mt19937 rng(42);
    for (int iter = 0; iter < 500; ++iter) {
        int n = rng() % 50;
        vector<int> cont(n);
        for (int& x : cont) {
            x = static_cast<int>(rng() % 41) - 20;
        }
        sort(cont.begin(), cont.end());

        for (int q = 0; q < 20; ++q) {
            int l = static_cast<int>(rng() % 51) - 25;
            int r = static_cast<int>(rng() % 51) - 25;
            if (l > r) swap(l, r);

            int expected = static_cast<int>(
                upper_bound(cont.begin(), cont.end(), r) -
                lower_bound(cont.begin(), cont.end(), l)
            );
            ASSERT_EQ(fast_search(cont, l, r), expected)
                << "Failed on iter=" << iter << " query=[" << l << ", " << r << "]";
        }
    }
}

#endif