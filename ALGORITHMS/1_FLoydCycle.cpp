#include<bits/stdc++.h>
using namespace std;
// find duplicate number
// floyd cycle detection -- tortoise and here
// fast and slow pointer
int findDuplicate(vector<int>& nums){
    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while (slow!=fast);
    // loop detected

    // find Entry point
    slow = nums[0];
    while (slow!=fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    

    return slow;
    // TC = O(n)
    // SC = O(1)
}

// pigeon hole -- binary search on answers
int findDuplicate2(vector<int>& nums) {

    int low = 1;
    int high = nums.size() - 1;

    while(low < high){

        int mid = low + (high - low)/2;

        int count = 0;

        for(int num : nums){
            if(num <= mid) count++;
        }

        if(count > mid)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
    // baki hain
}




int main(){
    vector<int> nums = {3,1,3,4,2};
    cout << "Duplicate : " << findDuplicate(nums) <<endl;
    return 0;
}