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