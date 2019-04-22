#include<bits/stdc++.h>
using namespace std;
int main(){
    cin >> n;

    while(n > 3)
    {
        for(int i = 0; i < n/2 + n%2; i++)
        {
            cout<<k<<' ';
        }
        n /= 2;
        k *= 2;
    }

    if(n == 1) cout<<k;
    if(n == 2) cout<<k<<' '<<2*k;
    if(n == 3) cout<<k<<' '<<k<<' '<<3*k;
}
