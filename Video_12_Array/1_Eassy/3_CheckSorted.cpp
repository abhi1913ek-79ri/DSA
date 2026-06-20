#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array of size n, write a program to check if the given array is sorted in 
// (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else 
// return False.

// Brute-Better-Optimal: compare adjacenta nd tell true if in ascending other wise false

bool isSorted(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]) return false;
    }
    return true;
}

int main(){
    vector<int>  arr={1,2,54,5,56,4};
    vector<int> arrsorted={1,2,3,4,5,6,7,8,9};
    bool ans=isSorted(arr);
    cout<<((ans==1)?"sorted":"Unsorted")<<endl;
    return 0;
}