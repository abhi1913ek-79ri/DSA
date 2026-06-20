#include <bits/stdc++.h>
using namespace std;

string removeOuterParenthesesNaive(string s)
{
    int numLeft = 0;
    int numRight = 0;
    int left = 0;
    int right = -1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            numLeft++;
        }
        else if (s[i] == ')')
        {
            numRight++;
            right = i;
        }
        if (numLeft == numRight)
        {
            s.erase(left, 1);
            s.erase(--right, 1);
            i -= 2;
            left = i + 1;
            right = -1;
        }
    }
    return s;
    // TC = O(n²)
    // SC = O(1)
}

string removeOuterParenthesesOptimal(string s){
    string ans = "";
    int balance = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i]=='(' && balance){
            ans+=s[i];
        }else if(s[i]==')' && !(balance-1==0)){
            ans+=s[i];
        }
        if(s[i]=='('){
            balance++;
        }else{
            balance--;
        }
    }

    return ans;
}

void printString(string s){
    for(auto c:s) cout<<c;
    cout<<endl;
}

int main()
{
    string s = "(()())(())";
    cout <<"Original String is : ";
    printString(s);
    s = removeOuterParenthesesNaive(s);
    cout <<"Removed parenthesis String is : ";
    printString(s);
    return 0;
}