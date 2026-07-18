#include <bits/stdc++.h>
using namespace std;
// gcd min max
int gcd(int a, int b)
{
    while (b)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }

    return a;
}
int findGCD(vector<int> &nums)
{
    int maxi = *max_element(nums.begin(), nums.end());
    int mini = *min_element(nums.begin(), nums.end());

    return gcd(maxi, mini);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& num : nums)
    {
        cin >> num;
    }
    int ans = findGCD(nums);
    cout << ans << endl;
    return 0;
}