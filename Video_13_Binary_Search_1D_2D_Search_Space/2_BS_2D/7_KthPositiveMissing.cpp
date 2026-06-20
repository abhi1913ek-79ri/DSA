#include<bits/stdc++.h>
using namespace std;
//Kth Missing Positive Number
// Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'.
// Find the 'kth' positive integer missing from 'vec'.
// Examples
// Example 1:
// Input Format:
// vec[]={4,7,9,10}, k = 1
// Result:
// Explanation:
//  The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.

int kthMissingPositiveBrute(vector<int> & arr,int k){
    int count=0;int ele=1;int i=0;
    while (count<k){
        if(i<arr.size()&&arr[i]==ele){
            i++;
        }
        else if(arr[i]!=ele){
            count++;
            if (count == k) return ele;
        }
        ele++;
    } 
    return -1;
}

int kthMissingPositiveBrute2(vector<int> & arr,int k){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            k+=1;
        }else{
            break;
        }
    }
    return k;
}
int kthMissingPositiveOptimal(vector<int> & arr,int k){
    int n = arr.size();
    int low=0;int high = n-1;
    while (low<=high)
    {
       int mid = low+ (high-low)/2;
       int missingNumbers = arr[mid]-(mid+1);
       if(missingNumbers<k){
            low=mid+1;    
       }else{
            high=mid-1;
       }
    }
    return low+k;//high+1+k = high + more = high + k- missing
}

void printArray(vector<int>& arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int>  vec={4,7,9,10};int k = 4;
    cout<<"Array : ";printArray(vec);
    cout<<k<<"th Missing positive Number : "<<kthMissingPositiveOptimal(vec,k)<<endl;
    return 0;
}