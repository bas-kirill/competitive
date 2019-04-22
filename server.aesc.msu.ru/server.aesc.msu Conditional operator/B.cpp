#include <bits/stdc++.h>
using namespace std;

int main(){

    int x1,y1,x2,y2;

    string white1="", black1="";
    string white2="", black2="";

    cin>>x1>>y1>>x2>>y2;

    int ostx1 = x1%2;
    int osty1 = y1%2;
    int ostx2 = x2%2;
    int osty2 = y2%2;

    if((ostx1==1 && osty1==1) || (ostx1==0 && osty1==0)){  //black
        if((ostx2==1 && osty2==0) || (ostx2==0 && osty2==1)){  //white
            cout<<"NO";
            return 0;
        }
        else {
            cout<<"YES";
            return 0;
        }
    }else {
        if((ostx2==1 && osty2==0) || (ostx2==0 && osty2==1)){  //white
            cout<<"YES";
            return 0;
        }else {
            cout<<"NO";
            return 0;
        }
    }



    if((black1==black2) || (white1==white2)){

    }
}
