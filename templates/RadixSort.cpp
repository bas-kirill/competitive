#include <bits/stdc++.h>
using namespace std;

void csort (vector<int> &a) {
    int c = 1 << 8;
    int n = (int) a.size();
    vector<int> b[c];
    for (int i = 0; i < n; i++)
        b[a[i]%c].push_back(a[i]);
    int k = 0;
    for (int i = 0; i < c; i++) {
        for (size_t j = 0; j < b[i].size(); j++)
            a[k++] = b[i][j];
        b[i].clear();
    }
    for (int i = 0; i < n; i++)
        b[a[i]/c].push_back(a[i]);
    k = 0;
    for (int i = 0; i < c; i++)
        for (size_t j = 0; j < b[i].size(); j++)
            a[k++] = b[i][j];
}

int main() {
    int n; cin >> n;
    vector<int> a;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    for (int i = 0; i < n; ++i) a.push_back(uniform_int_distribution<int>(1 << 18, 1 << 30)(rng));

    csort(a);
    cout << (is_sorted(a.begin(), a.end()) ? '+' : '-') << endl;
    for (int x : a) cout << x << " ";
}
