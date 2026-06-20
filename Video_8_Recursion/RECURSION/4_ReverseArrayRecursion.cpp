#include<bits/stdc++.h>
using namespace std;
void reverseArrayHelper(vector<int> &arr,int i, int j) {
    // code here
    if(i>j) return;
    swap(arr[i++],arr[j--]);
    reverseArrayHelper(arr,i,j);
}
void reverseArray(vector<int>& arr){
    reverseArrayHelper(arr,0,arr.size()-1);
}

int main(){
    vector<int> v={1,2,3,4,5};
    reverseArray(v);
    for(auto val:v) cout<< val<<" ";
    return 0;
}
