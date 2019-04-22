#include <bits/stdc++.h>
using namespace std;

int main() {
    string mask;
    cin >> mask;

    vector<string> a(5);
    for (string &x : a) cin >> x;

    for (int i = 0; i < 5; ++i) {
        string str = a[i];
        bool ok = true;
        for (int j = 0; j < str.size(); ++j)
            if ( !(str[j] == mask[j] || mask[j] == '?') ) ok = false;
            else if ()
    }
}
