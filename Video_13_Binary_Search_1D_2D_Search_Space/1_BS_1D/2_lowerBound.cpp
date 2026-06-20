#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given a sorted array of N integers and an integer x,
// write a program to find the lower bound of x.
// Example 1:
// Input Format:
//  N = 4, arr[] = {1,2,2,3}, x = 2
// Result:
//  1
// Explanation:
//  Index 1 is the smallest index such that arr[1] >= x.

int lowerBoundBrute(vector<int>& arr,int x){//Linear search
    int n=arr.size();
    int ans=n;
    for(int i=0;i<n;i++){
        if(arr[i]>=x){
            ans=min(i,ans);
        }
    }
    return ans;
}
int lowerBoundOptimalBS(vector<int>& arr,int x){
    int n=arr.size();
    int ans=n;
    int low=0;int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int lowerBoundOptimalBSCpp(vector<int>& arr,int x){
    return (lower_bound(arr.begin(),arr.end(),x)-arr.begin());

}



void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr={1,2,2,3};
    int x=4;
    int ans=lowerBoundBrute(arr,x);
    cout<<"Array : ";printArray(arr);
    cout<<"Lower Bound  Idx = "<<ans<<endl;
    return 0;
}