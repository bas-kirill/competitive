#include <bits/stdc++.h>
using namespace std;

int main(){
    long double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(2);

    long double x1, x2;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << -1;
            }
            else
            {
                cout << 0;
            }
        }
        else
        {
            x1 = -c / b;
            cout << 1 << " " << x1;
        }
    }
    else
    {
        long double D = b * b - 4 * a * c;

        if (D > 0)
        {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            cout << 2 << " " << min(x1, x2) << " " << max(x1, x2);
        }
        else
        {
            if (D == 0) {
                x1 = (-b) / (2 * a);
                cout << 3 << " " << x1;
            }
            else
            {
                cout << 0;
            }
        }
    }
}
