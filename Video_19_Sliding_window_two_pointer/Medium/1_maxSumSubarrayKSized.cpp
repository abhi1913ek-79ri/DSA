#include <bits/stdc++.h>
using namespace std;
// Maxsum subarray constant size k
// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700

// Brute --
// generat all subarrays then find maxSum
int maxSubarraySum_brute(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    // code here
    for (int i = 0; i <= n - k; i++)
    {
        int curr = 0;
        for (int j = i; j < i + k; j++)
        {
            curr += arr[j];
        }
        maxSum = max(maxSum, curr);
    }
    return maxSum;
    // TC = O(n*k)
    // SC = O(1)
}

// use of two pointers - O*(n)
int maxSubarraySum_optimal(vector<int> &arr, int k){
    int n = arr.size();

    int sum = 0;
    for (int i = 0; i < k; i++) // O(k)
    {
        sum += arr[i];       
    }

    int maxSum = sum;

    for (int i = k; i < n; i++)// O(n-k)
    {
        sum -= arr[i-k];
        sum += arr[i];
        maxSum = max(maxSum,sum);
    }
    
    return maxSum;
    // TC = O(n) 
    // SC = O(1)
}


int main()
{
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;
    cout << "Max Sum  : " << maxSubarraySum_brute(arr,k)<<endl;
    cout << "Max Sum  : " << maxSubarraySum_optimal(arr,k)<<endl;


    return 0;
}