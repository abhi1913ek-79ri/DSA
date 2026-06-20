#include<bits/stdc++.h>
using namespace std;
//Selection Sort is a simple comparison-based sorting algorithm. It works by repea
// tedly finding the smallest (or largest) element from the unsorted part of the list and moving it to
//  the beginning (or end) of the sorted part.

// 1.How It Works:
// 2.Start with the first element and assume it's the smallest.
// 3.Compare this element with the rest of the elements to find the actual smallest.
// 4.Swap the smallest element found with the first element.
// 5.Move to the next position and repeat the process for the remaining unsorted elements.
// 6.Continue until the entire list is sorted. 

void printArray(vector<int>& arr);
void selection_sort(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int minIdx=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[minIdx]) minIdx=j;
        }
        swap(arr[i],arr[minIdx]);
    }
}

int main(){
    vector<int> arr={29, 10, 14, 37, 13};
    cout<<"Before Sorting : ";
    printArray(arr);
    selection_sort(arr);
    cout<<"After Sorting : ";
    printArray(arr);
    
    return 0;
}


// def
void printArray(vector<int>& v){
    int count=0;
    cout<<"[";
    for(auto val : v){
        cout<< val << ((v.size()-1==count++)?"":",");
    }
    cout<<"]\n";  
}