#include <bits/stdc++.h>
using namespace std;

int N, K;
bool bad[11][11], used[11];
int ans = 0;

void solve(int v) {
	int cnt = 0;
	for (bool x : used) if (x) ++cnt;
	if (cnt == N) { ++ans; return; }
	for (int u = 0; u < N; ++u) {
		bool flag = 0; 
		if (used[u]) flag = 1;
		if (v != -1 && bad[v][u] == 1) flag = 1; //
		if (!flag) {
			used[u] = 1;
			solve(u);
			used[u] = 0;
		}
	}
}

int main() {
	//freopen("input.txt", "r+", stdin);
	cin >> N >> K;
	while (K--) {
		int I, J; cin >> I >> J, --I, --J;
		bad[I][J] = bad[J][I] = 1;
	}
	solve(-1);
	cout << ans;
}