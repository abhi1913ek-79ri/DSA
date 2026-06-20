#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array.
//You may consider that such an element always exists in the array.

// Moores Voting Theorem :: MVR to get element with most vote 

int MEBrute(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int cnt=0;
        int el=arr[i];
        for(int j=0;j<n;j++){
            if(arr[j]==el){
                cnt++;
            }
        }

        if(cnt>n/2){
            return el;
        }
    }
    return -1;
}
int MEBetter(vector<int>& arr){
    // Hashing
    int n=arr.size();
    map<int,int> mpp;
    for(auto num: arr){
        mpp[num]++;
    }

    for(auto pair: mpp){
        if(pair.second>n/2){
            return pair.first;
        }
    }

    return -1;
}
int MEOptimal(vector<int>& arr){
    // Moores Voting Theorem 
    // 1. Apply MVR el -O(N)
    // 2. Verify       -O(N)  -- Mandatory when Not given that ME Always Exist 
    int n=arr.size();
    int el;int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }else if(arr[i]==el){
            cnt++;
        }else{
            cnt--;
        }
    }
    int cnt1=0;
    for(auto num : arr){
        if(num==el){
            cnt1++;
        }
    }
    if(cnt1>(n/2)){
        return el;
    }
    return -1;
}

void printArray(vector<int>& arr){for(auto num:arr) cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr={1,2,1,3,3,2,2,2,2,2,3};
    int mE=MEOptimal(arr);
    cout<<"Array : ";printArray(arr);
    if(mE>=0){
        cout<<"Majority Element : "<<mE<<endl;
    }else{
        cout<<"Majority Element : Not Found!"<<endl;
    }
    return 0;
}