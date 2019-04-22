#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    cout << (60 * m - 11 * n + 720) % 720 / 11;
}
