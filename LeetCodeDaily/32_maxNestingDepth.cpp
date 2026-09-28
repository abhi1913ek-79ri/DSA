#include <bits/stdc++.h>
using namespace std;
// 1614. Maximum Nesting Depth of the Parentheses
int maxDepth(string s)
{
    int cnt = 0;
    int depth = 0;
    for (auto &ch : s)
    {
        if (ch == '(')
        {
            cnt++;
        }
        else if (ch == ')')
        {
            depth = max(depth, cnt);
            cnt--;
        }
    }

    return depth;
}

int main()
{
    string s;
    getline(cin,s);
    cout << maxDepth(s);
    return 0;
}