#include<bits/stdc++.h>
using namespace std;
// def
void printAllDivisor(vector<int>& v,int n){
    for(int i=1;i*i<n;i++){
        if(n%i==0){
            v.emplace_back(i);
            if(n/i!=i) v.emplace_back(n/i);
        }
        
    }

}

int main(){
    vector<int> v;
    int n=100;
    printAllDivisor(v,n);
    sort(v.begin(),v.end());
    for(auto val : v)cout<< val << " ";
    return 0;
}