#include<bits/stdc++.h>
using namespace std;

// Approach 1
// dp = recursion + memoization

// 678. Valid Parenthesis String
bool solve(int open,int idx,string s,int n,vector<vector<int>>& dp){
    // Base condition
    if(idx == n){
        return open == 0;
    }

    bool isValid = false;

    if(dp[open][idx] != -1){
        return dp[open][idx];
    }

    if(s[idx] == '('){
        isValid |= solve(open+1,idx+1,s,n,dp);
    }else if(s[idx] == '*'){
        isValid |= solve(open,idx+1,s,n,dp);
        isValid |= solve(open+1,idx+1,s,n,dp);
        if(open > 0){
            isValid |= solve(open-1,idx+1,s,n,dp);
        }
    }else if(open > 0){
        isValid |= solve(open-1,idx+1,s,n,dp);
    }

    return dp[open][idx] = isValid;;
}

bool checkValidString(string s) {
    int n = s.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(0,0,s,n,dp);
}

int main(){
    string s;
    getline(cin,s);
    cout << checkValidString(s);
    return 0;
}