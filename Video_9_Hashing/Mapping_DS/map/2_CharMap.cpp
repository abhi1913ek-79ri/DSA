#include<bits/stdc++.h>
using namespace std;
// char map
// frequency counter

int main(){
    map<char,int> mp;
    string name="Abhishek Kumar Giri";
    for(auto ch : name){
        mp[ch]++;
    }
    for(auto pair:mp){
        cout<<pair.first<<"->"<<pair.second<<endl;
    }
    return 0;
}