#include <bits/stdc++.h>
using namespace std;




string largestOddNumber(string num){
    for(int i=num.length()-1;i>=0;i--){
        if((num[i]-'0')%2==1){
            string ans = num.substr(0,i+1);
            ans = ans.erase(0,ans.find_first_not_of('0'));
            return ans;
        }
    }
    return "";
}


void printString(string s){
    for(auto c:s) cout<<c;
    cout<<endl;
}

int main(){
    string num = "0124502312";
    cout <<"Original String is : ";
    printString(num);
    string largestOdd = largestOddNumber(num);
    cout <<"Largest odd Integer : ";
    printString(largestOdd);
    return 0;
}