#include<bits/stdc++.h>
using namespace std;

unsigned int binToDec(string s){
    unsigned int ans  = 0;
    unsigned int r = 1;
    for(int i = s.length()-1;i>=0 ; i--){
        ans +=  (s[i]-'0')*r;
        r*=2;
    }
    return ans;
}

bool hasAllCodes(string s,int k){
    if (s.length() < k)
    return false;
    int limitingNum = 1 << k; //pow(2,k)
    vector<bool> Notfound(limitingNum,true);

    for(int i= 0;i<=s.length()-k;i++){
        string subStr = "";
        int l = i;
        int r = i+k-1;

        while (l<=r)
        {
            subStr += s[l];
            l++;
        }

        int num = binToDec(subStr);
        Notfound[num] = false;
    }

    for(auto isTrue : Notfound){
        if(isTrue == true){
            return false;
        }
    }

    return true;
}

int main(){
    string s = "00110110";
    bool ans = hasAllCodes(s,2);
    cout << " Result : " << ans<<endl;
    return 0;
}