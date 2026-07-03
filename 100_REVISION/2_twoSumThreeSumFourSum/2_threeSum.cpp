#include<bits/stdc++.h>
using namespace std;
// Three sum 

// brute
vector<vector<int>> threeSum_brute(vector<int>& nums){
    int n = nums.size();
    set<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                int sum = nums[i]+nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> temp = { nums[i],nums[j] , nums[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(ans.begin(),ans.end());
    // TC = O(n^3)
    // SC = O(1)
}


// better - hashMap for two
vector<vector<int>> threeSum_better(vector<int>& nums){
    int n = nums.size();
    
    set<vector<int>> ans;
    // hashMap 
    for(int i=0;i<n;i++){
        unordered_map<int,int> mpp;
        for(int j=i+1;j<n;j++){
            int need  = -(nums[i]+nums[j]);
            if(mpp.find(need) != mpp.end()){
                vector<int> temp = {nums[i],nums[j],need};
                sort(temp.begin(),temp.end());
                ans.insert(temp);
            }
            mpp[nums[j]]++;
        }
    }

    return vector<vector<int>>(ans.begin(),ans.end());
    // TC = O(n^2*logM) , M = numbber of triplet
    // SC = O(n)
    // Gives TLE , In leetcode
}


// Optimal  - sorting + two pointers + skip duplicates
// fix i 
// j = i+1 , k = n-1;
// now seerch for target = j to k - nums[i];
// also skip i,j,k when it is same as previous
vector<vector<int>> threeSum_optimal(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];

            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]) j++;
                while(j<k && nums[k] == nums[k+1]) k--;
            }
        }
    }

    return ans;
    // TC = O(n*n)
    // SC = O(n) for return ans
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto& num : nums){
            cin >> num;
        }

        vector<vector<int>> ans = threeSum_optimal(nums);
        sort(ans.begin(),ans.end());
        for(auto& arr : ans){
            cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        }
    }
    return 0;
}

/*2. Three Sum
Problem
a+b+c=0
Brute Force
Intuition

Har possible triplet check karo.

Algorithm
for i
   for j
      for k

          if sum==0

Duplicate remove using set.

Complexity

Time

O(n³)

Space

O(set)

Better (Hashing)
Intuition

Fix one element.

Baaki 2 Sum bana do.

for every i

    target = -nums[i]

    HashMap use karo
Algorithm
for i

    map clear

    for j=i+1

         need=target-nums[j]

         if found

             insert triplet into set

         store nums[j]

Duplicate remove using set.

Complexity

Time

O(n² log n)

Space

O(n)

Optimal (Sorting + Two Pointers)
Intuition

Sabse important.

Sort kar do.

Fix first number.

Baaki do numbers two pointers se search karo.

i

l=i+1

r=n-1
sum=nums[i]+nums[l]+nums[r]

If

sum<0

Left increase.

If

sum>0

Right decrease.

Else

Answer.

Move both pointers.

Skip duplicates.

Algorithm
sort

for i

   skip duplicates

   l=i+1
   r=n-1

   while(l<r)

        sum

        if sum<0
             l++

        else if sum>0
             r--

        else

             store

             l++
             r--

             skip duplicates
Complexity

Time

O(n²)

Space

O(1)*/