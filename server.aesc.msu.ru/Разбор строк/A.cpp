#include <bits/stdc++.h>
using namespace std;

string ans;

bool is_letter(char c) { return (c >= 'a' && c <= 'z'); }

void rec() {
	char c; cin >> c;
	if (is_letter(c)) { ans += c; return; }

	rec();
	char sign; cin >> sign;
	rec();
	cin >> c; ans += sign;
	return;
}

int main() {
	// freopen("input.txt", "r+", stdin);
	rec();
	cout << ans;
}