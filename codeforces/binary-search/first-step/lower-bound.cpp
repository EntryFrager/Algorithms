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
        cout << lower_bound<int>(a, x) << "\n";
    }

    return 0;
}