#include<bits/stdc++.h>
using namespace std;
// MaximumSubarray
// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.

pair<pair<int,int>,int> maximumSubArrayBrute(vector<int>& arr){
    int n=arr.size();int maxSum=INT_MIN;
    pair<pair<int,int>,int> ans;//Ans
    int start=-1;
    int end=-1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //We get start = i and End = j of SubArray 
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(maxSum<sum){
               maxSum=sum;
               start=i;end=j;
            }
        }
    }
    //Ans
    ans.first.first=start;ans.first.second=end;
    ans.second=maxSum;
    return ans;
}
pair<pair<int,int>,int> maximumSubArrayBetter(vector<int>& arr){
    int n=arr.size();int maxSum=INT_MIN;
    pair<pair<int,int>,int> ans;//Ans
    int start=-1;
    int end=-1;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>maxSum){
                maxSum=sum;
                end=j;start=i;//yahi pe dono ko change kiya jahan pe maxsumUodate hua hain
            }
        }
    }
    //Ans
    ans.first.first=start;ans.first.second=end;
    ans.second=maxSum;
    return ans;
}

pair<pair<int,int>,int> maximumSubArrayOptimalKadanesAlgo(vector<int>& arr){
    int n=arr.size();int maxSum=INT_MIN;
    pair<pair<int,int>,int> ans;//Ans
    int start=-1;
    int end=-1;int sum=0;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=arr[i];
        if(maxSum<sum){
            //Update ans
            maxSum=sum;
            end=i;
        }
        if(sum<0) sum=0;
    }
    if(maxSum<0){
        start=end=0;maxSum=0;
    }
    // if [] empty sub array is allowed => start=end =k and maxSum=0;
    ans.first.first=start;ans.first.second=end;
    ans.second=maxSum;
    return ans;
}

void printArray(vector<int>& arr){
    for(auto num:arr) cout<<num<<" ";
    cout<<endl;
}

void printSubArray(vector<int>& arr,int start,int end){
    if(start==end) cout<<"[]";
    else{
        for(int i=start;i<=end;i++) cout<<arr[i]<<" ";
    }
}


int main(){
    vector<int> arr={-1,-5};
    pair<pair<int,int>,int> ans=maximumSubArrayOptimalKadanesAlgo(arr);
    cout<<"Array : ";printArray(arr);
    cout<<"Sub Aarray : ";printSubArray(arr,ans.first.first,ans.first.second);
    cout<< " and Max sum : "<<ans.second<<endl;
    return 0;
}