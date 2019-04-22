#include <bits/stdc++.h>
using namespace std;
using ld = long double;

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
    long long A, B, C;
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

ostream &operator<<(ostream &o, line l)
{
    o << l.A << ' ' << l.B << ' ' << l.C;
    return o;
}

ld S_Gauss(vector<point> &points) //need tests
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
}



int main() {
    ifstream cin("in.txt");
    point O;
    ld R;
    cin >> O >> R;
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        point P = points[i];
        line l = make_line(O, P);
        int neg_cnt = 0;
        int pos_cnt = 0;
        for (int j = 0; j < n; j++)
        {
            point Pi = points[j];
            if ((Pi.x - O.x)*(Pi.x - O.x) + (Pi.y - O.y)*(Pi.y - O.y) <= R * R)
            {
                if (get_sign_line(l, Pi) >= 0)
                {
                    ++pos_cnt;
                }
                else
                {
                    ++neg_cnt;
                }
            }
        }

        ans = max(ans, max(pos_cnt, neg_cnt));
    }

    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
