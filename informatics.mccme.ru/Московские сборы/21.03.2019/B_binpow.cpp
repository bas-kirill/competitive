#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void init() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}

int N;
vi a;
int L = 0, R = 0;
vi top, bot;

void read() {
    cin >> N;
    a.resize(N);
    bot.resize(1000000, 0);
    top.resize(1000000, 0);
    for (int &x : a) cin >> x;
}

struct fenw {
    fenw() {}

    //SUM
    int get(vi &v, int i) {
        int res = 0;
        while (i >= 0)
            res += v[i], i = (i&(i+1))-1; //check formula
        return res;
    }

    void upd(vi &v, int i, int x) {
        while (i < N)
            v[i] += x, i = (i|(i+1));
    }
};

void solve() {
    if (N == 1) {cout << 1; exit(0);}
    vi cr(1000000, 0);
    for (int i = 0; i < N; ++i)
        cr[--a[i]] = i;
    fenw f;
    int i = 0;
//    exit(0);
    while (i < N) {
        if (cr[i] < cr[i + 1]) L = cr[i], R = cr[i + 1];
        else L = cr[i + 1], R = cr[i];
        vi &v = (i & 1) ? bot : top;
        if (f.get(v, R) - f.get(v, L - 1) != 0) break;
        f.upd(v, L, +1); f.upd(v, R, -1);
        //DEBUG
//        cout << N << "\n";
//        for (int i = 0; i < N; ++i) cout << v[i] << " "; cout << '\n';
//        exit(0);
        //END DEBUG
        ++i;
    }

    cout << min(i+1, N);
}

int main() {

    init();
    read();
    solve();
}
