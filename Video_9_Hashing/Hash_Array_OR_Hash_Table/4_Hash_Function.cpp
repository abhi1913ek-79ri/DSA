#include<bits/stdc++.h>
using namespace std;
// Hash-Function::
// Hashing : Pre-storing Key-may be same character/number or Hash-value returned By hash- function & fetch the value 
// associated with that key/hash-value
// Hash-Function :: hashFunction(key)=hash-value now storing and acces is done on the basis  of that only .
// unordered-map: Like things 
// TC= Storing and access - TC=O(1) + O(TC(hashFunction))
// I am here using Only for Number hashing
// Without Collision Resoltion

// here hash_table map key to frequency of numbers ending with digit=0,1,2,3,4,5,6,7,8,9
int hash_Kmod10(int k){// O(1)
    return k%10;
}

int main(){
    vector<int> nums={10,11,23,15,84,75,44,86,89,88};
    vector<int> hash_table(10,0);
    // Pre-computing and storing
    for(auto num:nums){
        int hash_value=hash_Kmod10(num);
        hash_table[hash_value]++;
    }
    // fetch
    for(auto num:nums){
        int hash_value=hash_Kmod10(num);
        cout << hash_value<<"->"<<hash_table[hash_value]<<endl;
    }
    return 0;
}