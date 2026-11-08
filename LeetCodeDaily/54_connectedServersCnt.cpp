#include <bits/stdc++.h>
using namespace std;
// 1267. Count Servers that Communicate
int solve(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> row(grid.size(), 0);
    vector<int> col(grid[0].size(), 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] > 0)
            {
                row[i]++;
                col[j]++;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && (row[i] >= 2 || col[j] >= 2))
            {
                cnt++;
            }
        }
    }

    return cnt;
    // TC = O(n*m)
    // SC = O(n+m)
}

int main()
{   
    int n;
    cin >> n;
    vector<vector<int>>grid(n);
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        vector<int> row(m);
        for(int j=0;j<m;j++){
            int ele;
            cin >> ele;
            row[j] = ele;
        }

        grid[i]=row;
    }


    cout << solve(grid);

    return 0;
}