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
    //ifstream cin("in.txt");
    point O;
    cin >> O;
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        point A, B, C;
        cin >> A >> B >> C;

        vect AB(A, B), AO(A, O);
        vect BC(B, C), BO(B, O);
        vect CA(C, A), CO(C, O);

        ld S1 = abs(kosoe(AB, AO)) / 2;
        ld S2 = abs(kosoe(BC, BO)) / 2;
        ld S3 = abs(kosoe(CA, CO)) / 2;

        vect AC(A, C);
        ld S = abs(kosoe(AB, AC)) / 2;
        //cout << S << " " << S1 << ' ' << S2 << ' ' << S3 << endl;
        if (S1 + S2 + S3 == S && S1 != 0 && S2 != 0 && S3 != 0)
        {
            ans.push_back(i + 1);
        }
    }

    sort(all(ans));
    cout << len(ans) << endl;
    for (int x : ans) cout << x << " ";
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
