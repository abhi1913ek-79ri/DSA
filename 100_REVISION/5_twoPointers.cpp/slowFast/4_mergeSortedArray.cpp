#include <bits/stdc++.h>
using namespace std;
// Merge sorted array
void merge_brute(vector<int> &nums1, int n, vector<int> &nums2, int m){
    for(auto& num : nums2){
        nums1.push_back(num);
    }

    sort(nums1.begin(),nums2.end());

}

void merge_optimal(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // right to left traverse
    // so that now elemenmt ovewritten
    int i = m - 1; // explore
    int j = n- 1; // explore
    int k = m+n-1; // valid pos 
    while (i>=0 && j >= 0)
    {
        if(nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }else{
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    } 
}


int main()
{
    int t;
    cin >> t;
    vector<int> nums1(t);
    for(auto& num : nums1){
        cin >> num;
    }

    int m;
    cin >> m;

    int k;
    cin >> k;
    vector<int> nums2(k);
    for(auto& num : nums2){
        cin >> num;
    }

    int n;
    cin >> n;

    merge_optimal(nums1,m,nums2,n);
    bool flag = false;
    for(auto& num : nums1){
        if(flag) cout << " ";
        cout << num;
        flag = true;
    }
    
    return 0;
}