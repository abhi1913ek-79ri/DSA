#include<bits/stdc++.h>
using namespace std;
// Selection sort revision
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  // Corrected outer loop
        for (int j = 0; j < n - i - 1; j++) {  // Corrected inner loop
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void bubble_optimised_sort(int arr[], int n) {
    bool isSwapped=false;
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwapped=true;
            }
           
        }
        if(!isSwapped) break;
        cout<<"swapped\n";
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
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sorting : ";
    printArray(arr,n);
    bubble_optimised_sort(arr,n);
    cout<<"After Sorting : ";
    printArray(arr,n);
    return 0;
}