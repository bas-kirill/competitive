#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    cout << (((m - n) >> 31) & 1) + 1;
}
