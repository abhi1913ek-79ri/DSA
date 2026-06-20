#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>& arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot&&i<high){
            i++;
        }
        while(arr[j]>=pivot&&j>low){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int>& arr,int low,int high){
    if(low<high){//check for size of array greater than 1
        int partitionIdx=partition(arr,low,high);
        quickSort(arr,low,partitionIdx-1);
        quickSort(arr,partitionIdx+1,high);
    }
}
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
    quickSort(arr,0,n-1);
    cout<<"After Sorting : ";
    printArray(arr,n);
    return 0;
}