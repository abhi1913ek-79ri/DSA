#include<bits/stdc++.h>
using namespace std;
//Problem Statement: You are given a sorted array containing N integers and a number X,
// you have to find the occurrences of X in the given array.

// Examples
// Example 1:
// Input:
//  N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
// Output
// : 4
// Explanation:
//  3 is occurring 4 times in 
// the given array so it is our answer.
int countOccurenceBrute(vector<int>& arr,int x){//Linear_search
    int ans=0;
    for(auto num: arr){
        if(num==x)ans++;
    }
    return ans;
    //O(N)
}
int countOccurenceOptimal(vector<int>& arr,int x){//BS
    int n=arr.size();
    int low=0;
    int high=n-1;
    int firstIdx=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            firstIdx=mid;
            high=mid-1;
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    if(firstIdx==-1) return 0;
    low=0;
    high=n-1;
    int lastIdx=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            lastIdx=mid;
            low=mid+1;
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return lastIdx-firstIdx+1;
}

int countOccurenceBrute(vector<int>& arr,int x){//Linear_search
    int ans=0;
    for(auto num: arr){
        if(num==x)ans++;
    }
    return ans;
    //O(N)
}
int countOccurenceOptimal(vector<int>& arr,int x){//BS
    int n=arr.size();
    int low=0;
    int high=n-1;
    int firstIdx=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            firstIdx=mid;
            high=mid-1;
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    if(firstIdx==-1) return 0;
    low=0;
    high=n-1;
    int lastIdx=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            lastIdx=mid;
            low=mid+1;
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return lastIdx-firstIdx+1;
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}


int main(){
    vector<int> arr={2, 2 , 3 , 3 , 3 , 3 , 4};
    int x=3;
    cout<<"Array : ";printArray(arr);
    cout<<"Linear Search Occurence of "<<x<<" is : "<<countOccurenceBrute(arr,x)<<endl;
    cout<<"Binary Search Occurence of "<<x<<" is : "<<countOccurenceBrute(arr,x)<<endl;


    return 0;
}