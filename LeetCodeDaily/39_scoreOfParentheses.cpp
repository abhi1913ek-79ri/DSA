#include <bits/stdc++.h>
using namespace std;
// 856. Score of Parentheses
int scoreOfParentheses(string s)
{
    int n = s.length();
    int result = 0;
    int depth = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            depth++;
        }
        else
        {
            depth--;

            if (s[i - 1] == '(')
            {
                result += pow(2, depth);
            }
        }
    }
    return result;
}

int main()
{
    string s;
    getline(cin,s);
    cout << scoreOfParentheses(s);
    return 0;
}