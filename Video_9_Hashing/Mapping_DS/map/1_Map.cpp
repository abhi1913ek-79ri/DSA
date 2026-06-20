#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    // Like a dictionary in python
    map<int,string> mp;

    // One Way of inserting values
    mp[1]="One";
    mp[2]="Two";
    mp[3]="Three";

    // Another way of Insert
    mp.insert({4,"Four"});

    // Access Way
    // cout<<1<<"->"<<mp[1];

    // Iterate
    for(auto pair:mp){
        cout<<pair.first<<"->"<<pair.second<<endl;
    }


    
    

    return 0;
}