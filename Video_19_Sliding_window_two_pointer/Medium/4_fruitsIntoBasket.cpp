#include<bits/stdc++.h>
using namespace std;
// Fruits into the basket : longest subarray with atomost two types of fruits
// Input: fruits = [1,2,1]
// Output: 3

// Brute Force : generate all subarray and check for at most 2 distinct element
int totalFruit_brute(vector<int>& fruits){
    int n = fruits.size();

    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<int,int> types;
        for (int j = i;  j< n; j++)
        {
            types[fruits[j]]++;
            if(types.size()>2) break;
            else maxLen = max(maxLen,j-i+1);
        }
    }
    
    return maxLen;
    // TC = O(n^2)
    // SC = O(1) becoz atmost 3 elements
}


// Optimal : sliding Window + map
int totalFruit(vector<int>& fruits) {
    int n = fruits.size();

    int maxLen = 0;

    int l = 0;
    unordered_map<int,int> types;
    for (int r = 0; r < n; r++)
    {
        types[fruits[r]]++;
        while (types.size()>2&&l<=r)
        {
            types[fruits[l]]--;
            if(types[fruits[l]]==0) types.erase(fruits[l]);
            l++;
        }
        maxLen = max(maxLen,r-l+1); 
    }

    return maxLen;
    // TC = O(n+n)
    // SC = O(1) becoz atmost 3 elements
}

int totalFruit2(vector<int>& fruits) {
    int n = fruits.size();

    int maxLen = 0;

    int l = 0;
    unordered_map<int,int> types;
    for (int r = 0; r < n; r++)
    {
        types[fruits[r]]++;
        if(types.size()>2)
        {
            types[fruits[l]]--;
            if(types[fruits[l]]==0) types.erase(fruits[l]);
            l++;
        }
        maxLen = max(maxLen,r-l+1); 
    }

    return maxLen;
    // TC = O(n)
    // SC = O(1)
}


int main(){
    vector<int> fruits = {1,2,3,2,2};
    cout << "Total Fruits : " << totalFruit_brute(fruits) << endl;
    cout << "Total Fruits : " << totalFruit(fruits) << endl;

    return 0;
}


