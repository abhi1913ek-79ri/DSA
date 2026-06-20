#include<bits/stdc++.h>
using namespace std;
// single Number - III
vector<int> singleNum1(vector<int>& nums){
    vector<int> ans;
    for(auto num1:nums){
        int cnt = 0;
        for(auto num2:nums){
            if(num1 == num2) cnt++;
        }
        if(cnt < 2) ans.push_back(num1);
    }
    return ans;
    // TC = O(n²)
    // SC = O(1)
}

// Better -- HashMap
vector<int> singleNum2(vector<int>& nums){
    vector<int> ans;

    unordered_map<int,int> mp;
    for(auto num:nums){
        mp[num]++;
    }

    for(auto num : nums){
        if(mp[num]<2) ans.push_back(num);
    }

    return ans;
    // TC = O(n) 
    // TC = O(n)
}

// bitManipualation -- to be continued
// BUCKET CONCEPT
// idea -- 
// 1. if XOR of two different number is given
// 2. we can find the both two numbers
// -- 1. it's guaranteed 1 bit is different
// -- 2. find the rightMost setbit
// -- 3. divde numbers into two bucket 
// --  --- bucket-1 = nth pos is set - put all those  numbers in that bucket that have setbit position at that place
// --  --- similarly for bucket-2
// --  --- then its guranteed that same number is in same bucket
// --  --- Now XOR all the elements with to get 1st unique number
// --  --- similarly for other

vector<int> singleNum3(vector<int>& nums){
    long xorAll = 0; // bhai sun  isko isliye kara hain kyunki xorall - 1 bhi ek jgah ho ra hai
    for(auto num : nums){
        xorAll ^= num;
    }

    int setBit = (xorAll & (xorAll-1))^xorAll; // not fast overflow error
    // setBit  = xorAll&(-xorAll) // -- will give same result
    int Bucket_1_XOR = 0;
    int Bucket_2_XOR = 0;

    for(auto num : nums){
        if(setBit&num){
            Bucket_1_XOR^=num;
        }else{
            Bucket_2_XOR^=num;
        }
    }

    return {Bucket_1_XOR,Bucket_2_XOR};
    // TC = O(n+n)
    // SC = O(1)
}

//PrintArray
void printArray(vector<int>& nums){
    cout << "[";
    for(auto num : nums) cout << num << " ";
    cout << "]\n";
}


int main(){
    vector<int> nums={1,2,1,2,3,5};
    vector<int> ans= singleNum3(nums);

    cout << "Array : ";
    printArray(nums);
    cout <<"Single numbers : ";
    printArray(ans);

    return 0;
}