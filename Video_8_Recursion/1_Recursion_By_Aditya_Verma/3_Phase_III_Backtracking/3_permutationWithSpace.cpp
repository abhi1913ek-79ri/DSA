#include <bits/stdc++.h>
using namespace std;

void solve(string& op, string& ip, int idx, vector<string>& ans)
{
    // Base Condition
    if (idx == ip.size())
    {
        ans.push_back(op);
        return;
    }

    // Take character with space
    op.push_back(' ');
    op.push_back(ip[idx]);

    solve(op, ip, idx + 1, ans);

    // Undo
    op.pop_back();
    op.pop_back();

    // Take character without space
    op.push_back(ip[idx]);

    solve(op, ip, idx + 1, ans);

    // Undo
    op.pop_back();
}

int main()
{
    string ip;
    getline(cin, ip);

    vector<string> ans;

    string op;
    op.push_back(ip[0]);

    solve(op, ip, 1, ans);

    for (auto& ele : ans)
        cout << ele << " ";

    return 0;
}