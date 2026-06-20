#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given two numbers N and M, find the Nth root of M. 
// The nth root of a number M is defined as a number X when raised to the power N equals M.
// If the 'nth root is not an integer, return -1.

// Examples
// Example 1:
// Input Format:
//  N = 3, M = 27
// Result:
//  3
// Explanation:
//  The cube root of 27 is equal to 3.

// instead of calculating pow(x,m) just return  to remove overflow 
int checkValidity(int n,int m,int mid){
    //return 1 if == m means valid
    // return 2 if > m  mean move high
    //return 0 if < m move low
    long long ans =1;
    for(int i=1;i<=n;i++){
        ans*=mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}

int nthRoot(int n,int m){
    int low=1;int high=m;
    while (low<=high){
        int mid=low+(high-low)/2;
        int check=checkValidity(n,m,mid);
        if(check==1) return mid;
        else if(check==0) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    cout <<"nthRoot(3, 27) = "<<nthRoot(3, 27) << endl;  // Output: 3
    cout <<"nthRoot(2, 16) = "<<nthRoot(2, 16) << endl;  // Output: 4
    cout <<"nthRoot(2, 10) = "<<nthRoot(2, 10) << endl;  // Output: -1 (No perfect square root)
    return 0;
}