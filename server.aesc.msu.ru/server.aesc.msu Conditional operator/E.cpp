#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    if (n < m)
    {
        swap(n, m);
    }

    cout << min(min(x, y), min(m - x, n - y));
}
