#include<bits/stdc++.h>
using namespace std;

void moveZeroToEndBrute(vector<int>& arr){
    // Brute : 
    vector<int> temp;int n= arr.size();
    // Copy All non-zero to temp
    for(int i=0;i<n;i++) {
        if(arr[i]!=0) temp.emplace_back(arr[i]);
    }

    // inesert all Non-zero to start from temp to arr
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    // Set Remaining to 0
    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
}

// OPtimal Approach 2 ptr Approach


void printArray(vector<int>& arr){
    for(auto num : arr) cout<<num<<" ";
    cout<<"\n";
}

int main(){
    vector<int> arr={1,2,0,0,4,0,45,7,1,80,0,0,4,0};
    cout<<"Orignal Array : ";
    printArray(arr);
    moveZeroToEndBrute(arr);
    cout<<"Changed Array : ";
    printArray(arr);
    return 0;
}