#include <iostream>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    char c;
    int n = 0, ch = 0;
    cin >> c;
    while (c != '.')
    {
        if (c >= '0' && c <= '9')
        {
            n++;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            ch++;
        }
        cin >> c;
    }

    cout << n << " " << ch;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
