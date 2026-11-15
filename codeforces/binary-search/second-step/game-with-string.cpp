#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check_letter(const string& t, const string& p, const vector<size_t>& a, size_t m) {
    vector<bool> removed(t.size());

    for (size_t i = 0; i < m; ++i) {
        removed[a[i]] = true;
    }

    size_t j = 0;
    size_t tLen = t.size();
    size_t pLen = p.size();
    for (size_t i = 0; i < tLen && j < pLen; ++i) {
        if (!removed[i] && t[i] == p[j])
            ++j;
    }
    
    return j == pLen;
}

unsigned int remove_letters(const string& t, const string& p, const vector<size_t>& a) {
    size_t l = 0;
    size_t r = t.size();

    size_t m = 0;
    while ((l + 1) < r) {
        m = (r + l) / 2;

        if (check_letter(t, p, a, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    string t, p;
    cin >> t >> p;
    size_t len = t.size();
    vector<size_t> a(len);

    for (size_t i = 0; i < len; ++i) {
        cin >> a[i];
        --a[i];
    }

    cout << remove_letters(t, p, a);

    return 0;
}