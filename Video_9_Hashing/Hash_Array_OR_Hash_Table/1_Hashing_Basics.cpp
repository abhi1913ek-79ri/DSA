#include<bits/stdc++.h>
using namespace std;
// Basics of Hashing 
// Hashing : Pre-storing Key-may be same character/number or Hash-value returned By hash- function & fetch the value 
// associated with that key/hash-value

// Number - Hashing
// Given : nums ={1,2,4,5,9,3,6,2,4,1,1,1}
// We have to store frequency of elements of nums in hash-array : hash-table

int main(){
    vector<int> nums={1,2,4,5,9,3,6,2,4,1,1,1};
    int max_element=9;
    vector<int> hash_table(max_element+1,0);

    // pre-computation
    for(auto num : nums) hash_table[num]++;


    // fetch
    for(int i=0;i<hash_table.size();i++) cout << i <<"->"<<hash_table[i]<<endl;
    return 0;
}
// Porblem : We cant allocate memory >= 10e7 in main()
// Porblem : We cant allocate memory >= 10e8 in Globally
// So we cant - map element -> freq(i) - USing Hash -Array For Bigger - Numbers 
// So we use map<> Data Structurres Which internal a hash-map and solve all problems
// map- ordered generally -Acces and Store TC=O(logn) ALL Cases : Avg ,worst and Best .
// unordered -map for faster -Acces and Store TC=O(1) Avg and Best Case. : Not most frequently once in a bloom collsion is 
// resolved usingb different techniques Gnerally like chaining etc.
// unordered -map for slower -Acces and Store TC=O(n) Worst.
