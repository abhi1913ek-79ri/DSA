#include<bits/stdc++.h>
using namespace std;
// Remove K digits
// ✅ 1. Concept Check

// ✔ Greedy approach correct
// ✔ Monotonic increasing stack correct
// ✔ Local decision making ✔
// ✔ Order preserved ✔
// Optimal : Using monotonic stack : kon sa bada elemnt wrong position pe hain
string removeKdigits(string num, int K) {
    int n = num.length();
    stack<char> st;
    int k = K;
    st.push(num[0]);
    for(int i=1;i<n;i++){
        while (!st.empty() && k > 0 && st.top() > num[i])
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k > 0) {
        st.pop();
        k--;
    }

    string ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop(); 
    }

    reverse(ans.begin(),ans.end());
    int i=0;
    while (i < ans.size() && ans[i] == '0')
    {
        i++;
    }

    ans = ans.substr(i);

    return  ans==""?"0":ans;
    // TC = O(n)
    // SC = O(n)  
}

int main(){
    string  num = "1432219";
    int k = 3;
    string numModified = removeKdigits(num,k);
    cout << "Num : " << num <<endl;
    cout << "Num after modification : " << numModified << endl;
    return 0;
}

// num = "10200", k = 1

// 👉 Tera logic:

// sabse bada = 2
// remove 2 → "1000" ❌

// 👉 Correct:

// 1 > 0 → remove 1
// → "0200" → "200" ✅

// Global max remove ❌
// Local comparison ✅
// greedy