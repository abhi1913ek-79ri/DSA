#include<bits/stdc++.h>
using namespace std;
// ALL elements +ve and 0 
int longestSubarrayKBrute(vector<int>& arr, int k) {
    // code here
    int n=arr.size();
    int len=0;
    for(int i=0;i<n;i++){
        int s=0; 
        for(int j=i;j<n;j++){
            s+=arr[j];
            if(s == k){
                len=max(j-i+1,len);
            }
        }
    }
    return len;
}
//Optimal For positive 
int longestSubarrayKOptimal(vector<int>& arr, int k) {
    // code here
    int n=arr.size();
    int left=0;int right=0;
    int maxLen=0;
    long long sum=arr[0];
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right<n) sum+=arr[right];
    }
    return maxLen;
    
}

void printArray(vector<int>& arr){for(auto num:arr) cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr={10, 5 ,2 ,7 ,1 ,10};int k=10;
    cout<<"Array : ";
    printArray(arr);
    // int maxLen = longestSubarrayKBrute(arr,k);
    int maxLen = longestSubarrayKOptimal(arr,k);
    cout<<"Longest SA length : "<<maxLen<<endl;
    return 0;
}