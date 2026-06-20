#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Given an array, and an element num the task is to find if num is
//  present in the given array or not. If present print the index of the element or print -1.

// Examples:
// Example 1:
// Input: arr[]= 1 2 3 4 5, num = 3
int linearSearch(vector<int> & arr, int k ){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==k) return i;
    }
    return -1;
}
void printArray(vector<int>& arr){
    for(auto num : arr) cout<<num<<" ";
    cout<<"\n";
}
int main(){
    vector<int> arr={1,2,4,5,4,56,4,8,7,9,10};
    int key;
    cout << " Enter Key : ";
    cin >> key;
    cout<<"Array : ";
    printArray(arr);
    int findIdx=linearSearch(arr,key);
    if(findIdx>=0){
        cout<<key <<" is Found at idx : "<<findIdx<<endl;
    }else{
        cout<<"Not Found !"<<endl;
    }
    return 0;
}

