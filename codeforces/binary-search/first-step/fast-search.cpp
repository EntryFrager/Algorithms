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
    return my_upper_bound<int>(cont, r) - my_lower_bound<int>(cont, l) + 1;
}

int main() {
    size_t n = 0, k = 0;
    int x = 0;

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