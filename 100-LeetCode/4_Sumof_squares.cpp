#include<bits/stdc++.h>
using namespace std;
// sum of squres numbers or
// Two pointers / binary search approach

// brute 
bool judgeSquareSum1(int c){
    for(int i =0 ;i*i<=c;i++){
        for (int j = 0; j*j <= c; j++)
        {
            if(i*i+j*j == c) return true;
        }
    }

    return false;
    // TC = O(c)
    // SC = O(1)
}


// optimal two pointers
bool judgeSquareSum(int c) {
    long l = 0;
    long r = sqrt(c);
    while (l<=r)
    {
        if(l*l+r*r - 1LL*c==0) return true;
        else{
            if(l*l+r*r < 1LL*c) l++;
            else r--;
        }
    }
    return false;
    // TC = O(sqrt(c))
    // SC = O(1)
}

// optimal - binary search  
bool judgeSquareSum2(int c) {
    for(int i =0 ;i*i<=c;i++){
        int  target = c - i*i;
        int l = 0;
        int r = sqrt(target);
        while (l<=r)
        {
            int mid = (l+r)/2;
            if(1LL*mid*mid == target) return true;
            else{
                if(1LL*mid*mid < target) l=mid+1;
                else r=mid-1;
            }
        }
        
    }
    return false;
    // TC = O(sqrt(c).logc)
    // SC = O(1)
}



int main(){
    int n = 3;
    bool isSumSqr = judgeSquareSum2(n);
    cout << "n = " << n << " is sum of squres : " << isSumSqr << endl;
    
    return 0;
}