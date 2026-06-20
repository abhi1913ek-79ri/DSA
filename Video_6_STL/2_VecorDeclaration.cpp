#include<bits/stdc++.h>
using namespace std;

// vector-- work like array what it has dynamic size

int main(){
    // simple decalration
    vector<int> v1;
    v1.push_back(2);
    v1.emplace_back(1); //fast --prefered
    cout << v1[0]<< v1[1]<< v1[0];
    vector<pair<int,int>> arr;
    arr={{1,2}};
    cout<<arr[0].first;

    // decalare with n equal values
    vector<int> v2(5,100);
    cout<<v2[0]<<v2[1]<<v2[2]<<v2[3]<<v2[4];


    //copy vcetor
    vector<int>v3(v2);
    cout<<endl<<v3[0]<<v3[1]<<v3[2]<<v3[3]<<v3[4];
    return 0;
    
}