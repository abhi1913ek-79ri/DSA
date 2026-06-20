#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Given an array of integers arr[] and an integer target.
// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise,
// we will return {-1, -1}.
// Note: You are not allowed to use the same element twice. 
// Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

string TwoSumVar1Brute(vector<int>& arr,int target){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]+arr[j]==target) return "Yes";
        }
    }
    return "No";
}
string TwoSumVar1Better(vector<int>& arr,int target){
    //Hashing
    int n=arr.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a=arr[i];
        int more=target-a;
        if(mpp.find(more)!=mpp.end()){//Used for check exitence
            return "Yes";
        }
        mpp[a]=i;
    }
    return "No";
}
string TwoSumVar1Optimal(vector<int>& arr,int target){
    // Two Pointer Approach
    int n=arr.size();
    int left=0;int right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target) return "Yes";
        else if(sum<target) left++;
        else right--;
    }
    return "No";
}
vector<int> TwoSumVar2Brute(vector<int>& arr,int target){
    int n=arr.size();
    vector<int> ans(2,-1);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]+arr[j]==target){
                ans[0]=i;
                ans[1]=j;
            }
        }
    }
    return ans;
}
vector<int> TwoSumVar2Better(vector<int>& arr,int target){  //Optimal is Also same
    //Hashing
    int n=arr.size();
    map<int,int> mpp;
    vector<int> ans(2,-1);
    for(int i=0;i<n;i++){
        int a=arr[i];
        int more=target-a;
        if(mpp.find(more)!=mpp.end()){//Used for check exitence
            ans[0]=mpp[more];
            ans[1]=i;
        }
        mpp[a]=i;
    }
    return ans;
}
void printArray(vector<int>& arr){for(auto num:arr)cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr={2,4,8,9};
    int target=9;
    cout<<"Array : ";
    printArray(arr);
    // Var 1
    string ans=TwoSumVar1Optimal(arr,target);
    cout<<"Two sum of target = "<<target<<" exist : "<<ans<<endl;
    // Var 2
    vector<int> ansvec=TwoSumVar2Better(arr,target);
    cout<<"TwoSum is Found at i = "<<ansvec[0]<<", j = "<<ansvec[1]<<" tagetSum = "<<target<<endl;
    
    return 0;
}