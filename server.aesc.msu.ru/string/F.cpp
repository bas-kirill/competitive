#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) ++j;
		pi[i] = j;
	}
	return pi;
}

int main() {
    //freopen("input.txt", "r", stdin);
    string s, t;
    getline(cin, s);
    getline(cin, t);
    bool is_ans = 0;
    for (int i = 0; i <= s.size() - t.size(); ++i) {
        if (s.substr(i, t.size()) == t) {
            cout << i + 1 << " ";
            is_ans = 1;
        }
    }
    if (!is_ans) cout << 0;
}
