#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr){
    int n=arr.size();
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}
int maxArray(vector<int>& arr){
    int largest=INT_MIN;
    for(auto it:arr){
        if(it>largest) largest=it;
    }
    return largest;
}
int minArray(vector<int>& arr){
    int smallest=INT_MAX;
    for(auto it:arr){
        if(it<smallest) smallest=it;
    }
    return smallest;
}




int main(){
    vector<int> arr={1,2,54,5,5,21,2,2};
    cout<<"Array : ";
    printArray(arr); 
    cout<<"Largest : "<<maxArray(arr)<<endl;
    cout<<"Smallest : "<<minArray(arr)<<endl;
    return 0;
}