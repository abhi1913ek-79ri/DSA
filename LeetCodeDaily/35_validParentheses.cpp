#include <bits/stdc++.h>
using namespace std;
// LC - 20 : Valid Parentheses
bool isValid(string s)
{
    stack<int> temp;
    for (auto ch : s)
    {
        if (ch == '[' || ch == '(' || ch == '{')
        { // opening
            temp.push(ch);
        }
        else
        { // closing
            if (temp.empty())
                return false; // FIX

            if (temp.top() == '(' && ch == ')')
            {
                temp.pop();
            }
            else if (temp.top() == '[' && ch == ']')
            {
                temp.pop();
            }
            else if (temp.top() == '{' && ch == '}')
            {
                temp.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return temp.empty();
    // TC = O(n)
    // SC = O(n)
}

int main()
{
    string s;
    getline(cin,s);
    cout << isValid(s);
    return 0;
}