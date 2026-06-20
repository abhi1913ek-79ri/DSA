#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Problem Statement: Given an array Arr[] of integers, rearrange the 
// numbers of the given array into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange to the lowest 
// possible order (i.e., sorted in ascending order).
vector<int> nextPermutaionBrute(vector<int>& arr){
    // Step 1: Find all possible permutations of elements present and store them.

    // Step 2: Search input from all possible permutations.
    
    // Step 3: Print the next permutation present right after it.

    // TC = O(N)
}
vector<int> nextPermutationBruteCpp(vector<int>& arr) {
    next_permutation(arr.begin(), arr.end()); // Modify arr in place
    return arr; // Return the updated vector
}

vector<int> nextPermutationOptimal(vector<int>& arr){
    int idx=-1;
    int n=arr.size();
    // To find Deep or break point  Idx
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            idx=i;
            break;
        }
    }

    if(idx ==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }

    for(int i=n-1;i>idx;i--){
        if(arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }

    reverse(arr.begin()+idx+1,arr.end());

    return arr;
}

void printArray(vector<int> arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr={1,2,3,4,6,5};
    cout<<"Original Array : ";printArray(arr);
    vector<int> ans = nextPermutationOptimal(arr);
    cout<<"Next Permutation : ";printArray(ans);

    
    return 0;
}