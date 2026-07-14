#include <bits/stdc++.h>
using namespace std;
//  sum of squares
bool judgeSquareSum(int c)
{
    int n = sqrt(c);

    int l = 0;
    int r = n;

    while (l <= r)
    {
        long long curr = 1LL * l * l + 1LL * r * r;
        if (curr == 1LL * c)
            return true;
        else if (curr < 1LL * c)
            l++;
        else
            r--;
    }

    return false;
}


int main()
{
    int t;
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        cout << judgeSquareSum(c) <<endl;
    }

    return 0;
}