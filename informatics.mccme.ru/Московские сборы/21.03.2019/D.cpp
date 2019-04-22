//2^N

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>

int N;
const int INF = 2.1e9;

bool belong(int x, int L, int R) { return ((L <= x) && (x <= R)); }

int main() {
   // freopen("input.txt", "r", stdin);
    cin >> N;
    vi X(N);
    for (int &x : X) cin >> x;
    int S;
    cin >> S;
    pii ans = make_pair(INF, -1);
    int L[2], R[2];
    vi ANS(N, 0);
    for (int k = 0; k < S; ++k) {
        cin >> L[0] >> R[0] >> L[1] >> R[1];
        int best_res = INF, best_mask = -1;
        for (int cur_mask = 0; cur_mask < (1 << N); ++cur_mask) {
            int res = -1, ok = 1;
            int last[2]{-1, -1};
            for (int i = 0; i < N; ++i) {
                int bit = (cur_mask >> i) & 1;
                if ((last[bit] != -1) && !belong(X[i] - X[last[bit]], L[bit], R[bit])) { ok = 0; break; }
                if (last[bit] == i - 1)
                    ++res;
                last[bit] = i;
            }
            if (ok && (best_res > res))
                best_res = res, best_mask = cur_mask;
        }
        if (best_res < ans.first) {
            ans.first = best_res, ans.second = k + 1;
            for (int i = 0; i < N; ++i)
                ANS[i] = (best_mask >> i) & 1;
        }
        //DEBUG
//        cout << best_res << " " << best_mask << '\n';
        //END DEBUG
    }

    if (ans.first >= INF) return cout << 0, 0;
    cout << ans.second << " " << ans.first << '\n';
    for (int x : ANS) cout << x+1;
}
