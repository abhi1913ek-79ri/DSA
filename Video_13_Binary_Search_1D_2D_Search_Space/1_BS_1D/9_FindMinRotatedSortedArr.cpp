#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values).
//Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.
//Example 1:
// Input Format:
// arr = [4,5,6,7,0,1,2,3]
// Result:
// 0
// Explanation:
// Here, the element 0 is the minimum element in the array. 
int minRotatedSortedOptimal(vector<int>& arr){
    int n=arr.size();
    int mini=INT_MAX;
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[low]<=arr[high]){ // if arr is alredy sorted
            mini=arr[low];
            break;
        }
        if(arr[low]<=arr[mid]){ //left sorted
            mini=min(mini,arr[low]);
            low=mid+1;
        }else{ //right sorted
            mini=min(mini,arr[mid]);
            high=mid-1;
        }
    }
    return mini;
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};  
    cout<<"Array : ";printArray(arr);
    cout << "Minimum element: " << minRotatedSortedOptimal(arr) << endl;
    return 0;
}