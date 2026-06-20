#include<bits/stdc++.h>
using namespace std;
//Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum 
//distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.
// Examples
// Example 1:
// Input Format:
// N = 6, k = 4, arr[] = {0,3,4,7,10,9}
// Result:
// 3

bool canWePlace(vector<int>& arr,int dist ,int cows){
    int n = arr.size();
    int countCows=1; int last = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-last>=dist){
            countCows++;
            last=arr[i];
        }
        if(countCows==cows) return true;
    }
    return false;
}

int aggressiveCowsBrute(vector<int>& arr,int cows){
    // sorted 
    sort(arr.begin(),arr.end());
    for(int i=1;i<=(arr[arr.size()-1]-arr[0]);i++){
        if(canWePlace(arr,i,cows)){
            continue;
        }else{
            return i-1;
        }
    }
    return -1;
}

int aggressiveCowsOptimal(vector<int>& arr,int cows){
    // sorted 
    sort(arr.begin(),arr.end());
    int low=1;int high=(arr[arr.size()-1]-arr[0]);
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if(canWePlace(arr,mid,cows)){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}

int main(){
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int k = 4;
    cout << "Maximum minimum distance: " << aggressiveCowsOptimal(arr, k) << endl;
    return 0;
}