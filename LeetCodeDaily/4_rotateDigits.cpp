#include <bits/stdc++.h>
using namespace std;
// Rotated Digits
int rotatedDigits(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int m = i;
        bool isChanged = false;
        bool isValid = true;
        while (m > 0)
        {
            int digit = m % 10;
            if(digit == 3 || digit == 4 ||digit == 7){
                isValid = false;
                break;
            }
            if(digit ==2 || digit == 5 || digit == 6 || digit == 9){
                isChanged = true;
            }
            m/=10;
        }
        if (isValid && isChanged) cnt++;
    }
    return cnt;
    // TC = O(nlogn)
    // SC = O(1)
}

int main()
{
    int n = 10;
    cout << "Number of good numbers : " << rotatedDigits(n) << endl;
    return 0;
}