#include <iostream>
#include <vector>

using namespace std;

bool find(vector<int>& a, int x) {
    size_t start = 0;
    size_t end = a.size();
    size_t mid = 0;

    while (end > start) {
        mid = start + (end - start) / 2;

        if (a[mid] == x) {
            return true;
        } else if (a[mid] > x) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return false;
}

bool find(vector<int>::iterator start, vector<int>::iterator end, int x) {
    if (start >= end)
        return false;
    auto mid = start + (end - start) / 2;

    if (*mid == x) {
        return true;
    } else if (*mid > x) {
        return find(start, mid, x);
    } else {
        return find(mid + 1, end, x);
    }

    return false;
}

#ifndef LOCAL_TESTS

int main() {
    size_t n = 0, k = 0;
    int x = 0;

    cin >> n >> k;
    vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while ((k--) > 0) {
        cin >> x;
        if (find(a.begin(), a.end(), x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

#else

#include <gtest/gtest.h>

TEST(BinarySearchTest, FirstTestExplicit) {
    vector<int> a = {1, 61, 126, 217, 2876, 6127, 39162, 98126, 712687, 1000000000};

    EXPECT_FALSE(::find(a.begin(), a.end(), 100));
    EXPECT_TRUE(::find(a.begin(), a.end(), 6127));
    EXPECT_TRUE(::find(a.begin(), a.end(), 1));
    EXPECT_TRUE(::find(a.begin(), a.end(), 61));
    EXPECT_FALSE(::find(a.begin(), a.end(), 200));
    EXPECT_FALSE(::find(a.begin(), a.end(), -10000));
    EXPECT_TRUE(::find(a.begin(), a.end(), 1));
    EXPECT_TRUE(::find(a.begin(), a.end(), 217));
    EXPECT_FALSE(::find(a.begin(), a.end(), 10000));
    EXPECT_TRUE(::find(a.begin(), a.end(), 1000000000));
}

TEST(BinarySearchTest, EmptyArray) {
    vector<int> empty;
    EXPECT_FALSE(::find(empty, 5));
    EXPECT_FALSE(::find(empty.begin(), empty.end(), 5));
}

#endif
