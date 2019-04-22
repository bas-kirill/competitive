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
        return printArray(os,a,len(a));
    }
}

using namespace io;

mt19937 rnd(time(0));

#define x(a) real(a)
#define y(a) imag(a)
using G = ld;
using pnt = complex<ld>;
istream& operator>>(istream &is, pnt &p){G x, y; is >> x >> y; p = {x, y}; return is;}
ostream& operator<<(ostream &os, const pnt &p){os << p.x() << ' ' << p.y(); return os;}
//G crs(const pnt &a, const pnt &b) {return (conj(a)*b).y();}
//G kos(const pnt &a, const pnt &b, const pnt &c) {return crs(b-a, c-b);};
G kos(pnt& P1, pnt& P2, pnt& M1, pnt& M2) { return (P2 - P1).x() * (M2 - M1).y() - (P2 - P1).y() * (M2 - M1).x(); }
G sc(pnt& P1, pnt& P2, pnt& M1, pnt& M2) {  return (P2 - P1).x() * (M2 - M1).x() + (P2 - P1).y() * (M2 - M1).y(); }
const ld PI = asin(double(1)) * 2;

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

namespace inter {
    namespace point {
        bool line(pnt& P1, pnt& P2, pnt& M) {
            if (kos(P1, P2, P1, M) == 0)
                return true;
            else
                return false;
        }

        bool ray(pnt& P1, pnt& P2, pnt& M) {
            if (kos(P1, P2, P1, M) == 0 && sc(P1, P2, P1, M) >= 0)
                return true;
            else
                return false;
        }

        bool seg(pnt& P1, pnt& P2, pnt& M) {
            if (kos(P1, P2, P1, M) == 0 && sc(M, P1, M, P2) <= 0)
                return true;
            else
                return false;
        }
    }

    namespace line {
        bool point(pnt& P1, pnt& P2, pnt& M) {
            return inter::point::line(P1, P2, M);
        }

        bool line(pnt& P1, pnt& P2, pnt& M1, pnt& M2) {
            if (kos(P1, P2, M1, M2) == 0)
                return true;
            else
                return false;
        }

        bool ray(pnt& P1, pnt& P2, pnt& M1, pnt& M2) {
            //TODO
        }

        bool seg(pnt& P1, pnt& P2, pnt& M1, pnt& M2) {
            //TODO
        }
    }

    namespace seg {
//        bool point(pnt& P1, pnt& P2, pnt& M) {
//            //TODO
//        }
//
//        bool line(pnt& P1, pnt& P2, pnt& M1, pnt& M2) {
//            //TODO
//        }
//
//        bool ray(pnt& P1, pnt& P2, pnt& M1, pnt& M2) {
//            //TODO
//        }

        bool seg(pnt& P1, pnt& P2, pnt& M1, pnt& M2) {
            if (kos(P1, P2, P1, M2) * kos(P1, P2, P1, M1) < 0 && kos(M1, M2, M1, P1) * kos(M1, M2, M1, P2) < 0)
                return true;
            else {
                if (inter::point::seg(P1, P2, M1) || inter::point::seg(P1, P2, M2))
                    return true;
                if (inter::point::seg(M1, M2, P1) || inter::point::seg(M1, M2, P2))
                    return true;
                return false;
            }
        }
    }
}

namespace dist {
    namespace point {
        G line(pnt& P1, pnt& P2, pnt& M) {
            return abs(kos(P1, P2, P1, M)) / abs(P2 - P1);
        }

        G ray(pnt& P1, pnt& P2, pnt& M) {
            return sc(P1, M, P1, P2) < 0 ? min(abs(P1 - M), abs(P2 - M)) : line(P1, P2, M);
        }

        G seg(pnt& P1, pnt& P2, pnt& M) {
            if (sc(P1, M, P1, P2) < 0 || sc(P2, M, P2, P1) < 0)
                return min(abs(P1 - M), abs(P2 - M));
            else
                return line(P1, P2, M);
        }
    }

    namespace seg {
        G seg(pnt& P1, pnt& P2, pnt& M1, pnt& M2) {
            if (inter::seg::seg(P1, P2, M1, M2))
                return 0;
            else {
                G mn1 = dist::point::seg(P1, P2, M1);
                G mn2 = dist::point::seg(P1, P2, M2);
                G mn3 = dist::point::seg(M1, M2, P1);
                G mn4 = dist::point::seg(M1, M2, P2);
                return min(min(mn1, mn2), min(mn3, mn4));
            }
        }
    }

    namespace ray {

    }

    namespace line {

    }
}

#define x first
#define y second
using pld = pair<ld, ld>;

pld a1, a2, b1, b2, va, vb;
ld eps = 1e-7;

bool read() {
    cin >> a1.x >> a1.y >> a2.x >> a2.y >>b1.x >>b1.y >> b2.x >> b2.y >> va.x >> va.y >> vb.x >> vb.y;
    return 1;
}

ld dst(pld a, pld b){
return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}

ld distl(pld a1, pld a2, pld p) {
    ld A = a2.y - a1.y;
    ld B = a1.x - a2.x;
    ld C = a2.x*a1.y - a1.x * a2.y;

    return (A * p.x + B*p.y + C) / sqrt(A*A + B*B);
}

ld sprod(pld a, pld b, pld c) {
    ld bax = a.x - b.x;
    ld bay = a.y - b.y;
    ld bcx = c.x - b.x;
    ld bcy = c.y - b.y;

    return bax * bcx + bay * bcy;
}

bool diffs(ld a, ld b) {
    if((a < eps && b > eps) || (a > eps && b < eps)) return 1;
    return 0;
}

ld disto(pld a1, pld a2, pld b1, pld b2){

    ld a1a2b1 = distl(a1, a2, b1);
    ld a1a2b2 = distl(a1, a2, b2);
    ld b1b2a1 = distl(b1, b2, a1);
    ld b1b2a2 = distl(b1, b2, a2);

    if(diffs(a1a2b1, a1a2b2) && diffs(b1b2a1, b1b2a2)) return 0;

    ld res = 1e12;
    res = min(res, dst(a1, b1));
    res = min(res, dst(a1, b2));
    res = min(res, dst(a2, b1));
    res = min(res, dst(a2, b2));

    if(sprod(a1, b1, b2) >= -eps  && sprod(a1, b2, b1) >= -eps) res = min(res, abs(distl(b1, b2, a1)));
    if(sprod(a2, b1, b2) >= -eps  && sprod(a2, b2, b1) >= -eps) res = min(res, abs(distl(b1, b2, a2)));

    if(sprod(b1, a1, a2) >= -eps  && sprod(b1, a2, a1) >= -eps) res = min(res, abs(distl(a1, a2, b1)));
    if(sprod(b2, a1, a2) >= -eps  && sprod(b2, a2, a1) >= -eps) res = min(res, abs(distl(a1, a2, b2)));

    return res;
}

pld v(pld a, pld v, ld m){
    return {a.x + v.x*m, a.y +v.y*m};
}

void solve() {
    ld l = 0, r = 1e15;
    while (r - l > eps) {
        ld m13 = l + 1*(r - l)/3;
        ld m23 = l + 2*(r - l)/3;

        ld q13 = disto(v(a1, va, m13), v(a2, va, m13), v(b1, vb, m13), v(b2, vb, m13));
        ld q23 = disto(v(a1, va, m23), v(a2, va, m23), v(b1, vb, m23), v(b2, vb, m23));

        if (q13 > q23 + eps) l = m13; else r = m23;
    }

    if(disto(v(a1, va, l), v(a2, va, l), v(b1, vb, l), v(b2, vb, l)) > 1e-2 ) cout<< -1;
    else cout<<fixed<<l;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(12);
    cout << fixed;

    read();
    solve();

    return 0;
}

/*
Расстояние от точки A до точки C. x
• Расстояние от точки A до отрезка CD. x
• Расстояние от точки A до луча CD. x
• Расстояние от точки A до прямой CD. x

• Расстояние от отрезка AB до точки C. x
• Расстояние от отрезка AB до отрезка CD.
• Расстояние от отрезка AB до луча CD.
• Расстояние от отрезка AB до прямой CD.

• Расстояние от луча AB до точки C. x
• Расстояние от луча AB до отрезка CD.
• Расстояние от луча AB до луча CD.
• Расстояние от луча AB до прямой CD

• Расстояние от прямой AB до точки C.
• Расстояние от прямой AB до отрезка CD.
• Расстояние от прямой AB до луча CD.
• Расстояние от прямой AB до прямой CD.
*/

/*
1 2
7 1
5 6
8 2
*/

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
