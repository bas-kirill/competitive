#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using vvi = std::vector<vi>;
using vii = std::vector<pii>;
using vll = std::vector<ll>;
using pll = std::pair<ll, ll>;

#define pb push_back
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define mp(x, y) make_pair(x, y)
#define fst first
#define snd second
#define len(v) (int)(v).size()
#define rall(v) (v).rbegin(), (v).rend()
#define vll vector<ll>
#define vi vector<int>

//mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
int sign(const T& t) {
    return (t > 0) - (t < 0);
}

template<typename A, typename B>
string to_string(const pair <A, B>& p) {
    string str;
    str += "(";
    str += to_string(p.first);
    str += ", ";
    str += to_string(p.second);
    str += ")";
    return str;
}

template<typename T>
string to_string(const vector <T>& vec) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : vec) {
        if (!first) {
            str += ", ";
        }
        str += to_string(it);
        first = false;
    }
    str += " }";
    return str;
}

template<typename T>
string to_string(const set <T>& s) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : s) {
        if (!first) {
            str += ", ";
        }
        str += to_string(it);
        first = false;
    }
    str += " }";
    return str;
}

template<typename K, typename V>
string to_string(const map <K, V>& m) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : m) {
        if (!first) {
            str += ", ";
        }
        first = false;
        str += to_string(it.first);
        str += " -> ";
        str += to_string(it.second);
    }
    str += " }";
    return str;
}

string to_string(const string& s) {
    return "\"" + s + "\"";
}

string to_string(const char* s) {
    return to_string(string(s));
}

string to_string(char ch) {
    return "\'" + string(1, ch) + "\'";
}

template<size_t N>
string to_string(const bitset<N>& b) {
    string res(N, '0');
    for (size_t i = 0; i < N; ++i) {
        res[i] = '0' + b[i];
    }
    return res;
}

template <typename T>
string to_string(const T& t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
}

double get_time() { return static_cast<double>(clock()) / CLOCKS_PER_SEC; }
//void sleep(ll sec) { this_thread::sleep_for(chrono::seconds(sec)); }

/* *************************** TEMPLATE CODE ENDS HERE ******************************** */

#define int long long

int n;
vector<int> v;

void read() {
    cin >> n;
    v.resize(n);
    for (int &x : v) cin >> x;
}

void solve() {
    ll ans = 0;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        ans += v[i] / 3; v[i] = v[i] % 3;
        if (v[i] > 0) {
            for (int j = 1; j <= v[i] + 1; ++j) {
                ind = max(i + 1, ind);
                while (ind < n && v[ind] < 2) ++ind;
                if (ind < n) {
                    v[ind] -= 2;
                    ++ans;
                }
            }
        }
    }
    cout << ans;
}

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.precision(12);
    cout << fixed;
#ifndef ONLINE_JUDGE
    #define FILE_NAME "input"
    freopen(FILE_NAME ".txt", "r", stdin);
    //freopen(FILE_NAME ".out", "w", stdout);
#endif
    read();
    solve();
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/


