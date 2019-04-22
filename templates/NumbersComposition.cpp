#include <iostream>
#include <vector>
using namespace std;

void composition(int n) {
    vector<int> a(n, 1);
    while (a[0] != n) {
        for (int x : a) cout << x << " "; cout << endl;
        int x = 1e9, ind;
        for (int i = 0; i < a.size() - 1; ++i)
            if (a[i] < x) x = a[i], ind = i;

        a[ind] += 1;
        a[a.size() - 1] -= 1;

        if (a[a.size() - 1] == 0) a.pop_back();

        for (int j = a.size() - 1; j >= ind + 1; --j) a.pop_back();
        int sum = 0; for (int y : a) sum += y;

        for (int j = 0; j < n - sum; ++j) a.push_back(1);
    }
    cout << n << endl;
}

int main() {
    int n; cin >> n;

    composition(n);
}
