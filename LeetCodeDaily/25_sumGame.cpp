#include <bits/stdc++.h>
using namespace std;
// 1927. Sum Game

bool sumGame(string num)
{
    int s1 = 0;
    int s2 = 0;
    int q = 0;
    int totalQ = 0;

    int i = 0;
    int mid = num.length() / 2;
    for (auto &ch : num)
    {
        if (i < mid)
        {
            if (ch == '?')
            {
                q++;
                totalQ++;
            }
            else
            {
                s1 += (ch - '0');
            }
        }
        else
        {
            if (ch == '?')
            {
                q--;
                totalQ++;
            }
            else
            {
                s2 += (ch - '0');
            }
        }
        i++;
    }

    if (totalQ % 2 == 1)
        return true;
    return 2 * (s1 - s2) != -9 * q;
}

int main()
{
    string s;
    cin >> s;
    cout << sumGame(s);
    return 0;
}