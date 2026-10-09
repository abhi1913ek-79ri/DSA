#include <bits/stdc++.h>
using namespace std;
// 1541. Minimum Insertions to Balance a Parentheses String
// greedy approach 
// maintaining two variables
int minInsertions(string s)
{
    int ans = 0;
    int need = 0;

    for (char ch : s)
    {
        if (ch == '(')
        {
            if (need % 2 == 1)
            {
                ans++;
                need--;
            }

            need += 2;
        }
        else
        {
            need--;

            if (need < 0)
            {
                ans++;
                need = 1;
            }
        }
    }

    return ans + need;
}

int main()
{
    string s;
    getline(cin,s);
    cout << minInsertions(s);
    return 0;
}