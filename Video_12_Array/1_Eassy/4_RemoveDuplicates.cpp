#include<bits/stdc++.h>
using namespace std;

// Array is Sorted
int removeDuplicateBrute(vector<int>& arr){
    set<int> st;
    // 1st Pass
    for(auto num:arr) st.insert(num);
    // 2nd Pass
    int i=0;
    for(auto it : st){
        arr[i++]=it;
    }
    return i;

}
int removeDuplicateOptimal(vector<int>& arr){
    int i=0;
    for(int j=1;j<arr.size();j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

void printArray(vector<int>& arr){
    int n=arr.size();
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr={1,2,2,3,3,3,4,5,6,7,7,7,8,9,9};
    cout<<"Original Array : ";
    printArray(arr);
    int size=removeDuplicateOptimal(arr);
    cout<<"After Removal Array : ";

    // only till last uique print slice till set size
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Duplicate Elements are Removed And Array size is "<<size;
    
    return 0;
}