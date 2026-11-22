#include <iostream>

using namespace std;

bool f(long long w, long long h, long long n, long long m) {
    return (m / w) * (m / h) >= n;
}

long long find_best(long long w, long long h, long long n) {
    long long l = 0;
    long long r = 1;
    while (!f(w, h, n, r))
        r *= 3;

    long long m = 0;
    while ((l + 1) < r) {
        m = (l + r) / 2;

        if (f(w, h, n, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    return r;
}

#ifndef LOCAL_TESTS

int main() {
    long long w = 0, h = 0, n = 0;
    cin >> w >> h >> n;

    cout << find_best(w, h, n) << "\n";

    return 0;
}

#else

#include <gtest/gtest.h>

TEST(FindBestTest, SampleCase) {
    EXPECT_EQ(find_best(2, 3, 10), 9);
}

TEST(FindBestTest, SingleRectangle) {
    EXPECT_EQ(find_best(5, 7, 1), 7);
    EXPECT_EQ(find_best(1, 1, 1), 1);
}

TEST(FindBestTest, ExactGridFit) {
    EXPECT_EQ(find_best(2, 2, 4), 4);
    EXPECT_EQ(find_best(3, 5, 6), 10);
}

TEST(FindBestTest, NonSquareAndLargeValues) {
    EXPECT_EQ(find_best(1, 1000000000LL, 1000000000LL), 1000000000LL);
    EXPECT_EQ(find_best(1000000000LL, 1000000000LL, 1000000000LL), 31623000000000LL);
}

#endif