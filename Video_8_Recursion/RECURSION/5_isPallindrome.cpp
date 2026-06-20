#include<bits/stdc++.h>
using namespace std;
bool pallindromeHelper(string str,int i){
    if(i>=str.size()/2) return true;
    if(str[i]!=str[str.size()-i-1]) return false;
    return pallindromeHelper(str,i+1);

}
bool isPalindrome(string str) {
    for (char &ch : str) {
        ch = toupper(ch);
    }
    for (int i = 0; i < str.size(); ) {
        if (!isalnum(str[i])) {
            str.erase(i, 1); // Erase the non-alphanumeric character
        } else {
            i++; // Only increment if no character is erased
        }
    }
    return pallindromeHelper(str,0);
}

int main(){
    string s="#@#%%&% 1nitin1";
    cout<<isPalindrome(s);

    return 0;
}