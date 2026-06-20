#include<bits/stdc++.h>
using namespace std;
// prefix to Infix
// Note :
// Postfix	Left → Right
// Prefix	❗ Right → Left

// Use only stack not precedence brackets etc.
bool isOperand(char ch){
    return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9');
}
string prefixToInfix(string s){
    // valid postfix -- mandetory : no brackets spaces etc.
    stack<string> st;

    for(int i = s.length()-1;i>=0;i--){
        if(isOperand(s[i])){
            st.push(string(1,s[i]));
        }else{
            if(st.size() < 2) return "INVALID EXP";
            string popped1 = st.top();
            st.pop();
            string popped2 = st.top();
            st.pop();

            string con = "(" + popped1 + s[i] + popped2 + ")";
            st.push(con);
        }
    }
    if(st.size() != 1) return "INVALID EXP";
    return st.top();
    // TC = O(n) + O(n)
    // SC = O(n)
}


int main(){
    string prefix = "*+ab-cd";
    string infix = prefixToInfix(prefix);
    cout << "Prefix exp : " << prefix << endl;
    cout << "Infix exp   : " << infix << endl;
    return 0;
}