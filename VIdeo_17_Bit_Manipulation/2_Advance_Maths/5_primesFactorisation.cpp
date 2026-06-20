#include<bits/stdc++.h>
using namespace std;
// Prime factorisation - 
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
vector<int> pfactorisation1(int n){
    vector<int> ans;

    for(int i = 2; i*i <= n ;i++){
        if(n%i==0){
            if(isPrime(i)){
                ans.push_back(i);
            }
            if(n/i!=i && isPrime(n/i)) ans.push_back(n/i);
        }
    }

    return ans;
    // TC = O(sqrt(n)*sqrt(n)) = O(n)
    // SC = O(pfs)
    // not gives repeating fcators
}

// optimal
vector<int> pfactorisation2(int n){
    vector<int> ans;

    for(int i=2 ;i*i<= n;i++){
        while (n%i==0)
        {
            ans.push_back(i);
            n/=i;
        }  
    }

    if(n!=1) ans.push_back(n);
    return ans;
    // TC = O(sqrt(n)*q)
    // SC = O(q)
}

// printArray
void printArray(vector<int>& nums){
    cout << "[";
    for(auto num : nums){
        cout << num <<" ";
    }
    cout <<"]\n";
}

int main(){
    int n = 20;
    vector<int> pfs = pfactorisation1(n);
    cout << "n = " << n<<endl;
    cout << "Prime factorisation : ";
    printArray(pfs);
    return 0;
}