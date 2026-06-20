#include<bits/stdc++.h>
using namespace std;
// Variety-2
// Problem Statement:
// There’s an array ‘A’ of size ‘N’ with positive and negative elements 
// (not necessarily equal). Without altering the relative order of positive 
// and negative elements, you must return an array of alternately positive
//  and negative values. The leftover elements should be placed at the very 
//  end in the same order as in array A.

// Note: Start the array with positive elements.

// Examples: 

// Example 1:

// Input:
// arr[] = {1,2,-4,-5,3,4}, N = 6
// Output:
// 1 -4 2 -5 3 4

vector<int> RearrangeArrayVar1Optimal(vector<int>& arr){//Brute is Optimal
    int n=arr.size();
    vector<int> pos;
    vector<int> neg;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size()>neg.size()){//neg pe kam
        for(int i=0;i<neg.size();i++){
            ans[2*i]=pos[i];
            ans[(2*i)+1]=neg[i];
        }
        int idx=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            ans[idx++]=pos[i];
        }
    }else{
        for(int i=0;i<pos.size();i++){
            ans[2*i]=pos[i];
            ans[(2*i)+1]=neg[i];
        }
        int idx=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            ans[idx++]=neg[i];
        }
    }
    return ans;
}
void printArray(vector<int> arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr={1,2,-3,-1,2,-3,3};
    vector<int> ans=RearrangeArrayVar1Optimal(arr);
    cout<<"Original Array : ";printArray(arr);
    cout<<"Rearraged Array : ";printArray(ans);
    return 0;
}