#include<bits/stdc++.h>
using namespace std;
// important Note : for associativty of ^
// Infix → Postfix	curr != '^'
// Infix → Prefix	curr == '^'

// Infix to Prefix : stack plus precdence
// Algorithm :
// 1. Reverse infix  also handles bracket
// 2. do postfix conversion - controlled - associativity of ^
// 3. Reverse the postfix result and return 

bool isOperand(char ch){
    return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9');
}

int priority(char ch){
    if(ch == '^') return 3;
    if(ch == '*'|| ch == '/') return 2;
    if(ch == '+'|| ch == '-') return 1;
    return -1;
}

string controllReverse(string s){
    reverse(s.begin(), s.end());

    for(char &ch : s){
        if(ch == '(') ch = ')';
        else if(ch == ')') ch = '(';
    }
    return s;
    // TC = O(n)
}

string infixToPrefix(string s){
    stack<char> st;
    string ans = "";

    // reverse infix
    s = controllReverse(s);

    int i=0;

    while (i<s.length())
    {
        if(s[i]=='('){
            st.push(s[i]);
        }else if(isOperand(s[i])){
            ans.push_back(s[i]);
        }else if(s[i]==')'){
            while (!st.empty()&& st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // remove '('
        }else{ // operator
            while (!st.empty() && st.top() != '(' &&
                  (priority(s[i]) < priority(st.top()) ||
                  (priority(s[i]) == priority(st.top()) && s[i] == '^')))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    // TC = O(n)
    // SC = O(n)
}

int main(){
    string infix = "a+b*c+(a+b)";
    string prefix = infixToPrefix(infix);
    cout << "Infix exp   : " << infix << endl;
    cout << "Prefix exp : " << prefix << endl;
    return 0;
}