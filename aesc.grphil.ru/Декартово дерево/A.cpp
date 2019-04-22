#include <iostream>
#include <cstdio>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main() {
    ios_base::sync_with_stdio(false);
    rope<int> v;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);

    while (m--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        rope<int> cur = v.substr(l, r - l + 1);
        v.erase(l, r - l + 1);
        v.insert(v.mutable_begin(), cur);
    }

    for (auto it = begin(v); it != end(v); ++it) {
        cout << *it << " ";
    }
}
