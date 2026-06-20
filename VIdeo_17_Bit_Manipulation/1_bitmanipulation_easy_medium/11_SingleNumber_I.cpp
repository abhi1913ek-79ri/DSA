#include<bits/stdc++.h>
using namespace std;
// single Number - I
// Find the number that appears once, and the other numbers twice
int singleNumber(vector<int>& nums) {
    // count occurence of every number
    for(auto num : nums){
        int cnt =0;
        for(auto other : nums){
            if(other==num) cnt++;
        }
        if(cnt <2) return num;
    }
    // TC = O(n²) -- TLE
    // SC = O(1)
}



// Use Hash Map using vector
int maxArray(vector<int>& nums){
    int maxii = INT_MIN;
    for(auto num : nums){
        maxii = max(num,maxii);
    }
    return maxii;
}

int singleNumber1(vector<int>& nums){
    vector<int> freq(maxArray(nums)+1,0);
    // calculate occurnces 
    for(auto num :nums){
        freq[num]++;
    }
    // find occurneces
    for(auto num : nums){
        if(freq[num]<2) return num;
    }
    // TC = O(n+n)
    // SC = O(n)
    // Not works for negative max number 
}


// hash map using map container
int singleNumber2(vector<int>& nums){
    map<int,int> freq;
    for(auto num : nums){
        freq[num]++; // logn
    }

    for(const auto pair:freq){
        if(pair.second <2) return pair.first; // O(1)
    }

    return -1;
    // TC = O(n.logn+logn)
    // SC = O(n)
}

// using ordered map
int singleNumber3(vector<int>& nums){
    unordered_map<int,int> mp;
    for(auto num : nums){
        mp[num]++;
    }
    
    for(const auto pair:mp){
        if(pair.second<2) return pair.first;
    }
    return -1;

    // TC = O(n+1) -- worst case O(n+n) if max hash collisons
    // SC = O(n)
}

// Using Bit manipulation 
// idea n^n = 0
int singleNumber4(vector<int>& nums){
    int XorRes = 0;
    for(auto num : nums){
        XorRes^=num;
    }
    return XorRes;
    // TC = O(n)
    // SC = O(1)
}

void printArray(vector<int> &nums){
    for(auto num : nums) cout << num << " ";
}

int main(){
    vector<int> nums = {4,1,2,1,2};
    cout << "nums = " << "[";
    printArray(nums);
    cout<<"]\n";
    cout << "Single Number : " << singleNumber4(nums);
    return 0;
}