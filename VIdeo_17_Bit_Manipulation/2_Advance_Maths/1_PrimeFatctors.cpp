#include<bits/stdc++.h>
using namespace std;


// Brute Force- 1 -- pfs of all numbers in queries
// Find all divisors and then check if it is prime
// isPrime
bool isPrime(int n){ // (sqrt(n))
    if(n<2) return  false;
    for(int i= 2;i*i<=n;i++){
        if(n%i == 0) return false;
    }
    return true;
    // TC = O(sqrt(n))
    // SC = O(1)
}

// prime factors 
vector<int> pfs(int n){
    vector<int> ans;
    for(int i = 2;i*i<=n;i++){
        if(n%i == 0){
            if(isPrime(i)) ans.push_back(i);

            if(i!=n/i && isPrime(n/i)){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
    // TC = O(srt(n)*sqrt(n)) = O(n)
    // SC = (n) for ans not for solution
}

// prime factors of numbers in array queries
vector<vector<int>> primeFactors(vector<int>& queries){
    vector<vector<int>> ans;

    for(auto num : queries){
        ans.push_back(pfs(num));
    }

    return ans;
    // TC = O(q*sqrt(n)*sqrt(n)) = O(q*n)
    // SC = O(1)  
}

// Brute Force 2: primefactors and their all occurences 

// Brute Force -- pfs of all numbers in queries
//

// prime factors 
vector<int> pfs2(int n){
    vector<int> ans;
    for(int i = 2;i*i<=n;i++){
        if(n%i == 0){
            while(n % i == 0){
            ans.push_back(i);
            n /= i;
        }
        }
    }
    if(n > 1) ans.push_back(n);
    return ans;
    // TC = O(srt(n)*logn)
    // SC = (n) for ans not for solution
}

// prime factors of numbers in array queries
vector<vector<int>> primeFactors2(vector<int>& queries){
    vector<vector<int>> ans;

    for(auto num : queries){
        ans.push_back(pfs2(num));
    }

    return ans;
    // TC = O(n*sqrt(n)logn)
    // SC = O(q.n)  
}

// strivers 
// prime factors 
vector<int> pfs3(int n){
    vector<int> ans;
    for(int i = 2;i*i<=n;i++){
        if(n%i == 0){
            ans.push_back(i);
            while(n % i == 0){
            n /= i;
        }
        }
    }
    if(n > 1) ans.push_back(n);
    return ans;
    // TC = O(srt(n)*logn)
    // SC = (n) for ans not for solution
}

// prime factors of numbers in array queries
vector<vector<int>> primeFactors3(vector<int>& queries){
    vector<vector<int>> ans;

    for(auto num : queries){
        ans.push_back(pfs3(num));
    }

    return ans;
    // TC = O(n*sqrt(n)logn)
    // SC = O(q.n)  
}


// print array
void printArray(vector<int>& nums){
    cout << "[";
    for(auto num : nums){
        cout << num << " ";
    }
    cout << "],";
}



int main(){
    vector<int> queries = {7, 12, 18};

    cout << "Prime factors of";
    printArray(queries);
    cout <<" : \n[";
    vector<vector<int>> primefacts = primeFactors3(queries);
    for(auto array : primefacts){
        printArray(array);
    }
    cout <<"]";

    return 0;
}





