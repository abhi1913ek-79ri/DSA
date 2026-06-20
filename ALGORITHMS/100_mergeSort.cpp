#include<bits/stdc++.h>
using namespace std;
// Merge Sort 
void merge(vector<int>& arr,int low,int mid ,int high){
    vector<int> temp;

    int left = low;
    int right = mid+1;

    while (left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left<=mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right<=high)
    {
        temp.push_back(arr[right++]);
    }
    
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>& arr,int low,int high){
    if(low==high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}


void printArray(vector<int>& arr){
    cout << "[";
    for(auto ele : arr) cout << ele << " ";
    cout << "]\n";

}

int main(){
    vector<int> arr = {5,1,2,4,3,6};
    cout << "arr = ";
    printArray(arr);
    mergeSort(arr,0,arr.size()-1);
    cout <<"sorted arr = ";
    printArray(arr);
    return 0;
}