#include <iostream>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()
int main() {
    char c;
    char c_prev = -1;
    while (cin >> c)
    {
        if (c == c_prev) break;
        cout << int(c) << '\n';
        c_prev = c;
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
