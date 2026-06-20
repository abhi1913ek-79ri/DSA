#include<bits/stdc++.h>
using namespace std;
// Number of greater Element right to the number


// Brute Force
int reversePairs(vector<int>& nums){
    int n = nums.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        int curr = nums[i];
        for (int j = i+1; j < n; j++){
            if(nums[j] > 2*curr){
                cnt++;
            }
        }
    }
    return cnt;
    // TC = O(n*n)
    // SC = O(n)
}

// Merge Sort - trick or count inversion {reverse here}
void merge(vector<int>& arr,int low,int mid ,int high,int& ans){
    vector<int> temp;

    int left = low;
    int right = mid+1;
    // individually count karna hoga : bulk counting possible nhi hain 
    // isliye merge se pahle mujhe count karna hoga har ek left ke liye right jab tak ki 2*nums[right];
    int j = mid+1;
    for(int i=low;i<=mid;i++){
        while (j<=high && arr[i]>2LL*arr[j])
        {
            j++;
        }
        ans+=(j-(mid+1));
    }
    // TC = O(n) becoz j++ hota ja ra hai
     
    // normal merge becoz its neeeded
    while (left<=mid && right<=high){ 
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{ // right is smaller ad all pairs
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left<=mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right<=high)
    {
        temp.push_back(arr[right++]);
    }
    
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>& arr,int low,int high,int& ans){
    if(low>=high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid,ans);
    mergeSort(arr,mid+1,high,ans);
    merge(arr,low,mid,high,ans);
}


// number of greater element
int reversePairsOptimal(vector<int>& nums){
    int size = nums.size();
    int ans = 0;
    mergeSort(nums,0,nums.size()-1,ans);
    return ans;
}


// printArray
void printArray(vector<int>& nums){
    cout << "[";
    for(auto num:nums) cout << num << " ";
    cout << "]\n";
}

int main(){
    vector<int> nums = {1,3,2,3,1};
    int rps = reversePairsOptimal(nums);
    cout << "nums = ";
    printArray(nums);
    cout << "Reverse Pairs count = " << rps <<endl ;
    return 0;
}



// 💣 MAIN PROBLEM (jaha tu confuse hua)
// 👉 Inversion me:

// Array sorted hai:

// Left = [5,6]
// Right = [1,2]

// 👉 5 > 1 → toh 5 > 2 bhi hoga
// 👉 isliye:

// (mid - left + 1)

// ✔️ bulk counting possible

// 👉 Reverse Pair me:
// Left = [5,6]
// Right = [2,3]

// Check:

// 5 > 2*2 = 4 ✔️
// 5 > 2*3 = 6 ❌

// 👉 SAME right array me mixed result 😵