#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1)
    {
        cout << "YES";
        return 0;
    }
    else if (n == 2)
    {
        if (s[0] == s[1])
        {
            cout << "YES";
            return 0;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    int sum1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum1 += s[i] - '0';
        int pos = i + 1;
        int sum2 = 0;
        bool ok = true;
        while (pos < n)
        {
            sum2 = s[pos] - '0';
            ++pos;
            while (pos < n && sum2 + s[pos] - '0' <= sum1)
            {
                sum2 += s[pos] - '0';
                ++pos;
            }

            if (sum1 != sum2)
            {
                ok = false;
            }
        }

        if (ok)
        {
            puts("YES");
            return 0;
        }
    }

    puts("NO");
}
