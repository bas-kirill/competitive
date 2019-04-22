#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
   // freopen("input.txt", "r", stdin);
    getline(cin, s);
    getline(cin, t);

    int n = (int)s.size(), m = (int)t.size();
    for (int i = 0; i < m - n; ++i) s = '0' + s; s = '0' + s;
    for (int i = 0; i < n - m; ++i) t = '0' + t; t = '0' + t;

    n = s.size(), m = s.size();
    int carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        int dig_s = s[i] - '0';
        int dig_t = t[i] - '0';
        int next = carry + dig_s + dig_t;
        carry = next / 10;
        next %= 10;
        s[i] = next + '0';
    }
    if (s[0] == '0') cout << s.substr(1, s.size() - 1); else cout << s;
}
