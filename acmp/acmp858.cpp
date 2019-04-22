#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define int ld

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

struct point {
    ld x, y;
    point () : x(0), y(0) {}
    point(ld x, ld y) : x(x), y(y) {}
};

struct vect {
    ld x, y;
    vect() : x(0), y(0) {}
    vect(point& a, point& b)
    {
        x = b.x - a.x, y = b.y - a.y;
    }
};

struct line {
    ld A, B, C;
};

line make_line(point a, point b)
{
    long long A = a.y - b.y;
    long long B = b.x - a.x;
    long long C = a.x * b.y - b.x * a.y;

    return {A, B, C};
}

int get_sign_line(line l, point a) //1 - poisitive, 0 - zero , -1 - negative
{
    int sign = l.A * a.x + l.B * a.y + l.C;
    return sign;
}

ld kosoe(vect a, vect b)
{
    return (a.x * b.y - a.y * b.x);
}

ld scalar(vect a, vect b)
{
    return (a.x * b.x + a.y * b.y);
}

bool sign(ld x)
{
    return (x >= 0);
}

istream& operator>>(istream& i, point& a)
{
    ld x, y;
    i >> x >> y;
    a = point(x, y);
    return i;
}

ostream &operator<<(ostream &o, point a)
{
    o << a.x << " " << a.y;
    return o;
}

istream &operator>>(istream &i, line &l)
{
    ld A, B, C;
    i >> A >> B >> C;
    l = {A, B, C};
    return i;
}

ostream &operator<<(ostream &o, line l)
{
    o << l.A << ' ' << l.B << ' ' << l.C;
    return o;
}

/*ld S_Gauss(vector<point> &points) //need tests
{
    int n = len(points);
    ld S1 = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S1 += points[i].x * points[(i + 1) % n].y;
    }

    for (int i = 0; i < n; i++)
    {
        S2 -= points[(i + 1) % n].x * points[i].y;
    }

    ld ans = abs(S1 + S2) / 2;
    return ans;
}*/



main() {
    ifstream cin("in.txt");
    line _0, _1, _2;
    cin >> _0 >> _1 >> _2;

    point A, B, C;


    ld x1 = (_0.C * _1.B - _1.C * _0.B) / (_0.A * _1.B - _1.A * _0.B);
    ld y1 = (_0.A * _1.C - _1.A * _0.C) / (_0.A * _1.B - _1.A * _0.B);

    A = {x1, y1};

    ld x2 = (_1.C * _2.B - _2.C * _1.B) / (_1.A * _2.B - _2.A * _1.B);
    ld y2 = (_1.A * _2.C - _2.A * _1.C) / (_1.A * _2.B - _2.A * _1.B);

    B = {x2, y2};

    ld x3 = (_0.C * _2.B - _2.C * _0.B) / (_0.A * _2.B - _2.A * _0.B);
    ld y3 = (_0.A * _2.C - _2.A * _0.C) / (_0.A * _2.B - _2.A * _0.B);

    C = {x3, y3};

    //cout << A << " " << B << " " << C << endl;

    vect AB(A, B), AC(A, C);
    cout.precision(3);
    cout << fixed << abs(kosoe(AB, AC)) / 2;

    //cout << delta_1 << " " << delta_1_x;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
