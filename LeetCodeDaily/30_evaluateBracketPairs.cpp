#include <bits/stdc++.h>
using namespace std;
// 1807. Evaluate the Bracket Pairs of a String
string evaluate(string s, vector<vector<string>> &knowledge)
{
    int n = s.length();
    map<string, string> mpp;
    for (auto &p : knowledge)
    {
        auto key = p[0];
        auto val = p[1];
        mpp[key] = val;
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (ch == '(')
        {
            i++;
            string key = "";
            while (s[i] != ')')
            {
                key += s[i];
                i++;
            }
            if (mpp.find(key) != mpp.end())
            {
                ans += mpp[key];
            }
            else
            {
                ans += '?';
            }
        }
        else
        {
            ans += ch;
        }
    }

    return ans;
}


int main()
{
    string s;
    getline(cin, s);

    int n;
    cin >> n;

    vector<vector<string>> knowledge(n, vector<string>(2));

    for (auto &p : knowledge)
    {
        cin >> p[0] >> p[1];
    }

    cout << evaluate(s, knowledge);

    return 0;
}