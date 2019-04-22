#include <iostream>
using namespace std;
const int MAXN  = 100000;

int main() {
    //freopen("output.txt", "w", stdout);
    cout << MAXN << " ";
    for (int i = 0; i < MAXN; ++i) {
        cout << 0 << " ";
    }
    cout << MAXN << " ";
    for (int i = 0; i < MAXN; ++i) {
        cout << 0 << " " << 1000000000000000000 << " ";
    }
}
