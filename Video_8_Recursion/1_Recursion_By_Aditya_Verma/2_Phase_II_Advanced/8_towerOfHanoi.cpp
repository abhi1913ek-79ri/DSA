#include<bits/stdc++.h>
using namespace std;
// Tower Of hanoi
void solve(int n,int s,int h,int d){
    // base
    if(n == 1){
        cout << "Move " << n <<"th Disc from tower-"<< s <<" to tower-" << d <<endl;
        return;
    }

    // induction
    solve(n-1,s,d,h);
    cout << "Move " << n <<"th Disc from tower-"<< s <<" to tower-" << d <<endl;
    solve(n-1,h,s,d);
}

int main(){
    int n = 3;
    solve(n,1,2,3);
    return 0;
}