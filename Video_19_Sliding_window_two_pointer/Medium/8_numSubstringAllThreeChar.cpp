#include<bits/stdc++.h>
using namespace std;
// Number of Substrings Containing All Three Characters
// Input: s = "abcabc"
// Output: 10
// BruteForce - 1 : Generate all , check all three characters area atList ones or not
int numberOfSubstrings_brute1(string s){
    int n = s.length();

    int cnt =  0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int cntA = 0;
            int cntB = 0;
            int cntC = 0;
            for (int k = i; k <= j; k++)
            {
                if(s[k]=='a') cntA++;
                if(s[k]=='b') cntB++;
                if(s[k]=='c') cntC++;
            }

            if(cntA>0&&cntB>0&&cntC>0) cnt++;
            
        }
    }

    return cnt;
    // TC = O(n*n*n)
    // SC = O(3) = O(1)
}

// Brute 2 : O(n*n)
int numberOfSubstrings_brute2(string s){
    int n = s.length();

    int cnt =  0;

    for (int i = 0; i < n; i++)
    {
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        for (int j = i; j < n; j++)
        {
            if(s[j]=='a') cntA++;
            if(s[j]=='b') cntB++;
            if(s[j]=='c') cntC++;
            if(cntA>0&&cntB>0&&cntC>0) cnt++;
        }
    }

    return cnt;
    // TC = O(n*n)
    // SC = O(3) = O(1)
}

// Brute 2 : O(n*n)
int numberOfSubstrings_brute3(string s){
    int n = s.length();

    int cnt =  0;

    for (int i = 0; i < n; i++)
    {
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        for (int j = i; j < n; j++)
        {
            if(s[j]=='a') cntA++;
            if(s[j]=='b') cntB++;
            if(s[j]=='c') cntC++;
            if(cntA>0&&cntB>0&&cntC>0){
                cnt += n-j;
                break;
            }
        }
    }

    return cnt;
    // TC = O(n*n)
    // SC = O(3) = O(1)
}



// Optimal : O(n) ->  Two pointers : lastSeen trick + minimul window - where comdition is true
// Every character end of substring 
int numberOfSubstrings_Optimal(string s){
    int n = s.length();

    vector<int> lastSeen = {-1,-1,-1};

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        lastSeen[s[i]-'a']=i;
        if(lastSeen[0]>-1 && lastSeen[1]>-1 && lastSeen[2]>-1){
            int startIdx =  min(lastSeen[0],lastSeen[1]);
            startIdx =  min(startIdx,lastSeen[2]);
            cnt += startIdx+1;
        }
    }
    return cnt;
    // TC = O(n)
    // SC = O(1)
}



int main(){
    string s1 = "abcabc"; // 10
    string s2 = "aaacb";  // 3
    string s3 = "abc";    // 1
    cout << "Brute 1 : \n";
    cout << "No. of substring  : " << numberOfSubstrings_brute1(s1)<<endl;
    cout << "No. of substring  : " << numberOfSubstrings_brute1(s2)<<endl;
    cout << "No. of substring  : " << numberOfSubstrings_brute1(s3)<<endl;
    cout << "Brute 2 : \n";
    cout << "No. of substring  : " << numberOfSubstrings_brute2(s1)<<endl;
    cout << "No. of substring  : " << numberOfSubstrings_brute2(s2)<<endl;
    cout << "No. of substring  : " << numberOfSubstrings_brute2(s3)<<endl;
    cout << "Brute 3 : \n";
    cout << "No. of substring  : " << numberOfSubstrings_brute3(s1)<<endl;
    cout << "No. of substring  : " << numberOfSubstrings_brute3(s2)<<endl;
    cout << "No. of substring  : " << numberOfSubstrings_brute3(s3)<<endl;
    cout << "Optimal : \n";
    cout << "No. of substring  : " << numberOfSubstrings_Optimal(s1)<<endl;
    cout << "No. of substring  : " << numberOfSubstrings_Optimal(s2)<<endl;
    cout << "No. of substring  : " << numberOfSubstrings_Optimal(s3)<<endl;
    return 0;
}