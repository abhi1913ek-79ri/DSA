#include<bits/stdc++.h>
using namespace std;
// Selection sort revision
void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {  
        int j=i;
        while(j>0 &&arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={5,6,4,5,8,9,1,4,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sorting : ";
    printArray(arr,n);
    insertion_sort(arr,n);
    cout<<"After Sorting : ";
    printArray(arr,n);
    return 0;
}