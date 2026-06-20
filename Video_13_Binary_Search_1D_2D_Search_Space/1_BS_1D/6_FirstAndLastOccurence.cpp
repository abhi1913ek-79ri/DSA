#include<bits/stdc++.h>
using namespace std;
// Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.

// Note: Consider 0 based indexing

// Examples:

// Example 1:
// Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
// Output: 4
// Explanation: As the target value is 13 , it appears for the first time at index number 2.

vector<int> firstOccurenceOptimal1(vector<int> arr,int target){
    int n=arr.size();
    int firstIdx=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            firstIdx=mid;
            high=mid-1;
        }else if(arr[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    low=0;
    high=n-1;
    int lastIdx=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            lastIdx=mid;
            low=mid+1;
        }else if(arr[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return {firstIdx,lastIdx};
}
vector<int> firstOccurenceOptimal2(vector<int> arr,int target){
    int n=arr.size();
    int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    int ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
    if(lb==n||arr[lb]!=target) return {-1,-1};
    return {lb,ub-1};
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr={3, 4,4,4,7, 8, 10}; int x= 4;
    vector<int> ans=firstOccurenceOptimal2(arr,x);
    cout<<"Arr : ";printArray(arr);
    cout<<"First occurence of "<<x<<" is at idx : "<<ans[0]<<" last at idx : "<<ans[1]<<endl;
    return 0;
}