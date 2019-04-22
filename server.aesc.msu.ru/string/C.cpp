#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    getline(cin, s);
    for (int i = s.size()-1; i >= 0; --i) {
        if (s[i] == ' ') {
            cout << s.substr(i + 1, s.size() - i - 1) << " " << s.substr(0, i);
        }
    }
}
