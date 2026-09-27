#include <bits/stdc++.h>
using namespace std;
// 1190. Reverse Substrings Between Each Pair of Parentheses
string reverseParentheses(string s)
{
    stack<string> st;
    st.push("");
    for (auto &ch : s)
    {
        if (ch == '(')
        {
            st.push("");
        }
        else if (ch == ')')
        {
            string top = st.top();
            reverse(top.begin(), top.end());
            st.pop();
            st.top() += top;
        }
        else
        {
            st.top() += ch;
        }
    }

    return st.top();
}

int main()
{
    string s;
    getline(cin,s);
    cout << reverseParentheses(s);
    return 0;
}