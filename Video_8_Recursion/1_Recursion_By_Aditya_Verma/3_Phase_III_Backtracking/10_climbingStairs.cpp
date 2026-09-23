#include<bits/stdc++.h>
using namespace std;
// 70. Climbing Stairs
void solve(int ip,int op,int& ways){
    // base condition
    if(ip < 1){
        if(ip == 0) ways++;
        return; 
    }

    // take 1
    op += 1;
    ip -= 1;
    solve(ip,op,ways);

    // undo
    ip += 1;
    op -= 1;

    // take 2
    op += 2;
    ip -= 2;
    solve(ip,op,ways);
}


int climbStairs(int n) {
    int ways = 0;
    solve(n,0,ways);
    return ways;
}

// Recursive version of same becos ways apas me plus ho jate hain 
int solveUsingRecursive(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    return solveUsingRecursive(n-1)+solveUsingRecursive(n-2);
}

// DP becoz  there are overlapping sub problems 
// state ip 
int solveDp(int n,vector<int>& dp){
    if(n==0) return 1;
    if(n<0) return 0;

    if(dp[n]!=-1){
        return dp[n];
    }

    // Take 1 stairs ways
    int one = solveDp(n-1,dp);

    // Take 2 stairs ways
    int two = solveDp(n-2,dp);

    dp[n] = one + two;

    return  one + two;
}

int solveDpMain(int n){
    vector<int> dp(n+1,-1);
    return solveDp(n,dp);
}
int main(){
    int n;
    cin >> n;
    cout << solveDpMain(n);
    return 0;
}