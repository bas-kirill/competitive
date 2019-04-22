#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    getline(cin, s);
    int ans = 0;
    int cur_ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            cur_ans++;
            ans = max(ans, cur_ans);
        } else {
            cur_ans = 0;
        }
    }

    cout << ans;
}
