#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>::iterator begin, vector<int>::iterator end, int x) {
    auto it = begin;
    auto last = end;

    while (last > it) {
        auto mid = it + (last - it) / 2;
        if (*mid <= x) {
            it = mid + 1;
        } else {
            last = mid;
        }
    }

    return it - begin;
}

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
        cout << find(a.begin(), a.end(), x) << "\n";
    }

    return 0;
}