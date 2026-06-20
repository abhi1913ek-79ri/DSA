#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array of N integers.
//Every number in the array except one appears twice. Find the single number in the array.
// Example 1:
// Input Format:
//  arr[] = {1,1,2,2,3,3,4,5,5,6,6}
// Result:
//  4
// Explanation:
//  Only the number 4 appears once in the array.
int singleNumberSortedArrayBruteForloop(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[0]!=arr[1])return arr[0];
        }
        else if(i==n-1){
            if(arr[i]!=arr[n-2]) return arr[n-1];
        }else{
            if(arr[i]!=arr[i-1]&& arr[i+1]!=arr[i]) return arr[i];
        }
    }
    return -1;
}
int singleNumberSortedArrayBruteHashing(vector<int>& arr){
    int ans=0;
    int n=arr.size();
    //find max 
    int maxi = INT_MIN;
    for(auto num: arr){
        maxi = max(maxi,num);
    }
    //hash
    vector<int> mapp(maxi+1,0);

    for(auto num:arr){
        mapp[num]++;
    }

    for(auto num:arr){
        if(mapp[num]==1) return num;
    }
    return -1;
    // TC = O(3N)
    // SC = O(N)
}
int singleNumberSortedArrayBruteXOR(vector<int>& arr){
    int ans=0;
    for(auto num:arr){
        ans^=num;
    }
    return ans;
    // TC=o(N)
    // SC=o(1)
}
int singleNumberSortedArrayOptimal(vector<int>& arr){ //Binary Search
    int n=arr.size();
    //edge cases to avoid unreadability during binary search 
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=1;
    int high=n-2;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        //search for single element :: condition
        if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1]) return arr[mid];

        //elemination
        if((mid%2==0&& arr[mid]==arr[mid+1])||(mid%2==1&&arr[mid]==arr[mid-1])){ // I am(Non-single ele at left)
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}


void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr={1,1,2,2,3,3,4,5,5,6,6};
    cout<<"Array : ";printArray(arr);
    cout<<"Single Number : "<<singleNumberSortedArrayOptimal(arr)<<endl;

    return 0;
}