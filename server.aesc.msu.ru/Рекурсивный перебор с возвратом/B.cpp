#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define len(x) int((x).size())
#define pb push_back

int N;
int ans = 0;

void f(vi fields) {
	if (len(fields) == N) { ++ans; return; }

	for (int i = 0; i < N; ++i) {
		bool flag = 0;

		for (int j = 0; j < len(fields); ++j) {
			if ( abs(len(fields) - j) == abs(fields[j] - i) ) 
				flag = 1;
			if (fields[j] == i) 
				flag = 1;
		}

		if (!flag) {
			fields.pb(i);
			f(fields);
			fields.pop_back();
		}
	}
}

int main() {
	// freopen("input.txt", "r+", stdin);
	cin >> N;
	vector<int> tmp = {};
	f(tmp);
	cout << ans;
}