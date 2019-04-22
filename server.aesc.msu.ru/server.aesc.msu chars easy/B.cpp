#include <iostream>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    char c1, c2;
    cin >> c1 >> c2;
    int sum = 0;
    if (c1 >= '0' && c1 <= '9')
    {
        sum += 16 * (c1 - '0');
    }
    else if (c1 >= 'A' && c1 <= 'Z')
    {
        sum += 16 * (c1 - 'A' + 10);
    }

    if (c2 >= '0' && c2 <= '9')
    {
        sum += (c2 - '0');
    }
    else if (c2 >= 'A' && c2 <= 'Z')
    {
        sum += (c2 - 'A' + 10);
    }

    cout << sum;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
