#include<bits/stdc++.h>
using namespace std;
// Searching : Given arr={12,4,5,4,7,8,56,98,45,33,75} and key=56
// Return : findIdx if found ,-1 if Not Found
int linearSearch(vector<int>& arr,int key){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==key) return i;
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
    vector<int> arr={12,4,5,4,7,8,56,98,45,33,75};
    int key=0;
    cout<<"Enter Key : ";
    cin>>key;
    cout<<"Array :";
    printArray(arr);
    int findIdx=linearSearch(arr,key);
    if(findIdx<0) cout<<"Not Found";
    else cout<<key<<" is Found at Idx : "<<findIdx<<"\n";
    
    return 0;
}