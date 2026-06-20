#include<bits/stdc++.h>
using namespace std;
// Balaned Parenthesis Using stack
bool isValid(string s){
    if(s.length()==1) return false;
    stack<int> temp;
    for(auto ch : s){
        if(ch == '[' || ch == '(' || ch == '{'){ // opening
            temp.push(ch);
        }else{ // closing
            if(temp.empty()) return false;   // FIX
            if(temp.top() == '(' && ch == ')'){
                temp.pop();
            }else if(temp.top() == '[' && ch == ']'){
                temp.pop();
            }else if(temp.top() == '{' && ch == '}'){
                temp.pop();
            }else{
                return false;
            }
        }
    }
    return temp.empty();
    // TC = O(n)
    // SC = O(n)
}

int main(){
    string s = "([])";
    cout << "S = " << s << endl;
    cout << "Valid : " << isValid(s) << endl;
    return 0;
}