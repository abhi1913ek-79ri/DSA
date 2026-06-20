#include<bits/stdc++.h>
using namespace std;

string reverseWordsNaive(string s) {// using stack
    stack<string> st;
    string word ="";
    // remove leading spaces
    int it = 0;
    while (s[it]==' ')
    {
        it++;
    }

    // remove trailing spaces
    int itEnd = s.size()-1;
    while (s[itEnd]==' ')
    {
        itEnd--;
    }

    for(int i = it;i<=itEnd;i++){
        if(s[i]==' '){
            if(!word.empty()){
                st.push(word);
                word = "";
            }
        }else{
            word+=s[i];
        }
    }
    if(!word.empty()) st.push(word);

    string ans = "";
    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
        if(!st.empty()) ans+='_';
        
    }

    return ans;
    // TC - O(n+n) 
    // SC = O(n)
}

// reverse logic approach start from end 
string reverseWordsOptimal(string s){
    // space for answer - not considered
    string ans = "";

    // remove leading spaces
    int it = 0;
    while (it < s.length() && s[it] == ' ') it++;

    
    // remove trailing spaces
    int itEnd = s.size()-1;
    while (itEnd >= it && s[itEnd] == ' ') itEnd--;


    // Edge case: all spaces or empty string
    if (it > itEnd) return "";

    // main logic
    int i = itEnd;
    string word = "";
    while (i>=it){
        if(s[i]==' '){
            if(!word.empty()){
                if (!ans.empty()) ans += " ";
                ans += word;
                word = "";
            }
        }else{
            word = s[i] + word;
        }
        i--;
    }
    if(word!=""){
        if(ans!=""){
            ans+=" " + word;
        }else{
            ans+=word;
        }
        
    }
    return  ans;
    // TC = O(n)
    // SC = O(1)
}


void printString(string s){
    for(auto c:s) cout<<c;
    cout<<endl;
}

int main(){
    string s = "           this is an amazing         program         ";
    string output = reverseWordsOptimal(s);
    cout << "Input : ";
    printString(s);
    cout << "Output : ";
    printString(output);

    
    return 0;
}