#include<bits/stdc++.h>
using namespace std;
// Number of greater Element right to the number


// Brute Force
int countInversion(vector<int>& nums){
    int n = nums.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        int curr = nums[i];
        for (int j = i+1; j < n; j++){
            if(nums[j] < curr){
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

    while (left<=mid && right<=high){ 
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{ // right is smaller ad all pairs
            temp.push_back(arr[right]);
            ans+= mid-left+1;
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
int inversionCount(vector<int>& nums){
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
    vector<int> nums = {1,2,1};
    int inversion = countInversion(nums);
    cout << "nums = ";
    printArray(nums);
    cout << "Inversion count = " << inversion <<endl ;
    return 0;
}