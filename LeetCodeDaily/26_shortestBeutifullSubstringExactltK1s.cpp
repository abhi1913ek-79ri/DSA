#include<bits/stdc++.h>
using namespace std;
// 
string shortestBeautifulSubstring(string s, int k) {
    int n = s.length();
    
    int bestLen = INT_MAX;
    string ans = "";

    int ones = 0;

    int l = 0;

    for(int r=0;r<n;r++){
        if(s[r]=='1') ones++;

        while (ones >= k)
        {
            if(ones == k){
                int len = r-l+1;
                string curr = s.substr(l,len);
                
                if(len < bestLen){
                    bestLen = len;
                    ans = curr;
                }else if(len == bestLen){
                    ans = min(curr,curr);
                }
            }

            if(s[l]=='1'){
                ones--;
            }
            l++;
        }
        
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << shortestBeautifulSubstring(s,k);
    return 0;
}