#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define dis(x) cout << x
#define disp(x) cout << x << " "
#define display(x) cout << x << endl
#define f1(i, a, b) for (ll i = a; i < b; i++)
#define f2(i, a, b) for (ll i = a; i > b; i--)
using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output_brut.txt");
    ll n;
    cin >> n;
    disp(1);
    f1(j, 2, 100) {
        if (n % j == 0)
            disp(j + n * (j - 1) / 2);
    }

    f2(i, n / 100, 0)
        if (n % i == 0)
            disp(n * (2 + n - 1) / (2 * i));
}
