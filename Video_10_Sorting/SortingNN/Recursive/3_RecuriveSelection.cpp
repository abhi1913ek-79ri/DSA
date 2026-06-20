#include<bits/stdc++.h>
using namespace std;
// Selection sort revision
void selection_sort(int arr[],int n){
    for (int i = 0; i <= n-2; i++) //why n-2 taki last element ko nakare koi jarurat bhi nahi hain
    {
        int minIdx=i;
        for (int j = i; j<=n-1; j++)
        {
            if(arr[j]<arr[minIdx]) minIdx=j;
        }
        swap(arr[i],arr[minIdx]);
        
    }
    
}
void selectionSortRecursive(int arr[],int i,int n){
    // Base Case:
    if(i==n-1) return;
    int minIdx=i;
    for(int j=i;j<=n-1;j++){
        if(arr[j]<arr[minIdx]){
            minIdx=j;
        }
    }
    swap(arr[i],arr[minIdx]);
    // Recursive call :
    selectionSortRecursive(arr,i+1,n);
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
    selectionSortRecursive(arr,0,n);
    cout<<"After Sorting : ";
    printArray(arr,n);
    return 0;
}