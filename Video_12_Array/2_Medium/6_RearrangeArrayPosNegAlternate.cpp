#include<bits/stdc++.h>
using namespace std;
// Variety-1  == pos = n/2 and neg = n/2
// Problem Statement:
// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
// Without altering the relative order of positive and negative elements, 
// you must return an array of alternately positive and negative values.
// Note: Start the array with positive elements.

vector<int> RearrangeArrayVar1Brute(vector<int>& arr){
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
    for(int i=0;i<n/2;i++){
        ans[2*i]=pos[i];
        ans[(2*i)+1]=neg[i];
    }
    return ans;
    // TC = O(N) + O(N/2)
    // SC = O(N)
}

vector<int> RearrangeArrayVar1Optimal(vector<int>& arr){
    int n=arr.size();
    vector<int> ans(n,0);
    int posIdx=0;int negIdx=1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){//negative
            ans[negIdx]=arr[i];
            negIdx+=2;
        }else{
            ans[posIdx]=arr[i];
            posIdx+=2;
        }
    }
    return ans;
    // TC = O(N) -- One pass only
    // SC = O(N)
}
void printArray(vector<int> arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr={1,2,-3,-1,2,-3};
    vector<int> ans=RearrangeArrayVar1Optimal(arr);
    cout<<"Original Array : ";printArray(arr);
    cout<<"Rearraged Array : ";printArray(ans);
    return 0;
}