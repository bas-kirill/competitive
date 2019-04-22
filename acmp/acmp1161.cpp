#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

vector<int> z_func_trivial(string s)
{
    int n = len(s);
    vector<int> z(n);
    z[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (s[j] == s[cnt])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        z[i] = cnt;
    }

    return z;
}

vector<int> z_smart(string s)
{

}

int main() {
    string s;
    cin >> s;
    vector<int> z = z_func_trivial(s);
    for (int x : z)
    {
        cout << x << " ";
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
