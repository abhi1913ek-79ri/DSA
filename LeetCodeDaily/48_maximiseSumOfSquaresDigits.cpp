#include <bits/stdc++.h>
using namespace std;
// LC : 3723. Maximize Sum of Squares of Digits
// greedy approach
string maxSumOfSquares(int num, int sum)
{
    int sumDigit = 0;
    string n = "";
    while (num)
    {
        if (sumDigit + 9 <= sum)
        {
            n += '9';
            sumDigit += 9;
        }
        else
        {
            n += to_string(sum - sumDigit);
            sumDigit += sum - sumDigit;
        }
        num--;
    }

    if (sumDigit != sum)
    {
        return "";
    }
    return (n);
}

int main()
{
    int num;
    cin >> num;
    int sum;
    cin >> sum;
    cout << maxSumOfSquares(num,sum);
    return 0;
}