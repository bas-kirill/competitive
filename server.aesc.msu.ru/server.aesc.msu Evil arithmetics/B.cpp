#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int _n = n + 1 / (n + 1);
    int _m = m + 1 / (m + 1);
    //cout << n << " " << m << endl;
    cout << (n % _m) * (m % _n) + 1 + (1 / (n + m + 1));
    //cout <<  + 1 + (1 / (n + m));
}
