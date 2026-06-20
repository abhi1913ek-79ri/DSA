#include<bits/stdc++.h>
using namespace std;
// Left Rotation By one place .

void leftRotationDplaceBrute(vector<int>& arr,int d){
    // Brute: 
    vector<int> temp;
    int n=arr.size();
    int d=d%n;
    // TC - O(d)
    for(int i=0;i<d;i++){
        temp.emplace_back(arr[i]);
    }
    //shifting from Idx=d to n-1 to 0 to n-d-1
    // TC - O(n-d)
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    // TC = O(d)
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }

    // TC = O(d + n-d + d)= O(n+d)
    // SC = O(n)
}
void leftRotationDplaceOptimal(vector<int>& arr,int d){
    // Optimal
    int n=arr.size();
    int d=d%n;
    reverse(arr.begin(),arr.begin() + d);//O(d);
    reverse(arr.begin()+d,arr.begin()+n); //O(n-d)
    reverse(arr.begin(),arr.end());//O(n)

    // TC = O(2N)
    // SC = O(1)
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
    int d=4;
    cout<<"Original Array : ";
    printArray(arr);
    leftRotationDplaceOptimal(arr,d);
    cout<<"Left Rotated "<<d<<" places Array : ";
    printArray(arr);
    return 0;
}