#include<bits/stdc++.h>
using namespace std;
// Number of Smaller Element right to the number


// Brute Force
vector<int> nNSES_brute(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        int curr = nums[i];
        for (int j = i+1; j < n; j++){
            if(nums[j]<curr){
                ans[i]++;
            }
        }
    }
    return ans;
    // TC = O(n*n)
    // SC = O(n)
}

// Merge Sort - trick or count inversion {reverse here}
void merge(vector<pair<int,int>>& arr,int low,int mid ,int high,vector<int>& ans){
    vector<pair<int,int>> temp;

    int left = low;
    int right = mid+1;
    int count = 0;
    while (left<=mid && right<=high){ // right is greater
        if(arr[left].first <= arr[right].first){
            ans[arr[left].second]+=count;
            temp.push_back(arr[left]);
            left++;
        }else{ // right is smaller
            temp.push_back(arr[right]);
            count++;
            right++;
        }
    }

    while (left<=mid)
    {
        ans[arr[left].second] += count;
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

void mergeSort(vector<pair<int,int>>& arr,int low,int high,vector<int>& ans){
    if(low>=high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid,ans);
    mergeSort(arr,mid+1,high,ans);
    merge(arr,low,mid,high,ans);
}


// number of greater element
vector<int> numberOfSmallerElement(vector<int>& nums){
    int size = nums.size();
    // auxilary array : stores value and their index
    vector<pair<int,int>> aux;
    
    for (int i = 0; i < size; i++)
    {
        aux.push_back({nums[i],i});
    }

    vector<int> ans(size,0);
    
    mergeSort(aux,0,nums.size()-1,ans);
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
    vector<int> nNSEs = numberOfSmallerElement(nums);
    cout << "nums = ";
    printArray(nums);
    cout << "nNGEs = ";
    printArray(nNSEs);
    return 0;
}