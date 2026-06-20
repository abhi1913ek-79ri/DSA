#include<bits/stdc++.h>
using namespace std;
// ALL elements negative as well as positive 
int longestSubarrayKBrute(vector<int>& arr, int k) {
    // code here
    int n=arr.size();
    int len=0;
    for(int i=0;i<n;i++){
        int s=0; 
        for(int j=i;j<n;j++){
            s+=arr[j];
            if(s == k){
                len=max(j-i+1,len);
            }
        }
    }
    return len;
}
//Optimal For all positive as well as negative 
// Using Hashing
int longestSubarraySumKOptimal(vector<int> &arr, int k)
{
    // code here
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

void printArray(vector<int>& arr){for(auto num:arr) cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr={10,5,5,9,-1,-1,2,-1,2,5,5,3,};int k=10;
    cout<<"Array : ";
    printArray(arr);
    // int maxLen = longestSubarrayKBrute(arr,k);
    int maxLen = longestSubarraySumKOptimal(arr,k);
    cout<<"Longest SA length : "<<maxLen<<endl;
    return 0;
}