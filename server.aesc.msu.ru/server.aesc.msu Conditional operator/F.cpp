#include<bits/stdc++.h>
using namespace std;

void resort(int &A, int &B, int &C)
{
    int mn = A, mx = C;
    if (mn > B) mn = B;
    if (mx < B) mx = B;
    if (mn > C) mn = C;
    if (mx < A) mx = A;
    B = A + B + C - mn - mx;
    A = mn;
    C = mx;
}

int main(){
    int A1, B1, C1;
    int A2, B2, C2;
    cin >> A1 >> B1 >> C1;
    cin >> A2 >> B2 >> C2;

    resort(A1, B1, C1);
    resort(A2, B2, C2);

    if ((A1 == A2) && (B1 == B2) && (C1 == C2)) {
        cout << "Boxes are equal";
    }
    else
    {
        if ((A1 <= A2) && (B1 <= B2) && (C1 <= C2))
        {
            cout << "The first box is smaller than the second one";
        }
        else if ((A2 <= A1) && (B2 <= B1) && (C2 <= C1))
        {
            cout << "The first box is larger than the second one";
        }
        else
        {
            cout << "Boxes are incomparable";
        }
    }
}
