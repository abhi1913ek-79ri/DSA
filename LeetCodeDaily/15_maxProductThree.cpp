#include<bits/stdc++.h>
using namespace std;
// LC : 628
// Brute : 3 nested loops
int maximumProduct1(vector<int>& nums){
    int n = nums.size();
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                int prod = nums[i]*nums[j]*nums[k];
                maxi = max(maxi,prod);
            }
            
        }
        
    }
    return maxi;
    // TC = O(n^3)
    // SC = O(1)
}

/*

// Better : only works for positive
// step 1 : find max , remove max
// step 2 : find max prod of 2
// step 3 : return max*maxprod2
int maximumProduct2(vector<int>& nums){
    int n = nums.size();
    auto maxIdx = max_element(nums.begin(),nums.end());
    int maxi = *maxIdx;
    nums.erase(maxIdx);
    int maxiProd = INT_MIN;

    for(int i = 0;i<n-1;i++){
        for(int j = i+1; j<n-1 ; j++){
            maxiProd = max(maxiProd,nums[i]*nums[j]);
        }
    }
    return maxi*maxiProd;
    // TC = O(n^2)
    // SC = O(1)
}
*/

// Optimal : sorting
// 2 possibilities 
// 1 -> l1*l2*l3
// 2 -> s1*s2*l1
// return max of two above cases
int maximumProduct3(vector<int>& nums){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int possible1 = nums[0]*nums[1]*nums[n-1];
    int possible2 = nums[n-3]*nums[n-2]*nums[n-1];
    return max(possible1,possible2);
    // TC = O(nlogn) 
    // SC = O(1)
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& num : nums)
    {
        cin >> num;
    }

    int ans = maximumProduct3(nums);

    cout << ans;
    
    return 0;
}