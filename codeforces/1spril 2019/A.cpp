#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0; (1 << i) <= n; ++i) {
        for (int j = 0; j < n; j += (1 << i)) {
                int pr = 0;
                for (int k = j; k < (j + (1 << i)); ++k) {
                    if (a[k] < pr && k != j) {
                        pr = -1; break;
                    }
                    pr = a[k];
                }


                if (pr != -1) ans = 1 << i;
        }
    }

    cout << ans << '\n';
}
