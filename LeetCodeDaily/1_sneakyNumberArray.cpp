// Approach	Time	Space	Works For	Comment
// Sorting	O(n log n)	O(1)	Any integers	Memory-efficient, slightly slower
// Visited Array	O(n)	O(n)	Only if 0 ≤ num < n	Super fast, but limited range

#include<bits/stdc++.h>
using namespace std;

vector<int> getSneakyNumbersBrute(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0;i<nums.size();i++){
        for(int j = i+1;j<nums.size();j++){
            if(nums[i]==nums[j]){
                ans.push_back(nums[i]);
                break;
            }
        }
    }
    return ans;
    // TC = O(n*n)
    // SC = O(1)
}

// using sorting nlogn - better in time and best in space
vector<int> getSneakyNumbersBetter(vector<int>& nums){
    vector<int> ans;
    sort(nums.begin(),nums.end());

    for(int i = 0 ; i<nums.size()-1;i++){
        if(nums[i] == nums[i+1]){
            ans.push_back(nums[i]);
            int num = nums[i];
            while (nums[i] == num && i<nums.size())
            {
                i++;
            }
            i--; // becoz its incremenjted 14 extra time ;
        }
    }

    return ans;
    //  TC = nlogn 
    //  SC = O(1)
}

// Hash/map etc
vector<int> getSneakyNumbersBetter2(vector<int>& nums){
    vector<bool> visited(nums.size(),false);
        vector<int> ans;

        for(auto num : nums){
            if(visited[num]) ans.push_back(num);
            else visited[num] = true;
        }

    return ans;
    // TC = o(n)
    // SC = O(n)
}


// Optimal - answer .... specialy for Finding duplicates when numebers in range 0 to n etc
// 🔹 Approach 5 — Index Marking (⚡ Most Optimal for 0…n Range)
// This is a trick often used in LeetCode for arrays with positive integers in range 1…n.
// Idea: Use the array itself as a hash. Mark visited indices as negative.
vector<int> getSneakyNumbersOptimal(vector<int>& nums){
    // using array itself as hash- array
    vector<int> ans;
    for(int i = 0; i<nums.size();i++){
        int idx = abs(nums[i]);
        if(nums[idx]<0) ans.push_back(idx);
        else nums[idx] = -nums[idx];
    }

    return ans;
    // TC  = O(n)
    // SC = O(1)
}


void printArray(vector<int> & arr){
    for(auto ele : arr){
        cout<<ele<<" ";
    }
    cout<<"\n";
}

int main(){
    vector<int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};

    vector<int> sneakyNumbers = getSneakyNumbersOptimal(nums);

    cout << " Sneaky numbers : ";
    printArray(sneakyNumbers);
    return 0;
}