#include<bits/stdc++.h>
using namespace std;
// important Note : for associativty of ^
// Infix → Postfix	curr != '^' pop karna 
// Infix → Prefix	curr == '^' pop karna

// Infix to Postfix : stack plus precdence

// Problem Statement: Given an infix expression,
//  Your task is to convert the given infix 
// expression to a postfix expression.
// infix = human readable form 
// postfix = used by stack based caculators // polish Notation
// prefix = used by some language like LISP // Reverse Polish Notation

//Example 1:
// Input:
// s = a + b * (c^d - e) ^ (f + g * h) - i

// Initialize:
// stack<char> st
// string ans = ""

// for each character ch in string:

// 1. If ch is operand (a-z, A-Z, 0-9):
//       ans += ch

// 2. Else if ch == '(':
//       st.push(ch)

// 3. Else if ch == ')':
//       while(st.top() != '('):
//             ans += st.top()
//             st.pop()
//       st.pop()   // remove '('

// 4. Else (ch is operator like +, -, *, /):
//       while(!st.empty() AND precedence(ch) <= precedence(st.top())):
//             ans += st.top()
//             st.pop()
//       st.push(ch)

// After loop:
// while(!st.empty()):
//       ans += st.top()
//       st.pop() 

bool isOperand(char ch){
    return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9');
}

int priority(char ch){
    if(ch == '^') return 3;
    if(ch == '*'|| ch == '/') return 2;
    if(ch == '+'|| ch == '-') return 1;
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string ans ="";

    int i = 0;
    while(i<s.length()){
        // space handling 
        if(s[i]==' '){ 
            i++;
            continue;
        }

        // opening bracket
        if(s[i] == '('){
            st.push(s[i]);
        }else if(isOperand(s[i])){ // operand
            ans.push_back(s[i]);
        }else if(s[i] == ')'){
            while (!st.empty() && st.top() != '(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            if(!st.empty()) st.pop(); // openning = '(' ke liye
        }else{ // operator
            while (!st.empty() && st.top() != '(' && (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top())&& s[i]!='^')))
            {
                ans+=st.top();
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

    return ans;
    // TC = O(n) + O(n)
    // SC = O(n)->stack + O(n)-> ans
}

int main(){
    string infix = "a+b*c+(a+b)";
    string postfix = infixToPostfix(infix);
    cout << "Infix exp   : " << infix << endl;
    cout << "Postfix exp : " << postfix << endl;
    return 0;
}