#include<bits/stdc++.h>
using namespace std;
// Binary Search : Given sorted arr={12,4,5,4,7,8,56,98,45,33,75} and key=56
// Return : findIdx if found ,-1 if Not Found
int binarySearch(vector<int>& arr,int key){
    int left=0;int right=arr.size()-1;
    while(!(left>right)){
        int mid=(left+right)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) right=mid-1;
        else left=mid+1;
    }
    return -1;
}
void printArray(vector<int>& arr){
    cout << "[";
    int count=0;
    for(auto num: arr){
        cout<<num<<((count==(arr.size()-1))?"":",");
        count++;
    }
    cout<<"]\n";
}
int main(){
    vector<int> arr={4,4,5,7,8,12,33,45,56,75,98};
    int key=0;
    cout<<"Enter Key : ";
    cin>>key;
    cout<<"Array :";
    printArray(arr);
    int findIdx=binarySearch(arr,key);
    if(findIdx<0) cout<<"Not Found";
    else cout<<key<<" is Found at Idx : "<<findIdx<<"\n";
    
    return 0;
}