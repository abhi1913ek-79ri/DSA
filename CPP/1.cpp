#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> indexxed;

        for(int i=0;i<n;i++){
            indexxed.push_back({nums[i],i});
        }

        sort(indexxed.begin(),indexxed.end(),[](auto & a, auto &b){
            return a.first>b.first;
        });

        vector<pair<int,int>> maxK(indexxed.begin(),indexxed.begin()+k);

        sort(maxK.begin(),maxK.end(),[](auto &a ,auto &b){
            return a.second<b.second;
        });

        vector<int> result;

        for(auto& [val,index]:maxK){
            result.push_back(nums[index]);
        }

        return result;
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    topKFrequent(nums, k);
    return 0;
}
