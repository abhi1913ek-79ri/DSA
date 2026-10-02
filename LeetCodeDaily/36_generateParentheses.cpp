#include <bits/stdc++.h>
using namespace std;
// 22. Generate Parentheses

// Brute Force
void solve_1(string op, int n, vector<string> &ans)
{
    // base conditiion
    if (n == 0)
    {
        ans.push_back(op);
        return;
    }

    // open
    op.push_back('(');
    solve_1(op, n - 1, ans);
    // undo
    op.pop_back();

    // close
    op.push_back(')');
    solve_1(op, n - 1, ans);

    // undo
    op.pop_back();
}

bool isValid(string s)
{
    int cnt = 0;
    for (auto &ch : s)
    {
        if (cnt < 0)
            return false;
        cnt += ch == '(' ? 1 : -1;
    }
    return cnt == 0;
}
vector<string> generateParenthesis_1(int n)
{
    vector<string> ans;
    solve_1("", 2 * n, ans);
    vector<string> finalAns;
    for (auto &ele : ans)
    {
        if (isValid(ele))
            finalAns.push_back(ele);
    }
    return finalAns;
}

// Better solution
// Balanced based parentheses
void solve_2(string op, int n, int cnt, vector<string> &ans)
{
    // base conditiion
    if (n == 0)
    {
        if (cnt == 0)
        {
            ans.push_back(op);
        }
        return;
    }

    if (cnt < 0)
    {
        return;
    }

    // open
    op.push_back('(');
    solve_2(op, n - 1, cnt + 1, ans);
    // undo
    op.pop_back();

    // close
    op.push_back(')');
    solve_2(op, n - 1, cnt - 1, ans);

    // undo
    op.pop_back();
}

vector<string> generateParenthesis_2(int n)
{
    vector<string> ans;
    solve_2("", 2 * n, 0, ans);
    return ans;
}

// Optimised
// Contraints based backtracking
void solve_3(string op, int open, int close, vector<string> &ans)
{
    // base conditiion
    if (open == 0 && close == 0)
    {
        ans.push_back(op);
        return;
    }

    // open
    if (open > 0)
    {
        op.push_back('(');
        solve_3(op, open - 1, close, ans);
        // undo
        op.pop_back();
    }

    // close
    if (close > open)
    {
        op.push_back(')');
        solve_3(op, open, close - 1, ans);
        // undo
        op.pop_back();
    }
}
vector<string> generateParenthesis_3(int n)
{
    vector<string> ans;
    solve_3("", n, n, ans);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis_3(n);
    bool flag = false;
    for(auto& ele : ans){
        if(flag) cout << " ";
        cout << ele;
        flag = true;
    }
    return 0;
}