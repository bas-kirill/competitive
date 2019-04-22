
#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    string s;
    cin >> s;

    int vowel = 0;
    int cnsnt = 0;

    int tmp_v = 0;
    int tmp_cnsnt = 0;
    int ans = 0;
    for (int i = 0; i < len(s); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
        {
            ++tmp_v;

            tmp_cnsnt = 0;
        }
        else
        {
            ++tmp_cnsnt;

            tmp_v = 0;
        }

        if (tmp_v == 3)
        {
            ans++;
            tmp_v = 1;
        }

        if (tmp_cnsnt == 3)
        {
            ans++;
            tmp_cnsnt = 1;
        }
    }

    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
