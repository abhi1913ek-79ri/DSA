#include<bits/stdc++.h>
using namespace std;
//Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.
//Example 1:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
int ceil(vector<int>& arr,int x){
    int n=arr.size();
    int ceilIdx=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ceilIdx=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ceilIdx!=-1?arr[ceilIdx]:-1;
}
int ceilCpp(vector<int>& arr,int x){
    int n=arr.size();
    int lb=(lower_bound(arr.begin(),arr.end(),x)-arr.begin());
    if(lb==n){
        return -1;
    }
    return arr[lb];
}
int floor(vector<int>& arr,int x){
    int n=arr.size();
    int floorIdx=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=x){
            floorIdx=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return floorIdx!=-1?arr[floorIdx]:-1;
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr={3, 4, 4, 7, 8, 10}; int x= 5;
    int ans=floor(arr,x);
    cout<<"Arr : ";printArray(arr);
    // cout<<"Floor of "<<x<<" is "<<((ans==-1)?"Not Found.":NULL)<<((ans!=-1)?ans:NULL);
    cout<<"Floor of "<<x<<" is "<<ans<<endl;
    return 0;
}