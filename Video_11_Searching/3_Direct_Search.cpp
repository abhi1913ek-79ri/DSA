#include<bits/stdc++.h>
using namespace std;
// Direct Search : Uses Hashing 
// Element Are stored using hash value as Index
// Element Are accessed using hash value;
int hashFunction_kmod10(int key){
    return key%10;
}

int directSearch(vector<int>& arr,int key){
    int hashValue=hashFunction_kmod10(key);
    if(arr[hashValue]==key) return hashValue;
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
    vector<int> arr={23,45,78,9,56,47};
    unordered_map<int,int> mp;
    // Pre-Storing
    int count=0;
    for(auto map: mp){
        mp[hashFunction_kmod10(arr[count])]==arr[count];
        count++;
    }
    int key=0;
    cout<<"Enter Key : ";
    cin>>key;
    cout<<"Array :";
    printArray(arr);
    int findIdx=hashFunction_kmod10(key);
    if(findIdx<0) cout<<"Not Found";
    else cout<<key<<" is Found at Idx : "<<findIdx<<"\n";
    
    return 0;
}