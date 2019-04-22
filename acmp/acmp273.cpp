#include <iostream>
#include <string>
#include <set>

using namespace std;

unsigned long long deletion(const string &str)
{
    int n = str.length();
    if (n < 3) return 0;

    std::set<int> nn;

    for (int i = 0; i < n - 2; ++i)
    {
        if (str[i] == '0') continue;
        for (int j = i + 1; j < n - 1; ++j)
            for (int k = j + 1; k < n; ++k)
                nn.insert((str[i] - '0') * 100 + (str[j] - '0') * 10 + (str[k] - '0'));
    }

    return nn.size();
}

int main()
{
    string s;
    cin >> s;
    cout << deletion(s);
    return 0;
}
