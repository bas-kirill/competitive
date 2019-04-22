#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

const int buben = 5e8;
int M_1, M_2;
const ll P = 31;
char s[100'001], t[1'000'001];

struct num {
    ll a, b;

    void upd(ll &a, ll &b) {
        if (a < 0) a += M_1;
        if (b < 0) b += M_2;
    }

    num(ll x) {
        a = x%M_1, b = x%M_2;
        upd(a, b);
    }

    num(ll x, ll y) {
        a = x % M_1, b = y % M_2;
        upd(a, b);
    }

    num operator+ (const num &x) { return num(a + x.a, b + x.b); }
    num operator- (const num &x) { return num(a - x.a, b - x.b); }
    num operator* (const num &x) { return num(a*x.a, b*x.b); }
    bool operator== (const num &x) { return a == x.a && b == x.b; }
};

bool isprime(int x) {
    for (int i = 2; i*i <= x; i++) if (x%i == 0) return 0;
    return 1;
}

int ord(char c, bool flag) { return (flag ? c - 'a' : c - '0'); }

struct my_hash {
    char *s;
    int n;
    vector<num> h_s, pw;
    my_hash(char *s, int n) : s(s), n(n), h_s(n+1, 0), pw(n+1, 0) {


        for(int i = 0; i < n; i++)
            h_s[i+1] = h_s[i] * P + (ord(s[i], 1) + 1);



        pw[0] = 1;


        for(int i = 1; i <= n; i++)
            pw[i] = pw[i-1]*P;

    }
    num get(int l, int r) { return h_s[r] - h_s[l]*pw[r-l]; }
};



void init() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    M_1 = buben + rand()%buben, M_2 = buben + rand()%buben;
    while (!isprime(M_1) || !isprime(M_2))
    {
        if (!isprime(M_1)) ++M_1;
        if (!isprime(M_2)) ++M_2;
    }
}

int main() {
    init();

    scanf("%s %s", s, t);

    int n = strlen(s), m = strlen(t);
    int cnt[2] = {}, pos[2] = {-1, -1};
    for (char *cur = s; *cur; cur++) {
        int f = *cur-'0';
        cnt[f]++;
        if (pos[f] == -1) pos[f] = cur-s;
    }

    my_hash hash_str(t, m);
    int ans = 0;
    for (int len0 = 1; len0 < m; len0++) {
        if ( (m - cnt[0] * 1ll * len0) % cnt[1]) continue;

        ll len1 = (m - cnt[0] * 1ll * len0) / cnt[1];
        if (len1 <= 0) continue;


        int skr = (pos[0] == 0 ? 1 : 0);
        int xyi = (skr == 0 ? len1 : len0);
        num H[2] = {
        H[0] = hash_str.get(pos[0]*xyi, pos[0]*xyi+len0),
        H[1] = hash_str.get(pos[1]*xyi, pos[1]*xyi+len1)};

        if (H[0] == H[1]) continue;
        int prev = 0, flag = 1;
        for (int i = 0; i < n && flag; i++) {
            int f = ord(s[i], 0);
            int cur_len = (f == 0 ? len0 : len1);
            flag &= (hash_str.get(prev, prev+cur_len) == H[f]);
            prev += cur_len;
        }
        ans += flag;
    }
    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
