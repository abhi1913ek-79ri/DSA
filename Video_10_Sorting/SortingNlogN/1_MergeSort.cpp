#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int low,int mid,int high);
void mergeSort(vector<int>& arr, int low, int high);
void printArray(vector<int>& arr,int n){
    for (int i = 0; i < n; i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr={6, 9, 1, 4, 7, 3, 2, 8, 5};
    int n=arr.size();
    cout<<"Before Sorting : ";
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    cout<<"After Sorting : ";
    printArray(arr,n);
    return 0;
}

void merge(vector<int>& arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.emplace_back(arr[left]);
            left++;
        }else{
            temp.emplace_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.emplace_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.emplace_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    // code here
    if(low==high) return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}