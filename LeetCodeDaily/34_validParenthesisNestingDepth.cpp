#include <bits/stdc++.h>
using namespace std;
// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
vector<int> maxDepthAfterSplit(string seq)
{
    vector<int> ans;
    stack<char> st;

    for (auto &ch : seq)
    {
        if (ch == '(')
        {
            st.push(ch);
            ans.push_back((st.size() - 1) % 2);
        }
        else
        {
            st.pop();
            ans.push_back(st.size() % 2);
        }
    }

    return ans;
}
int main()
{
    string s;
    getline(cin,s);
    vector<int> ans = maxDepthAfterSplit(s);
    bool flag = false;
    for(auto& ele : ans){
        if(flag) cout << " ";
        cout << ele;
        flag = true;
    }

    return 0;
}