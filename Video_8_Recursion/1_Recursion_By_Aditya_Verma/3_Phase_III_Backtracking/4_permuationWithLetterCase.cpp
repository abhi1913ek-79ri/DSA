#include<bits/stdc++.h>
using namespace std;
// LC-784. Letter Case Permutation
void solve(string op,string& ip,int idx,vector<string>& ans){
    if(idx == ip.length()){
        ans.push_back(op);
        return;
    }

    if(isalpha(ip[idx])){
        // first choice
        op.push_back(tolower(ip[idx]));
        solve(op,ip,idx+1,ans);

        // undo 
        op.pop_back();
        op.push_back(toupper(ip[idx]));
        solve(op,ip,idx+1,ans);
        op.pop_back();
    }else{
        op.push_back(ip[idx]);
        solve(op,ip,idx+1,ans);
        op.pop_back();
    }
}
vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    solve("",s,0,ans);
    return ans;
}

int main(){
    string s;
    getline(cin,s);
    vector<string> ans = letterCasePermutation(s);
    bool flag = false;
    for(auto& ele:ans){
        if(flag){
            cout << " ";
        }
        cout << ele;
        flag = true;
    }
    return 0;
}