#include <bits/stdc++.h>
using namespace std;

bool is_letter(char c) { return (c >= 'a' && c <= 'z'); }

int main() {
	string s; cin >> s;
	int n = (int) s.size();

	vector<char> st;


	bool is_first_letter;
	char sign;
	for (int i = 0; i < n; ++i) {
			if (s[i] == '(')
				st.push_back('(');
			if (is_letter(s[i]))
				st.push_back(s[i]);
			if (s[i] == '-' || s[i] == '+' || s[i] == '*') {
				
			}
 	}
}