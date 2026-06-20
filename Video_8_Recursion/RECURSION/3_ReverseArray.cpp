#include<bits/stdc++.h>
using namespace std;
void reverseArray(vector<int> &arr) {
    // code here
    int i=0;int j=arr.size()-1;
    while(i<=j){
        swap(arr[i++],arr[j--]);
    }
    return;
}

int main(){
    vector<int> v={1,2,3,4,5};
    reverseArray(v);
    for(auto val:v) cout<< val<<" ";
    return 0;
}
