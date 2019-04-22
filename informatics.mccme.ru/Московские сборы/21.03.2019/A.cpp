#include <iostream>
using namespace std;

int big = 2100000000;

int main() {
    int n;
    cin >> n;
    int mx_2 = -big, mx_11 = -big, mx_22 = -big;
    int neg_mx_2 = big, neg_mx_11 = big, neg_mx_22 = big;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (num > 0) {
            if (num % 22 == 0) {
                mx_22 = max(mx_22, a[i]);
                continue;
            } else if (num % 2 == 0)
                mx_2 = max(mx_2, a[i]);
            else if (num % 11 == 0)
                mx_11 = max(mx_11, a[i]);
        } else {
            if (num % 22 == 0) {
                neg_mx_22 = max(neg_mx_22, a[i]);
                continue;
            } else if (num % 2 == 0)
                neg_mx_2 = min(neg_mx_2, a[i]);
            else if (num % 11 == 0)
                neg_mx_11 = min(neg_mx_11, a[i]);
        }
    }

    int ans1 = mx_2 * mx_11;
    int ans2 = mx_2 * mx_22;
    int ans3 = mx_11 * mx_22;
    int ans4 = neg_mx_2 * neg_mx_11;
    int ans5 = neg_mx_2 * neg_mx_22;
    int ans6 = neg_mx_11 * neg_mx_22;

    int ans = max(ans1, max(ans2, max(ans3, max(ans4, max(ans5, ans6)))));

    cout << ans;
}
