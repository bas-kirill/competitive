#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a = {0, 2, 3, 4, 5, 6, 8, 12, 30, 32, 33, 34, 35, 36, 38, 40, 42, 43, 44, 45, 46, 48, 50, 52, 53, 54, 55, 56, 58, 60, 62, 63, 64, 65, 66, 68, 80, 82, 83, 84, 85, 86, 88 };

    for (int i : a)
        if (i == n)
            return cout << "YES", 0;

    cout << "NO";
}
