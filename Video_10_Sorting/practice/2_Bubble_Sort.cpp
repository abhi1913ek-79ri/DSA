#include<bits/stdc++.h>
using namespace std;
// at every iteration the biggest element of sub array get to its Right postion
// By swaping adjacent elemennt 

void bubble_sort(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        bool isSwapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwapped=true;
            }
        }
        if(!isSwapped) break; //loop is alleready sorted
    }
}

void printArray(vector<int>& arr);

int main(){
    vector<int> arr={29, 10, 14, 37, 13};
    cout<<"Before Sorting : ";
    printArray(arr);
    // start time : 
    clock_t start=clock();
    bubble_sort(arr);
    // end time : 
    clock_t end=clock();
    cout<<"After Sorting : ";
    printArray(arr);
    cout<<"Time of Execution is : "<<(start-end)/CLOCKS_PER_SEC<<" seconds";
    
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