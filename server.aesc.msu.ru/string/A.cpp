#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    //freopen("input.txt", "r", stdin);
    getline(cin, s);
    string ans = "";
    while (s[0] == ' ') {
        s.erase(s.begin());
    }

    while (s[s.size() - 1] == ' ') {
        s.erase(s.begin() + s.size() - 1);
    }

    for (int i = 0; i < s.size(); ++i)
        if (s[i] == ' ') {
            int j = i + 1;
            while (s[j] == ' ') {
                s.erase(j, 1);
            }
        }

    cout << s << endl;
}
