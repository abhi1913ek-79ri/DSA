#include <bits/stdc++.h>
using namespace std;

// atoi - loop
int myAtoi(string s)
{

    long long ans = 0;
    // bool flag = false;
    int i = 0;
    bool isNeg = false;
    // remove leading spaces
    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }

    if (s[i] == '-')
    {
        i++;
        isNeg = true;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    while (i < s.length() && (s[i] - '0' >= 0 && s[i] - '0' <= 9))
    {
        int digit = s[i] - '0';
        if (ans > (INT_MAX - digit) / 10)
        {
            return isNeg ? INT_MIN : INT_MAX;
        }
        ans = ans * 10 + digit;
        i++;
    }

    if (isNeg)
        ans = -ans;

    return ans;
    // TC = O(n)
    // SC = O(1)
}

// Using Recursion
int atoihelper(string s, int i, long long sum, int sign)
{

    if (i >= s.length() || s[i] < '0' || s[i] > '9')
    {
        return sign * sum;
    }

    int digit = s[i] - '0';
    // overflow condition
    if (sum > ((INT_MAX - digit) / 10))
    {
        return sign == -1 ? INT_MIN : INT_MAX;
    }

    sum = sum * 10 + digit;

    return atoihelper(s, i + 1, sum, sign);
}

int myAtoi2(string s)
{
    int i = 0;
    int sign = 1;
    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }

    if (i >= s.length()) return 0; // <--- safety check

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        sign = 1;
        i++;
    }
    return atoihelper(s, i, 0, sign);
    // TC = O(n)
    // SC = O(n)
}

int main()
{
    string s = "   -42";
    int num = myAtoi2(s);
    cout << s << " to int : " << num;
    return 0;
}