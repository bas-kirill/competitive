#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define DEBUG 0

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<pii>;
using vll = vector<ll>;
using pll = pair<ll, ll>;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define pb push_back
#define len(c) int((c).size())
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define mp(x, y) make_pair(x, y)
#define fst first
#define snd second
#define vi vector<ll>

namespace io {
    // Source: StackOverflow

    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O

    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (len(s)) { setIn(s+".in"), setOut(s+".out"); }
    }

    // INPUT

    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); }
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        for (int i = 0; i < len(a); i++) is >> a[i];
        return is;
    }

    // OUTPUT

    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        cout << first << ' '; pr(rest...);
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }

    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        for (int i = 0; i < SZ; i++) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }

    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

mt19937 rnd(time(0));

template<typename T>
int sign(const T& t) {
    return (t > 0) - (t < 0);
}

template<typename T>
void make_unique(vector<T>& v) {
    sort(all(v));
    v.erase(std::unique(all(v)), end(v));
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

string to_string(const string& s) { return "\"" + s + "\""; }
string to_string(const char* s) { return to_string(string(s)); }
string to_string(char ch) { return "\'" + string(1, ch) + "\'"; }

template<size_t N>
string to_string(const bitset<N>& b) {
    string res(N, '0');
    for (size_t i = 0; i < N; ++i) {
        res[i] = '0' + b[i];
    }
    return res;
}

template <typename T>
string to_string(const T& t) { stringstream ss; ss << t; return ss.str(); }

template<typename T>
T gcd(T a, T b) {
    a = abs(a), b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

template<typename T>
T lcm(T a, T b) {
    a = abs(a), b = abs(b);
    return a / gcd(a, b) * b;
}

double get_time() { return static_cast<double>(clock()) / CLOCKS_PER_SEC; }

void sleep(ll sec) { this_thread::sleep_for(chrono::seconds(sec)); }

/* *************************** TEMPLATE CODE ENDS HERE ******************************** */

int a, b, c, d;
vi start;

bool read() {
    start.resize(3); //init
    re(a, b, c, d);
    re(start[0], start[1], start[2]);
    return 1;
}

vi go(vi seq) {
    return {seq[1], seq[2], (a*seq[2]%d + b*seq[1]%d + c*seq[0]%d) % d};
}

void solve() {
    vi ptr_1 = start, ptr_2 = go(start);

    while (ptr_1 != ptr_2) {
        if (DEBUG) cout << "1 " << to_string(ptr_2) << endl;
        ptr_1 = go(ptr_1), ptr_2 = go(go(ptr_2));
    }

    int period = 1;
    ptr_2 = go(ptr_2);
    while (ptr_1 != ptr_2) {
        if (DEBUG) cout << "2 " << to_string(ptr_2) << endl;
        ptr_2 = go(ptr_2);
        ++period;
    }

    ptr_1 = start, ptr_2 = start;
    for (int i = 0; i < period; ++i) {
        if (DEBUG) cout << "3 " << to_string(ptr_2) << endl;
        ptr_2 = go(ptr_2);
    }

    int preperiod = 0;
    while (ptr_1 != ptr_2) {
        ptr_1 = go(ptr_1), ptr_2 = go(ptr_2);
        ++preperiod;
    }

    vi cnt(20), x = start;
    for (int i = 0; i < 400; ++i) {
        if (DEBUG) cout << "4 " << to_string(ptr_2) << endl;
        ++cnt[int(20 * (double(x[0]) / double(d)))]; //?
        x = go(x);
    }

    ld ok = 0;
    for (int i = 0; i < 20; ++i) {
        if (DEBUG) cout << "5 " << endl;
        ok += (cnt[i] - 20) * (cnt[i] - 20);
    }
    ok /= 400;

    pr("Period: ", period, "Preperiod:", preperiod, "Horoshest:", ok);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(5);
    cout << fixed;

    freopen("in.txt", "r", stdin);

    read();
    solve();
    cout.flush();

    return 0;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
