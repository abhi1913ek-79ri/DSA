#include<bits/stdc++.h>
using namespace std;
// Maximum Distance Between a Pair of Values
// Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
// Output: 2
int maxDistance_brute(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    int maxDistance = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = i; j < n2; j++)
        {
            if(nums1[i]<=nums2[j]){
                maxDistance = max(maxDistance,j-i);
            }
        }
        
    }
    return maxDistance;
    // TC = O(n^2)
    // SC = O(1)
}

// Optimisation - bruteforce optimisation
// Given sorted -- take benefit of that
int maxDistance_better(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    int maxDistance = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = i; j < n2; j++)
        {
            if(nums1[i]<=nums2[j]){
                maxDistance = max(maxDistance,j-i);
            }else{
                break;
            }
        }
        
    }
    return maxDistance;
    // TC = O(n^2)
    // SC = O(1)
}

// Full benefit of sorting
// Optimisation - find righmost valid
int maxDistance_optimal(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    int maxDistance = 0;
    for (int i = 0; i < n1; i++)
    {
        int target = nums1[i];
        // Binary search
        int l = i;
        int h = n2-1;
        int maxIdx = 0;
        while (l<=h)
        {
            int mid = l + (h - l) / 2;
            if(nums2[mid]>=nums1[i]){
                maxIdx = max(maxIdx,mid);
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        maxDistance = max(maxDistance,maxIdx-i);
    }
    return maxDistance;
    // TC = O(nlogn)
    // SC = O(1)
}


// optimised 2  : two pointers approach
int maxDistance_optimal2(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    int i = 0;
    int j = 0;

    int maxDis = 0;

    while (i<n1&&j<n2)
    {
        if(i<=j&&nums1[i]<=nums2[j]){
            maxDis = max(maxDis,j-i);
            j++;
        }else if(i>j){
            j++;
        }else{
            i++;
        }
    }
    return maxDis;
    // TC = O(n)
    // SC = O(1)
}



int main(){
    vector<int> nums1 = {55,30,5,4,2}, nums2 = {100,20,10,10,5};
    cout << "Max Distance : " << maxDistance_brute(nums1,nums2)<<endl;
    cout << "Max Distance : " << maxDistance_better(nums1,nums2)<<endl;
    cout << "Max Distance : " << maxDistance_optimal(nums1,nums2)<<endl;
    cout << "Max Distance : " << maxDistance_optimal2(nums1,nums2)<<endl;
    return 0;
}