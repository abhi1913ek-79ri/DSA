#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array, print all the elements which are leaders.
// A Leader is an element that is greater than all of the elements on its right side in the array.

//Example 1:
// Input:

// arr = [4, 7, 1, 0]
// Output
// :
// 7 1 0
vector<int> leadersInArrayBrute(vector<int>& arr){
    //Brute Force just Compare All with its right elements .
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader=false;break;
            }
        }

        if(leader){
            ans.push_back(arr[i]);
        }
    }

    return ans;
}
vector<int> leadersInArrayOptimal(vector<int>& arr){
    // DP Concept : preversing greatest for comparision OR : we can say last leader.
    int n = arr.size();
    vector<int> ans;
    int maxEel = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        maxEel = max(maxEel, arr[i]);
        if (arr[i] < maxEel)
        {
            continue;
        }
        ans.push_back(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void printArray(vector<int> arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr={4, 7, 1, 0};
    cout<<"Array : ";printArray(arr);
    vector<int> ans=leadersInArrayOptimal(arr);
    cout<<"Leaders : ";printArray(ans);
    return 0;
}