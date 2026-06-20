#include<bits/stdc++.h>
using namespace std;
// Binary Subarrays With Sum subarray sum ki taarah
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4

// Brute - O(n*n*n) - generate all subarrays and find their sum 
int numSubarraysWithSum_brute1(vector<int>& nums,int goal){
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum+=nums[k];
            }
            if(sum==goal) cnt++;
        } 
    }

    return cnt;
    // TC = O(n^3)
    // SC = O(1)
}


// Brute 2 : O(n^2)
int numSubarraysWithSum_brute2(vector<int>& nums,int goal){
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum+=nums[j];
            if(sum == goal) cnt++;
        } 
    }

    return cnt;
    // TC = O(n^2)
    // SC = O(1)
}

// Optimal
int atMost(vector<int>& nums, int goal){
    if(goal < 0) return 0;

    int l = 0, sum = 0, cnt = 0;

    for(int r = 0; r < nums.size(); r++){
        sum += nums[r];

        while(sum > goal){
            sum -= nums[l++];
        }

        cnt += (r - l + 1);
    }
    return cnt;
}
int numSubarraysWithSum_Optimal(vector<int>& nums,int goal){
   return atMost(nums,goal) - atMost(nums,goal-1);
}

int main(){
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << "No of subarrays with sum == " << goal << " is : " << numSubarraysWithSum_brute1(nums,goal)<<endl;
    cout << "No of subarrays with sum == " << goal << " is : " << numSubarraysWithSum_brute2(nums,goal)<<endl;
    cout << "No of subarrays with sum == " << goal << " is : " << numSubarraysWithSum_Optimal(nums,goal)<<endl;
    return 0;
}