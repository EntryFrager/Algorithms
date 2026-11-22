#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool two_sets(long long n, const vector<long long>& a, pair<vector<long long>, vector<long long>>& sets) {
    long long sum = n * (n + 1) / 2;

    if (sum % 2 != 0)
        return false;

    long long half = sum / 2;

    long long firstSum  = 0;

    for (long long i = n - 1; i >= 0; --i) {
        if ((firstSum + a[i]) <= half) {
            firstSum += a[i];
            sets.first.push_back(a[i]);
        } else {
            sets.second.push_back(a[i]);
        }
    }

    return (sets.first.size() + sets.second.size()) == n;
}

#ifndef LOCAL_TESTS

int main() {
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    pair<vector<long long>, vector<long long>> result{};
    if (two_sets(n, a, result)) {
        cout << "YES\n";

        cout << result.first.size() << "\n";
        for (long long i = result.first.size() - 1; i >= 0; --i)
            cout << result.first[i] << " ";
        cout << "\n";

        cout << result.second.size() << "\n";
        for (long long i = result.second.size() - 1; i >= 0; --i)
            cout << result.second[i] << " ";
    } else {
        cout << "NO\n";
    }

    return 0;
}

#else

#include <gtest/gtest.h>

TEST(TwoSetsTest, SampleN7) {
    long long n = 7;
    vector<long long> a = {1, 2, 3, 4, 5, 6, 7};
    pair<vector<long long>, vector<long long>> res{};

    ASSERT_TRUE(two_sets(n, a, res));

    vector<long long> expected_first = {7, 6, 1};
    vector<long long> expected_second = {5, 4, 3, 2};

    EXPECT_EQ(res.first, expected_first);
    EXPECT_EQ(res.second, expected_second);
}

TEST(TwoSetsTest, SampleN6) {
    long long n = 6;
    vector<long long> a = {1, 2, 3, 4, 5, 6};
    pair<vector<long long>, vector<long long>> res{};

    EXPECT_FALSE(two_sets(n, a, res));
    EXPECT_TRUE(res.first.empty());
    EXPECT_TRUE(res.second.empty());
}

#endif