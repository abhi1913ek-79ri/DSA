#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array of length N. Peak element is defined as the
//  element greater than both of its neighbors. Formally, if 'arr[i]' 
// is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.
// Find the index(0-based) of a peak element in the array.
// If there are multiple peak numbers, return the index of any peak number.
// Note: For the first element, the previous element should be considered as
//  negative infinity as well as for the last element, the next element should be considered as negative infinity.

// Pre-requisite: Binary Search Algorithm

// Examples
// Example 1:
// Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
// Result: 7
// Explanation: In this example, there is only 1 peak that is at index 7.
vector<int> peakElementBrute1(vector<int>& arr){
    int n=arr.size();
    vector<int> ans;
    if(n==1) return {0};
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[0]>arr[1]) ans.push_back(0);
        }
        else if(i==n-1){
            if(arr[n-1]>arr[n-2]) ans.push_back(n-1);
        }else{
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                ans.push_back(i);
            }
        }

    }
    return ans;
}
vector<int> peakElementBrute2(vector<int>& arr){
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        if((i==0||arr[i-1]<arr[i]) && ((i==n-1)||arr[i]>arr[i+1])) ans.push_back(i);
    }
    return ans;
}

int peakElementOptimal(vector<int>& arr){
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}


int main(){
    vector<int>  arr = {1,2,3,4,5,6,7,8,5,1};
    vector<int> ans=peakElementBrute2(arr);
    cout<<"Array : ";printArray(arr);
    cout<<"Peak elements index : "<<peakElementOptimal(arr);
    return 0;
}