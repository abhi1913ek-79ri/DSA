#include <bits/stdc++.h>
using namespace std;
// LC-301. Remove Invalid Parentheses

void solve(string& op, int idx, string& s,
           int open,
           int remOpen,
           int remClose,
           unordered_set<string>& st)
{
    // Invalid prefix
    if (open < 0)
        return;

    // Not enough characters left to remove
    if (remOpen + remClose > s.length() - idx)
        return;

    // Base condition
    if (idx == s.length())
    {
        if (open == 0 && remOpen == 0 && remClose == 0)
        {
            st.insert(op);
        }

        return;
    }

    char ch = s[idx];

    // Non-parenthesis character
    if (ch != '(' && ch != ')')
    {
        op.push_back(ch);

        solve(op, idx + 1, s,
              open,
              remOpen,
              remClose,
              st);

        op.pop_back();
    }

    // '('
    else if (ch == '(')
    {
        // OPTION 1: Remove '('
        if (remOpen > 0)
        {
            solve(op, idx + 1, s,
                  open,
                  remOpen - 1,
                  remClose,
                  st);
        }

        // OPTION 2: Keep '('
        op.push_back(ch);

        solve(op, idx + 1, s,
              open + 1,
              remOpen,
              remClose,
              st);

        op.pop_back();
    }

    // ')'
    else
    {
        // OPTION 1: Remove ')'
        if (remClose > 0)
        {
            solve(op, idx + 1, s,
                  open,
                  remOpen,
                  remClose - 1,
                  st);
        }

        // OPTION 2: Keep ')'
        if (open > 0)
        {
            op.push_back(ch);

            solve(op, idx + 1, s,
                  open - 1,
                  remOpen,
                  remClose,
                  st);

            op.pop_back();
        }
    }
}


vector<string> removeInvalidParentheses(string s)
{
    int remOpen = 0;
    int remClose = 0;

    // Calculate minimum removals
    for (char ch : s)
    {
        if (ch == '(')
        {
            remOpen++;
        }
        else if (ch == ')')
        {
            if (remOpen > 0)
                remOpen--;
            else
                remClose++;
        }
    }

    unordered_set<string> st;
    string op;

    solve(op, 0, s,
          0,
          remOpen,
          remClose,
          st);

    // For deterministic output
    vector<string> ans(st.begin(), st.end());
    sort(ans.begin(), ans.end());

    return ans;
}


int main()
{
    string s;
    cin >> s;

    vector<string> ans = removeInvalidParentheses(s);

    for (string& str : ans)
    {
        cout << str << endl;
    }

    return 0;
}