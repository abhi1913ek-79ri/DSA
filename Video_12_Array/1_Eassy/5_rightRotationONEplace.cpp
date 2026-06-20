#include<bits/stdc++.h>
using namespace std;
// Left Rotation By one place .
// Optimal

// RightRotation   --- why error ALways do changes your pos side to forwarding side 
void rightRotationOneplace(vector<int>& arr){
    int n=arr.size();
    int temp=arr[n-1];
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    //set last element to temp which is arr[0] at initially.
    arr[0]=temp;
}
void printArray(vector<int>& arr){
    int n=arr.size();
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    cout<<"Original Array : ";
    printArray(arr);
    rightRotationOneplace(arr);
    cout<<"Right Rotated Array : ";
    printArray(arr);
    return 0;
}