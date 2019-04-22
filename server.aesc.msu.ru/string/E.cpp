#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    freopen("input.txt", "r", stdin);
    getline(cin, s);

    while (s[0] == ' ') {
        s.erase(s.begin());
    }

    while (s[s.size()-1] == ' ') {
        s.erase(s.begin());
    }

    //cout << s << endl;
}
