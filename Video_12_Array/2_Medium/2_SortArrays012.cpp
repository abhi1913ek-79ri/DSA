#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place 
// sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space).

// Brute:
// Sort using any nLogn algorithm Like  mergeSOrt
// Sorting ( even if it is not the expected solution here but it can be considered as one of the approaches).
//  Since the array contains only 3 integers, 0, 1, and 2. 
// Simply sorting the array would arrange the elements in increasing order.
void SortArrayBrute(vector<int>& arr){
    // consider that using mergeSOrt
    sort(arr.begin(),arr.end());
}


// Using Hashing type thing or cnt0,cnt1,cnt2 variables 
void SortArrayBetter(vector<int>& arr){
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    // O(N)
    for(auto num: arr){
        if(num==0)cnt0++;
        else if(num==1)cnt1++;
        else cnt2++;
    }
    //O(N) Total of 3
    for(int i=0;i<cnt0;i++) arr[i]=0;
    for(int i=cnt0;i<cnt1+cnt0;i++) arr[i]=1;
    for(int i=cnt1+cnt0;i<cnt0+cnt1+cnt2;i++) arr[i]=2;
}

// Optimal
void SortArrayOptimal(vector<int>& arr){
    int n=arr.size();
    int low=0;int mid =0;int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }

}
void printArray(vector<int>& arr){for(auto num:arr) cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr={0,1,2,1,0,1,0,1,0,2};
    cout<<"Array : ";printArray(arr);
    SortArrayOptimal(arr);
    cout<<"Array after sort : ";printArray(arr);
    return 0;
}