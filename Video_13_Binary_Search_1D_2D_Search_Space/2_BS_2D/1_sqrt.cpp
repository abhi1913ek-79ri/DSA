#include<bits/stdc++.h>
using namespace std;
//Problem Statement: You are given a positive integer n.
//  Your task is to find and return its square root. 
//  If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

int squarRootBrute(int n){
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(i*i<=n){
            ans=i;
        }else{
            break;
        }
    }
    return ans;
    // O(N)
}
int squarRootBetter(int n){
    int ans=-1;
    for(int i=1;i*i<=n;i++){
        if(i*i<=n){
            ans=i;
        }else{
            break;
        }
    }
    return ans;
    //O(sqrt(N))
}
int squarRootOptimal(int n){
    if (n == 0 || n == 1) return n; // Handling edge cases

    int low = 0, high = n, ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2; // Use long long to prevent overflow

        if (mid * mid == n) return mid; // Perfect square case
        if (mid * mid < n) { 
            ans = mid; // Store potential answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
    // log(N)
    
}
int main(){
    int n=28;
    cout<<"sqrt("<<n<<") ="<<squarRootBrute(n)<<endl;
    cout<<"sqrt("<<n<<") ="<<squarRootBetter(n)<<endl;
    cout<<"sqrt("<<n<<") ="<<squarRootOptimal(n)<<endl;


    
    return 0;
}