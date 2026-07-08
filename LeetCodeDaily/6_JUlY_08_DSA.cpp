#include<bits/stdc++.h>
using namespace std;
// 3756. Concatenate Non-Zero Digits and Multiply by Sum II

// Brute Force
int sumAndMultiplyHelper(string s,int l,int r){
    long long ans = 0;
    int newNum = 0;
    int sum = 0;
    while(l<=r){
        int digit = s[l] - '0';
        if(digit) newNum =( newNum*10 + digit)%1000000007;
        sum += digit;
        l++;
    }
    ans = 1LL*sum*newNum;
    ans = ans % 1000000007;
    return (int)ans;
}

vector<int> sumAndMultiply(string s, vector<vector<int>>& queries){
    int n = queries.size();
    vector<int> ans;
    for(auto& q : queries){
        int l = q[0];
        int r = q[1];
        ans.push_back(sumAndMultiplyHelper(s,l,r));
    }

    return ans;
    // TC =O(n^2)
    // SC = O(n)  returning ans
}


// Optimal 
// 1. Sum of all digits
// 2. Non-zero digits ko concatenate karke number banana
// 3. Answer = sum × concatenatedNumber

// Example
// s = "102030405"

// Query = [2,8]

// Substring = "2030405"

// Sum = 2+0+3+0+4+0+5 = 14

// Concatenation = 2345

// Answer = 14 × 2345

// 1. Prefix Sum
// 2. Position of non-zero digits
// 3. Prefix Concatenation
// 4. Power of 10

// // helper
// int sumAndMultiplyHelper_better(string s,int l,int r,vector<int>& pre){
//     const int MOD = 1e9+7;
//     long long ans = 0;
//     int newNum = 0;
//     int left = l;
//     while(l<=r){
//         int digit = s[l] - '0';
//         if(digit) newNum =( newNum*10 + digit)%MOD;
//         l++;
//     }
//     int sum = pre[r+1] - pre[left];
//     ans = 1LL*sum*newNum;
//     ans = ans % MOD;
//     return (int)ans;
// }

// // Better - use prefix sum for range sum of digits
// vector<int> sumAndMultiply_optimal(string s, vector<vector<int>>& queries){
//     int n = queries.size();
//     vector<int> ans;
//     // prefix sum calculation
//     vector<int> pre(s.length()+1,0);
//     for (int i = 0; i < s.length(); i++)
//     { 
//         int digit = s[i] - '0';
//         pre[i+1] = pre[i]+digit;
//     }
    
//     // Non-zeros ko handle karna 
//     vector<int> pos;
//     vector<int> digits;
//     for(int i = 0;i<s.length();i++){
//         int d = s[i] -'0';
//         if(d){
//             pos.push_back(i);
//             digits.push_back(d);
//         }
//     }

//     // pow10
//     const int MOD = 1e9+7;

//     int m = digits.size();

//     vector<long long> pow10(m+1);

//     pow10[0] = 1;

//     for(int i=1;i<=m;i++){
//         pow10[i] = (pow10[i-1]*10)%MOD;
//     }

//     // concatPre
//     vector<long long> concatPre(m+1,0);
//     conca
//     for(int i= 1;i<m;i++){
//         concatPre[i] = (concatPre[i]*10+ digits[i])%MOD;
//     }


        

//     return ans;
//     // TC =O(n^2)
//     // SC = O(n)  returning ans
// }


int main(){
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        string s;
        getline(cin,s);
        int n;
        cin >> n;
        vector<vector<int>> queries(n);
        for(auto& q : queries){
            int m;
            cin >> m;
            vector<int> tempArr(m);
            for(auto& temp : tempArr){
                cin >> temp;
            }

            q = tempArr;
        }

        vector<int> ans = sumAndMultiply_optimal(s,queries);
        bool flag = false;
        for(auto& a : ans){
            if(flag) cout << " ";
            cout << a;
            flag = true;
        }
        cout << endl;
    }
    
    return 0;
}

// (a*b)%m
// =
// ((a%m)*(b%m))%m
// (a+b)%m
// =
// ((a%m)+(b%m))%m