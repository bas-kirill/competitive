#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

struct point {
    long double x, y;
    point () : x(0), y(0) {}
    point(long double x, long double y) : x(x), y(y) {}
};

struct vect {
    long double x, y;
    long double len = 0;
    vect() : x(0), y(0) {}
    vect(point& a, point& b)
    {
        x = b.x - a.x, y = b.y - a.y;
        len = sqrtl(x*x + y*y);
    }
};

struct line {
    long long A, B, C;
};

line make_line(point a, point b)
{
    long long A = a.y - b.y;
    long long B = b.x - a.x;
    long long C = a.x * b.y - b.x * a.y;

    return {A, B, C};
}

bool operator==(point a, point b)
{
    if (a.x == b.x && a.y == b.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(line a, line b)
{
    if (a.A == b.A && a.B == b.B && a.C == b.C)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(point a, point b)
{
    if (a.x != b.x || a.y != b.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(line a, line b)
{
    if (a.A != b.A || a.B != b.B || a.C != b.C)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int get_sign_line(line l, point a) //1 - poisitive, 0 - zero , -1 - negative
{
    int sign = l.A * a.x + l.B * a.y + l.C;
    return sign;
}

long double kosoe(vect a, vect b)
{
    return (a.x * b.y - a.y * b.x);
}

long double scalar(vect a, vect b)
{
    return (a.x * b.x + a.y * b.y);
}

bool sign(long double x)
{
    return (x >= 0);
}

istream& operator>>(istream& i, point& a)
{
    long double x, y;
    i >> x >> y;
    a = point(x, y);
    return i;
}

ostream &operator<<(ostream &o, point a)
{
    o << a.x << " " << a.y;
    return o;
}

ostream &operator<<(ostream &o, line l)
{
    o << l.A << ' ' << l.B << ' ' << l.C;
    return o;
}

long double S_Gauss(vector<point> &points) //need tests
{
    int n = len(points);
    long double S1 = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S1 += points[i].x * points[(i + 1) % n].y;
    }

    for (int i = 0; i < n; i++)
    {
        S2 -= points[(i + 1) % n].x * points[i].y;
    }

    long double ans = abs(S1 + S2) / 2;
    return ans;
}

int main() {
    point A, B, C;
    cin >> A >> B >> C;

    if (A == B && B == C)
    {
        //0
        cout << 0;
        return 0;
    }
    else
    {
        //1
        if (A == B)
        {
            if (B != C)
            {
                cout << 1;
                return 0;
            }
        }
        else if (A == C)
        {
            if (A != B)
            {
                cout << 1;
                return 0;
            }
        }
        else if (B == C)
        {
            if (A != B)
            {
                cout << 1;
                return 0;
            }
        }
    }


    //2
    if ((A.y - C.y) * (B.x - C.x) == (B.y - C.y) * (A.x - C.x))
    {
        cout << 2;
        return 0;
    }

    vect AB(A, B), AC(A, C), BC(B, C);

    long double a = AB.len;
    long double b = AC.len;
    long double c = BC.len;

    vector<long double> lens;
    lens.push_back(a);
    lens.push_back(b);
    lens.push_back(c);

    sort(all(lens));

    a = lens[2];
    b = lens[1];
    c = lens[0];

    long double cos_a = (int(((b*b + c*c - a*a) / (2*b*c) * 10000))) / 10000.0;
//    cout << a << " " << b << " " << c << "\n";
//    cout << a*a << " " << b*b << " " << c*c << "\n";
//    cout << cos_a << "\n";

    if(cos_a > 0)
    {
        cout << 3;
        return 0;
    }
    else if (cos_a == 0)
    {
        cout << 4;
        return 0;
    }
    else if (cos_a < 0)
    {
        cout << 5;
        return 0;
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
