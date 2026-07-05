#include<bits/stdc++.h>
using namespace std;
// Sort  an array


// for sort function
// Hyphthesis
// sort(arr,n-1) correctly sort the array with size n-1

// induction  
// sort(arr,n) = sort(arr,n-1) ans insert(nth element) at it's correct position

// Base condition 
// n == 1 return arr


// for insert function
// Hypothesis 
// insert(arr, i, j--,ele) = correctly insert at it's correct position

// induction
// arr.push_back(arr[j]) -- aatey samay

// base condition
// arr[j] < ele  || n == 0 { arr.push_back(ele)}

// insert
void insert(vector<int>& arr,int ele){
    if(arr.size() == 0 || ele >= arr[arr.size()-1]) {arr.push_back(ele);return;}

    int temp = arr[arr.size()-1];
    arr.pop_back();
    insert(arr,ele);
    arr.push_back(temp);
}

void sortHelper(vector<int>& arr){
    // base condition
    if( arr.size()<=1) return;
    int temp = arr[arr.size()-1];
    arr.pop_back();
    sortHelper(arr);
    insert(arr,temp);
}


void sortRecursive(vector<int>& arr){
    sortHelper(arr);
}

// Time Complexity : O(n²)
// Space Complexity : O(n)



int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto& num : nums)
        {
            cin >> num;
        }

        sortRecursive(nums);
        bool flag = false;
        for(auto& num : nums){
            if(flag) cout << " ";
            cout << num;
            flag = true;
        }
        cout << endl;
    }
    
    return 0;
}