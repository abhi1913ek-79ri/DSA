#include<bits/stdc++.h>
using namespace std;
// ALGO 
// think in left to rigth 
// then to counter open > close part 
// right to left

// 32. Longest Valid Parentheses 
int longestValidParentheses(string s) {
    int n = s.length();

    int open = 0;
    int close = 0;
    int maxLen = 0;
    // left to right traversal
    for(auto& ch : s){
        open += (ch == '(');
        close += (ch == ')');

        if(open > close){
            continue;
        }else if(close > open){
            open = 0;
            close = 0;
        }else{
            maxLen = max(maxLen,open+close);
        }
    }

    // right to left
    open = 0;
    close = 0;
    for(int i=n-1;i>=0;i--){
        char ch = s[i];
        open += (ch == '(');
        close += (ch == ')');

        if(close > open){
            continue;
        }else if(open > close){
            open = 0;
            close = 0;
        }else{
            maxLen = max(maxLen,open+close);
        }
    }

    return maxLen;
    // TC = O(n)
    // SC = O(1)
}
int main(){
    string s;
    getline(cin,s);
    cout << longestValidParentheses(s);
    return 0;
}