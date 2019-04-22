#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout("output.txt");
    cout << 1000 << endl;
    int cnt = 1000000;
    for (int i = 0; i < 1000; i++) {
        cout << cnt-- << " " << cnt-- << endl;
    }
}
