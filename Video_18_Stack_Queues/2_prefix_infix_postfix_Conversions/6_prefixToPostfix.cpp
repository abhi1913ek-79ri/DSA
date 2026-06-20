#include<bits/stdc++.h>
using namespace std;
// postfix to prefix
// Note :
// Postfix	Left → Right
// Prefix	❗ Right → Left

// Use only stack not precedence brackets etc.
bool isOperand(char ch){
    return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9');
}
string prefixToPostfix(string s){
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

            string con =popped1 + popped2 + string(1,s[i]); // yahan pe bhi hume popped1  and popped2 ko swap karna hota hain
            st.push(con);
        }
    }
    if(st.size() != 1) return "INVALID EXP";
    return st.top();
    // TC = O(n) + O(n)
    // SC = O(n)
}


int main(){
    string prefix = "+ab";
    string postfix = prefixToPostfix(prefix);
    cout << "Prefix exp   : " << prefix << endl;
    cout << "Postfix exp : " << postfix << endl;
    return 0;
}