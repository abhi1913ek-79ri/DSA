#include<bits/stdc++.h>
using namespace std;
// string sapce limit exceed solution : use iteration insteed of recursion
bool isPalindrome(string str) {
        // Create a new string with only alphanumeric characters and convert to uppercase
        string filteredStr = "";
        for (char ch : str) {
            if (isalnum(ch)) {
                filteredStr += toupper(ch); 
            }
        }
        int left = 0, right = filteredStr.size() - 1;
        while (left < right) {
            if (filteredStr[left] != filteredStr[right]) {
                return false; 
            }
            left++;
            right--;
        }

        return true;
}

int main(){
    string s="#@#%%&% 1nitin1";
    cout<<isPalindrome(s);

    return 0;
}