#include <bits/stdc++.h>
using namespace std;
// Power Set | Bit manipulation
vector<vector<int>> subsets(vector<int> &nums){
    int n = nums.size();
    int subsets = 1<<n;
    vector<vector<int>> ans={};
    for(int num = 0 ;num<=subsets-1;num++){
        vector<int> temp;
        for (int i = 0; i <= n-1; i++)
        {
            if(num&(1<<i)){
                temp.push_back(nums[i]);
            }
        }
        ans.push_back(temp); 
    }

    return ans;
}

void printArray2D(vector<vector<int>>& arr){
    cout << "[";
    for(int i = 0 ; i< arr.size();i++){
        cout << "[";
        for(int j=0; j<arr[i].size();j++){
            cout << arr[i][j] << ",";
        }
        cout << "],";
    }
    cout << "]\n";
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> powerSet = subsets(arr);
    cout << "Array : ";
    printArray2D(powerSet);


    return 0;
}