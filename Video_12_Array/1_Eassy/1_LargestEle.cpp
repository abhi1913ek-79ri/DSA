#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Given an array, we have to find the largest element in the array.
// BruteForce : Sort arr , retun arr[n-1]
int largestBrute(vector<int>& arr){
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];

}
int largestOptimal(vector<int>& arr){
    int largest=INT_MIN;
    for(auto num : arr){
        if(num>largest) largest=num;
    }
    return largest;
}

void printArray(vector<int>& arr){
    int n=arr.size();
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr={1,2,54,5,5,21,2,2};
    cout<<"Array : ";
    printArray(arr); 
    cout<<"LargestBRute : "<<largestBrute(arr)<<endl;
    cout<<"LargestOptimal : "<<largestOptimal(arr)<<endl;
    return 0;
}