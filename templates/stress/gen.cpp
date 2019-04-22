#include<bits/stdc++.h>

using namespace std;

int main(){
        ofstream cout("input.txt");

    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    long long n = 1e6;
    printf("%d\n", n);
    cout << rng() % n;
}
