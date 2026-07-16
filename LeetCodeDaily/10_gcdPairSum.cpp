#include<bits/stdc++.h>
using namespace std;
// 3867. Sum of GCD of Formed Pairs
int gcd(int a , int b){
    while (b)
    {
        int temp = a;
        a = b;
        b = temp%b;
    }

    return a;
    // TC = O(logN)
    // SC = O(1)
}

vector<int> createPrefixGcd(vector<int>& nums){
    int n = nums.size();
    int maxi = INT_MIN;
    vector<int> prefixGcd;
    for(int i=0;i<n;i++){
        maxi = max(maxi,nums[i]);
        int g = gcd(maxi,nums[i]);
        prefixGcd.push_back(g);
    }

    return prefixGcd;
    // TC = O(nlogn)
    // SC = O(n)
}

long long gcdSum(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int r = n-1;
    long long sum = 0;
    vector<int> prefixGcd = createPrefixGcd(nums);
    sort(prefixGcd.begin(),prefixGcd.end());
    while(l<r){
        sum += gcd(prefixGcd[l],prefixGcd[r]);
        l++;
        r--;
    }
    return sum;
    // TC = O(nlogn)
    // SC = O(n)
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }
    cout << gcdSum(nums) << endl;
    return 0;
}