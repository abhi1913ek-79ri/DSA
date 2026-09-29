#include <bits/stdc++.h>
using namespace std;
// 2267. Check if There Is a Valid Parentheses String Path
bool solve(int i, int j, int openCnt, vector<vector<char>> &grid, int n, int m, vector<vector<vector<int>>> &dp)
{
    openCnt += (grid[i][j] == '(') ? 1 : (-1);
    // base condition
    if (i == n - 1 && j == m - 1)
    {
        return openCnt == 0;
    }

    if (openCnt < 0)
    {
        return false;
    }

    int remaining = m - 1 - j + n - 1 - i;

    if (openCnt > remaining)
        return false;

    if (dp[i][j][openCnt] != -1)
    {
        return dp[i][j][openCnt];
    }

    if (j + 1 < m && solve(i, j + 1, openCnt, grid, n, m, dp))
    {
        return dp[i][j][openCnt] = 1;
    }

    if (i + 1 < n && solve(i + 1, j, openCnt, grid, n, m, dp))
    {
        return dp[i][j][openCnt] = 1;
    }

    return dp[i][j][openCnt] = 0;
}

bool hasValidPath(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    if (grid[0][0] == ')')
        return false;
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(
               m, vector<int>(n + m + 1, -1)));

    return solve(0, 0, 0, grid, n, m, dp);
}

int main()
{   
    int n;
    cin >> n;
    vector<vector<char>> grid;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        vector<char> row;
        for(int j=0;j<m;j++){
            char ch;
            cin >> ch;
            row.push_back(ch);
        }
        grid.push_back(row);
    }

    cout << hasValidPath(grid);
    return 0;
}