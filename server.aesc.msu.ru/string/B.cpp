#include <bits/stdc++.h>
using namespace std;

bool is_pal(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1])
            return 0;
    }
    return 1;
}

string s;

int main() {
    getline(cin, s);
    if (is_pal(s)) return cout << 0, 0;
    string rs = s;
    reverse(rs.begin(), rs.end());
    string t = s + rs;
    int ans = 0;
    while (t.size() != s.size()) {
        if (is_pal(t)) ans = rs.size();
        rs.erase(rs.begin());
        t = s + rs;
    }

    cout << ans;
}
