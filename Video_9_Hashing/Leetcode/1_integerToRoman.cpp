#include<bits/stdc++.h>
using namespace std;

// Integer To Roman
string intToRoman(int num){
    vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> dec = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    string ans = "";
    while (num) 
    {
        int j = 0;
        for(auto decNum : dec){
            if(num/decNum>0){
                int times = num/decNum;
                num = num%decNum;
                for(int i = 0;i<times;i++){
                    ans += roman[j];
                }
                break;
            }
            j++;
        }
    }

    return ans;
    // O(1)
}

// Using Greedy Logic
string intToRoman2(int num){
    vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string ans = "";

    for(int i =0 ; i< val.size();i++){ // O(13)
        while (num>=val[i]) // O(39)
        {
            ans += roman[i];
            num -= val[i];
        }
    }
    return ans;
    // TC = O(39*13) =~ O(1)
    // SC = O(26) =~ O(1)
}

int main(){
    int n = 3999;
    cout << "Decimal Num : " << n << endl;
    cout << "Roman Num : " << intToRoman2(n)<<endl;
    return 0;
}