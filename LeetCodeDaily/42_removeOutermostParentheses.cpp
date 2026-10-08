#include<bits/stdc++.h>
using namespace std;
// LC - 1021. Remove Outermost Parentheses
string removeOuterParentheses(string s){
    string ans = "";
    int balance = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i]=='(' && balance){
            ans+=s[i];
        }else if(s[i]==')' && !(balance-1==0)){
            ans+=s[i];
        }
        if(s[i]=='('){
            balance++;
        }else{
            balance--;
        }
    }
    return ans;
}

int main(){
    string s;
    getline(cin,s);
    cout << removeOuterParentheses(s);
    return 0;
}