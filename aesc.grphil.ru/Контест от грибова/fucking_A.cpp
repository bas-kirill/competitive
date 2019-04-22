#include <bits/stdc++.h>
using namespace std;

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

#define pb push_back
#define len(c) int((c).size())
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define mp(x, y) make_pair(x, y)
#define vi vector<int>
#define ff first
#define ss second

mt19937 rnd(time(0));

#define x(a) real(a)
#define y(a) imag(a)
using G = ld;
using pnt = complex<ld>;
const ld PI = asin(double(1)) * 2;
const int BASE = 1000000000;
const int BASE_DIG = 9;

typedef long long ll;
typedef long double ld;

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
    a = sg(a), b = sg(b);
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

struct BigInteger {
    vi value;
    int sign;
    int BASE = 1000000000
    int BASE_DIG = 9;

    BigInteger(string &s) { input(s); }

    void input(const string &s) {
        int
    }
};

BigInteger a, b;

bool read() {
    cin >> a >> b;
    return 0;
}

void solve() {
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(12);
    cout << fixed;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
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
