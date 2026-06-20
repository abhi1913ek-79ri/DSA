#include<bits/stdc++.h>
using namespace std;


// fun
void fun(int& cnt){
    // base condition
    if(cnt == 5) return;
    cout<<cnt<<" ";
    cnt++;
    fun(cnt);
    cnt--;
    cout<<cnt<<" "; 
}

// Done print name 5 times
void f1(int& cnt){
    if(cnt == 5) return;

    cout<<"Name-"<<cnt+1<<endl;
    cnt++;
    f1(cnt);
}

// 2 - print 1 to n
void f2(int i,int n){
    if(i>n) return;

    cout << i <<" ";

    f2(++i,n);

}

// 3 - print n to 1
void f3(int n){
    if(n==0) return;
    cout<<n<<" ";
    f3(n-1);
}

// 4 - print n to 1
void f4(int i,int n){
    if(n-i==0) return;
    cout<<n-i<<" ";
    f4(i+1,n);
}

// Backtracking 

// 1 to n but by backtracking
void f5(int i, int n){
    if(i<1) return;

    f5(i-1,n);  // n ka use nhi kar re hain fir bhi pass kar re hain kyunki shuruat me n chahiye and functionnrecursion wala hain
    cout<<i<<" ";
}

// n to 1 but by backtracking
void f6(int i, int n){
    if(i>n) return;
    // i ki value yahan pe conserved rah ja rahi hain 
    f6(i+1,n);  // n ka use nhi kar re hain fir bhi pass kar re hain kyunki shuruat me n chahiye and functionnrecursion wala hain
    cout<<i<<" ";
}



int main(){
    int n = 5;
    f6(1,n);
    return 0;
}