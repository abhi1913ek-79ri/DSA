#include <bits/stdc++.h>
using namespace std;
// BruteForce Cases ke tareeke se soch ke 
string addBinaryBrute(string a, string b)
{
    int lenA = a.length();
    int lenB = b.length();

    int ptA = lenA - 1;
    int ptB = lenB - 1;

    int carry = 0;
    string ans = "";

    while (ptA >= 0 && ptB >= 0)
    {
        if (a[ptA] == '0' && b[ptB] == '1')
        {
            if (carry == 0)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
                carry = 1;
            }
        }
        else if (a[ptA] == '1' && b[ptB] == '1')
        {
            if (carry == 0)
            {
                ans += '0';
                carry = 1;
            }
            else
            {
                ans += '1';
                carry = 1;
            }
        }
        else if (a[ptA] == '0' && b[ptB] == '0')
        {
            if (carry == 0)
            {
                ans += '0';
            }
            else
            {
                ans += '1';
                carry = 0;
            }
        }
        else if (a[ptA] == '1' && b[ptB] == '0')
        {
            if (carry == 0)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
                carry = 1;
            }
        }
        ptA--;
        ptB--;
    }
    while (ptA >= 0)
    {
        if (carry == 1)
        {
            if (a[ptA] == '0')
            {
                ans += '1';
                carry = 0;
            }
            else
            {
                ans += '0';
                carry = 1;
            }
        }
        else
        {
            ans += a[ptA];
        }

        ptA--;
    }

    while (ptB >= 0)
    {
        if (carry == 1)
        {
            if (b[ptB] == '0')
            {
                ans += '1';
                carry = 0;
            }
            else
            {
                ans += '0';
                carry = 1;
            }
        }
        else
        {
            ans += b[ptB];
        }

        ptB--;
    }

    if (carry == 1)
    {
        ans += '1';
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// Optimal Universal formula type mathematical solutionk sum%2 , sum /2
// Binary conversion through ASCII values
string addBinaryOptimal(string a , string b){
    int i = a.length()-1;
    int j = b.length()-1;

    string ans  = "";
    int carry = 0;

    while(i>=0 || j>=0 || carry){
        int sum  = carry;
        int binDigit = 0;
        if(i>=0) sum+=a[i--]-'0';
        if(j>=0) sum+=b[j--]-'0';

        binDigit = sum%2;
        carry = sum / 2;

        ans += binDigit + '0';

    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    string a, b;

    cout << "Enter first binary string: ";
    cin >> a;

    cout << "Enter second binary string: ";
    cin >> b;

    cout << "\nBrute Force Result: "
         << addBinaryBrute(a, b) << endl;

    cout << "Optimal Result: "
         << addBinaryOptimal(a, b) << endl;

    return 0;
}
