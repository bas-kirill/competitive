#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<double> CC;

#define pb push_back
#define len(c) int((c).size())
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define mp(x, y) make_pair(x, y)
#define vi vector<int>
#define ff first
#define ss second

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int BASE = 1000000000;
const int BASE_DIG = 9;
const double PI = 3.14159265358979323846;

struct BigInteger {
    vi value;
    int sign;

    BigInteger(string &s) { input(s); }
    BigInteger() : sign(1) {}           //null
    BigInteger(ll v) { *this = v; }

    void cl() {
        while (!value.empty() && value.back() == 0) value.pop_back();
        if (value.empty()) sign = 1;
    }

    void input(string &s) {
        sign = 1;
        value.clear();
        int ind = 0;
        while (ind < len(s) && (s[ind] == '-' || s[ind] == '+')) {
            if (s[ind] == '-')
                sign = -sign;
            ++ind;
        }
        for (int i = len(s) - 1; i >= ind; i -= BASE_DIG) {
            int x = 0;
            for (int j = max(ind, i - BASE_DIG + 1); j <= i; ++j)
                x = x * 10 + s[j] - '0';
            value.pb(x);
        }
        cl();
    }

    BigInteger operator-() const { BigInteger res = *this; res.sign = -sign; return res; }
    BigInteger operator/(const BigInteger &v) const { return divmod(*this, v).ff; }
    BigInteger operator%(const BigInteger &v) const { return divmod(*this, v).ss; }
    BigInteger operator/(int v) const { BigInteger res = *this; res /= v; return res; }
    BigInteger operator*(int v) const { BigInteger res = *this; res *= v; return res; }

    void operator+=(const BigInteger &v) { *this = *this + v; }
    void operator-=(const BigInteger &v) { *this = *this - v; }
    void operator*=(const BigInteger &v) { *this = *this * v; }
    void operator/=(const BigInteger &v) { *this = *this / v; }
    void operator=(const BigInteger &v) { value = v.value, sign = v.sign; }

    bool operator>(const BigInteger &v) const { return v < *this; }
    bool operator<=(const BigInteger &v) const { return !(v < *this); }
    bool operator>=(const BigInteger &v) const { return !(*this < v); }
    bool operator==(const BigInteger &v) const { return !(*this < v) && !(v < *this); }
    bool operator!=(const BigInteger &v) const { return *this < v || v < *this; }
    bool operator<(const BigInteger &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (len(value) != len(v.value))
            return len(value) * sign < len(v.value) * v.sign;
        for (int i = len(value) - 1; i >= 0; i--)
            if (value[i] != v.value[i])
                return value[i] * sign < v.value[i] * sign;
        return 0;
    }
    int operator%(int v) const {
        if (v < 0) v = -v;
        int m = 0;
        for (int i = len(value) - 1; i >= 0; --i)
            m = (value[i] + m * (ll) BASE) % v;
        return m * sign;
    }
    void operator/=(int v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = len(value) - 1, rem = 0; i >= 0; --i) {
            ll cur = value[i] + rem * ll(BASE);
            value[i] = int(cur / v);
            rem = int(cur % v);
        }
        cl();
    }
    void operator=(ll v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        value.clear();
        for (; v > 0; v = v / BASE)
            value.pb(v % BASE);
    }
    //check emaxx
    BigInteger operator+(const BigInteger &v) const {
        if (sign == v.sign) {
            BigInteger res = v;

            for (int i = 0, carry = 0; i < max(len(value), len(v.value)) || carry; ++i) {
                if (i == len(res.value))
                    res.value.pb(0);
                res.value[i] += carry + (i < len(value) ? value[i] : 0);
                carry = res.value[i] >= BASE;
                if (carry)
                    res.value[i] -= BASE;
            }
            return res;
        }
        return *this - (-v);
    }
    //check emaxx
    BigInteger operator-(const BigInteger &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                BigInteger res = *this;
                for (int i = 0, carry = 0; i < len(v.value) || carry; ++i) {
                    res.value[i] -= carry + (i < len(v.value) ? v.value[i] : 0);
                    carry = res.value[i] < 0;
                    if (carry)
                        res.value[i] += BASE;
                }
                res.cl();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
    //check emaxx
    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < len(value) || carry; ++i) {
            if (i == len(value))
                value.pb(0);
            ll cur = value[i] * (ll) v + carry;
            carry = int(cur / BASE);
            value[i] = int(cur % BASE);
        }
        cl();
    }
    //smart
    BigInteger operator*(const BigInteger &v) const {
        vector<int> c = FFTMultiply(
            TRANSFORMER(this->value, BASE_DIG, 2),
            TRANSFORMER(v.value, BASE_DIG, 2)
        );
        BigInteger res;
        res.sign = sign * v.sign;
        res.value = TRANSFORMER(c, 2, BASE_DIG);
        res.cl();
        return res;
    }

    friend pair<BigInteger, BigInteger> divmod(const BigInteger &a1, const BigInteger &b1) {
        int norm = BASE / (b1.value.back() + 1);
        BigInteger a = a1.abs() * norm, b = b1.abs() * norm;
        BigInteger q, r;
        q.value.resize(len(a.value));

        for (int i = len(a.value) - 1; i >= 0; i--) {
            r *= BASE;
            r += a.value[i];
            int s1 = len(b.value) < len(r.value) ? r.value[len(b.value)] : 0;
            int s2 = len(b.value) - 1 < len(r.value) ? r.value[len(b.value) - 1] : 0;
            int d = ((ll) s1 * BASE + s2) / b.value.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.value[i] = d;
        }
        r.sign = a1.sign, q.sign = a1.sign * b1.sign;
        r.cl(); q.cl();
        return mp(q, r / norm);
    }

    bool is_zero() const { return value.empty() || (len(value) == 1 && !value[0]); }
    BigInteger abs() const { BigInteger res = *this;res.sign *= res.sign; return res; }

    ll longValue() const {
        ll res = 0;
        for (int i = len(value) - 1; i >= 0; --i) res = res * BASE + value[i];
        return res * sign;
    }

    static vi TRANSFORMER(const vi &a, int old_digits, int new_digits) {
        vector<ll> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < len(p); ++i)
            p[i] = p[i - 1] * 10;
        vi res;
        ll cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); ++i) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.pb(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.pb(int(cur));
        while (!res.empty() && res.back() == 0)
            res.pop_back();
        return res;
    }

    static void FFT (vector<CC> &a, bool invert) {
	    int n = len(a);
	    if (n == 1)  return;

	    vector<CC> a0 (n/2),  a1 (n/2);
	    for (int i=0, j=0; i<n; i+=2, ++j)
	        a0[j] = a[i], a1[j] = a[i+1];

	    FFT(a0, invert);
	    FFT(a1, invert);

	    double ang = 2*PI/n * (invert ? -1 : 1);
	    CC w(1),  wn(cos(ang), sin(ang));
	    for (int i = 0; i < n / 2; ++i) {
		    a[i] = a0[i] + w * a1[i];
		    a[i+n/2] = a0[i] - w * a1[i];
		    if (invert) a[i] /= 2,  a[i+n/2] /= 2;
		    w *= wn;
	    }
    }

    static vi FFTMultiply(const vi &a, const vi &b) {
    	vector<CC> fa (all(a)),  fb (all(b));
    	int n = 1;
    	while (n < max(len(a), len(b)))  n <<= 1; //shift
    	n <<= 1;
    	fa.resize (n), fb.resize (n);

    	FFT(fa, 0),  FFT(fb, 0);
    	for (int i = 0; i < n; ++i)
    		fa[i] *= fb[i];
    	FFT(fa, 1);

    	vi res(n);
    	for (int i = 0; i < n; ++i)
    		res[i] = int(fa[i].real() + 0.5);

    	int carry = 0;
	    for (int i = 0; i < n; ++i) {
		    res[i] += carry;
		    carry = (res[i] / 100);
		    res[i] %= 100;
	    }
	    while (len(res) > 1 && res.back() == 0) res.pop_back();
	    return res;
	}
};

istream& operator>>(istream &i, BigInteger &v) {
    string s; i >> s;
    v.input(s);
    return i;
}

ostream& operator<<(ostream &kek, const BigInteger &v) {
    if (v.sign == -1) kek << '-';
    kek << (v.value.empty() ? 0 : v.value.back());
    for (int i = (int) v.value.size() - 2; i >= 0; --i)
        kek << setw(BASE_DIG) << setfill('0') << v.value[i];
    return kek;
}

int main() {
    freopen("input.txt", "r+", stdin);
    BigInteger a, b, c;
    cin >> a >> b;
    cout << a * b;
}
/*
friend pair<BigInteger, BigInteger> divmod(const BigInteger &a1, const BigInteger &b1) {
        int norm = BASE / (b1.value.back() + 1);
        BigInteger a = a1.abs() * norm;
        BigInteger b = b1.abs() * norm;
        BigInteger q, r;
        q.value.resize(len(a.value));

        for (int i = len(a.value) - 1; i >= 0; i--) {
            r *= BASE;
            r += a.value[i];
            int s1 = len(b.value) < len(r.value) ? r.value[len(b.value)] : 0;
            int s2 = len(b.value) - 1 < len(r.value) ? r.value[len(b.value) - 1] : 0;
            int d = ((ll) s1 * BASE + s2) / b.value.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.value[i] = d;
        }
        r.sign = a1.sign, q.sign = a1.sign * b1.sign;
        r.cl(); q.cl();
        return mp(q, r / norm);
    }

    BigInteger operator/(const BigInteger &v) const { return divmod(*this, v).ff; }
    BigInteger operator%(const BigInteger &v) const { return divmod(*this, v).ss; }
    void operator/=(const BigInteger &v) { *this = *this / v; }
    bool is_zero() const { return value.empty() || (len(value) == 1 && !value[0]); }

*/
