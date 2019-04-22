#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("output.txt", "w", stdout);
    random_device rd;
    mt19937 rand(rd);
    uniform_int_distribution<int> dis(0, 1488);
    cout << dis(rand);
}
