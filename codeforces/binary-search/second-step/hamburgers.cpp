#include <iostream>
#include <vector>

using namespace std;

bool make_hamburger(const vector<int>& recipe, const vector<int>& n, const vector<int>& p, long long money, long long m) {
    long long b = max(0LL, m * recipe[0] - n[0]);
    long long s = max(0LL, m * recipe[1] - n[1]);
    long long c = max(0LL, m * recipe[2] - n[2]);
    return (b * p[0] + s * p[1] + c * p[2]) <= money;
}

long long hamburgers_count(const vector<int>& recipe, const vector<int>& n, const vector<int>& p, long long money) {
    long long l = 0;
    long long r = 1;

    while (make_hamburger(recipe, n, p, money, r))
        r *= 2;

    long long m = 0;
    while ((l + 1) < r) {
        m = (r + l) / 2;

        if (make_hamburger(recipe, n, p, money, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

#ifndef LOCAL_TESTS

int main() {
    string recipeStr;
    cin >> recipeStr;
    vector<int> recipe(3, 0);
    for (char ch : recipeStr) {
        if (ch == 'B') ++recipe[0];
        else if (ch == 'S') ++recipe[1];
        else if (ch == 'C') ++recipe[2];
    }

    vector<int> n(3);
    for (int i = 0; i < 3; ++i)
        cin >> n[i];

    vector<int> p(3);
    for (int i = 0; i < 3; ++i)
        cin >> p[i];

    long long money;
    cin >> money;

    cout << hamburgers_count(recipe, n, p, money);
    return 0;
}

#else

#include <gtest/gtest.h>

TEST(HamburgersTest, FirstTest) {
    vector<int> recipe = {3, 2, 1};
    vector<int> n = {6, 4, 1};
    vector<int> p = {1, 2, 3};
    long long money = 4;

    EXPECT_EQ(hamburgers_count(recipe, n, p, money), 2LL);
}

TEST(HamburgersTest, SecondTest) {
    vector<int> recipe = {2, 0, 1};
    vector<int> n = {1, 10, 1};
    vector<int> p = {1, 10, 1};
    long long money = 21;

    EXPECT_EQ(hamburgers_count(recipe, n, p, money), 7LL);
}

// TEST(HamburgersTest, ThirdTest) {
//     vector<int> recipe = {1, 1, 1};
//     vector<int> n = {1, 1, 3};
//     vector<int> p = {1, 1, 1};
//     long long money = 1000000000000LL;

//     EXPECT_EQ(hamburgers_count(recipe, n, p, money), 200000000001LL);
// }

#endif