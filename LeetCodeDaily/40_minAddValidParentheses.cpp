#include <bits/stdc++.h>
using namespace std;
// LC-921. Minimum Add to Make Parentheses Valid
int minAddToMakeValid(string s){
    stack<char> st;
    int minOp = 0;
    for (auto &ch : s)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                minOp++;
                continue;
            }
            st.pop();
        }
    }
    return minOp + st.size();
}

int main()
{
    string s;
    getline(cin,s);
    cout << minAddToMakeValid(s);
    return 0;
}