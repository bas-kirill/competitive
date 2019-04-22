#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    ld x, eps;
    cin >> x >> eps;
    ld val = x;
    int i = 1;
    ld ans = x;
    while (true) {
        ld tmp = (-2 * ld(x)) / i;
        val *= tmp;
        ans += val;
        ++i;
        if (fabs(val) <= eps) break;
        cout << val << '\n';
    }
    ld exact = x * exp(-2 * x);
    cout << "Accurate to eps: " << setprecision(10) << ans << '\n';
    cout << "Exact value of function: " << setprecision(10) << exact << '\n';
    cout << "The value of the relative error: " << setprecision(10) << abs(ans - exact) / exact;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
