#include<bits/stdc++.h>
using namespace std;


// Brute Force
// All divisors of n
vector<int> getDivisors(int n){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(n%i==0) ans.push_back(i);
    }
    return ans;
    // TC = O(n)
    // SC = O(divisors)
}

// Optimal but unorted order
vector<int> getDivisors2(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            if(n/i!=i) ans.push_back(n/i);
        }
    }
    return ans;
    // TC = O(sqrt(n))
    // SC = O(divisors)
}




// printarray
void printArray(vector<int>& nums){
    cout << "[";
    for(auto num:nums){
        cout << num << " ";
    }
    cout <<"]";
}

int main(){
    int n = 15;
    vector<int> divisors = getDivisors2(n);
    cout << "Divisors of " << n <<" : ";
    printArray(divisors);
    return 0;
}