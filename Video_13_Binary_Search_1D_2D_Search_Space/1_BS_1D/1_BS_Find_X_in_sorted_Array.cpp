#include<bits/stdc++.h>
using namespace std;
//Problem statement: You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.

// Let’s say the given array is = {3, 4, 6, 7, 9, 12, 16, 17} and target = 6.
// Output : 2  first Occurence if modified like that 
// Modified::
int binarySearchFirstOccurrence(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        // Check if it's the first occurrence or not
        if (mid == 0 || arr[mid - 1] != target)
            return mid;
        else
            return binarySearchFirstOccurrence(arr, low, mid - 1, target); // Search in left part
    } 
    else if (arr[mid] > target) 
        return binarySearchFirstOccurrence(arr, low, mid - 1, target);
    else 
        return binarySearchFirstOccurrence(arr, mid + 1, high, target);
}

// general : I tried REcursive
int binarySearchRecusrive(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return binarySearchFirstOccurrence(arr, low, mid - 1, target);
    } 
    else if (arr[mid] > target) 
        return binarySearchFirstOccurrence(arr, low, mid - 1, target);
    
    return binarySearchFirstOccurrence(arr, mid + 1, high, target);
}
// Iterative
int binarySearchIterative(vector<int>& arr, int target) {
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (arr[mid] == target) {
            if (mid == 0 || arr[mid - 1] != target) return mid;  // Check first occurrence
            else high = mid - 1;  // Move left to find the first occurrence
        } 
        else if(arr[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

void printArray(vector<int> arr){
    for(auto num : arr){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr={3, 4, 6,6, 7, 9, 12, 16, 17};int n=arr.size();
    int target=6;
    cout<<"Array : ";printArray(arr);
    int findIdx=binarySearchRecusrive(arr,0,n-1,target);
    int findIdx2=binarySearchIterative(arr,target);//with fist occurence gurantee
    if(findIdx==-1)cout<<target<<" is Not Found !"<<endl;
    else cout<<target<<" is Found at Idx : "<<findIdx<<endl;
    if(findIdx2==-1)cout<<target<<" is Not Found !"<<endl;
    else cout<<target<<" is Found at Idx : "<<findIdx2<<endl;
    return 0;
}