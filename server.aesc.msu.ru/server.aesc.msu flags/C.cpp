#include <iostream>
#include <vector>
using namespace std;

int f(int &n)
{
    int sum = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i * i < n)
            {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int mx_sum = 0;
    int ans = -1;
    for (int i = n; i >= (n > 25000 ? n - 25000 : 1); --i)
    {
        int sum = f(i);
        //cout << i << ' ' <<  sum << '\n';
        if (sum > mx_sum)
        {
            mx_sum = sum;
            ans = i;
        }
    }

    cout << ans;
}
