#include <bits/stdc++.h>
using namespace std;
// LC:3963. Create Grid With Exactly One Path

vector<string> solve(int m, int n)
{
    vector<string> ans;
    string firstRow = "";
    for (int i = 0; i < n; i++)
    {
        firstRow += '.';
    }

    ans.push_back(firstRow);

    string curr = "";
    for (int j = 0; j < n - 1; j++)
    {
        curr += '#';
    }
    curr += '.';
    for (int i = 1; i < m; i++)
    {
        ans.push_back(curr);
    }
    return ans;
    // TC = O(n)
    // SC = O(1)
}
int main()
{
    int m,n;
    cin >> m >> n;
    vector<string> ans = solve(m,n);
    for(auto& row : ans){
        cout << row << endl;
    }
    return 0;
}