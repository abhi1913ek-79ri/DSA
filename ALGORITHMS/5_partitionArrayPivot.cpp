#include<bits/stdc++.h>
using namespace std;
// just three pass solution will works here becioz relative order is mandetory
class Solution {
public:
    vector<int> pivotArray(vector<int>& arr, int pivot) {
        vector<int> left, equal, right;
        
        // Partition elements into three vectors
        for (int num : arr) {
            if (num < pivot) 
                left.push_back(num);
            else if (num == pivot) 
                equal.push_back(num);
            else 
                right.push_back(num);
        }

        // Combine all parts
        left.insert(left.end(), equal.begin(), equal.end());
        left.insert(left.end(), right.begin(), right.end());
        
        return left;


    }
};
int main(){
    
    return 0;
}