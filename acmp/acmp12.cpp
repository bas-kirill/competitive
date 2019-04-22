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

ld S_Gauss(vector<int> &points) //need tests
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
    int n;
    ifstream cin("in.txt");
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        point O, P, S, Q, R;
        cin >> O >> P >> S >> Q >> R;

        vect PS(P, S), PR(P, R);

        ld S_rect = 2 * abs(kosoe(PS, PR));

        vect P_S(P, S), P_O(P, O);
        vect S_Q(S, Q), S_O(S, O);
        vect Q_R(Q, R), Q_O(Q, O);
        vect R_P(R, P), R_O(R, O);

        ld S1 = abs(kosoe(P_S, P_O));
        ld S2 = abs(kosoe(S_Q, S_O));
        ld S3 = abs(kosoe(Q_R, Q_O));
        ld S4 = abs(kosoe(R_P, R_O));

        //cout << S_rect << " " << S1 << " " << S2 << " " << S3 << " " << S4 << endl;

        if (S1 + S2 + S3 + S4 == S_rect)
        {
            ans++;
        }
    }

    cout << ans;
}

/*
* (Actually read this Pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
