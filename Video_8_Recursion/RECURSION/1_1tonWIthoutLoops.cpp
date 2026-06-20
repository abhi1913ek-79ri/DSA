#include<bits/stdc++.h>
using namespace std;
int cnt =1;
    // Complete this function
void printNos(int n) {
    // Your code here
    if(cnt==(n+1)){
        return;
    }else{
        cout<<cnt<<" ";
        cnt++;
        printNos(n);
    }
}

int main(){
    printNos(10);
    
    return 0;
}