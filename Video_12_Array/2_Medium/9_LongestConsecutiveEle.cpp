#include<bits/stdc++.h>
using namespace std;
//Problem Statement: You are given an array of ‘N’ integers.
//  You need to find the length of the longest sequence which contains the consecutive elements.
// Explanation:
//  The longest consecutive subsequence is 1, 2, 3, and 4.

// Input:
//  [3, 8, 5, 7, 6]

// Output:
//  4

// Explanation:
//  The longest consecutive subsequence is 5, 6, 7, and 8.

bool ls(vector<int> &arr,int target){
    for(auto num : arr){
        if(num==target) return true;
    }

    return false;
}
int longestConsecutiveSeqBrute(vector<int>& arr){
    //order not matter
    int longest=1;
    int n= arr.size();
    for(int i=0;i<n;i++){
        int x=arr[i];
        int cnt=1;
        while(ls(arr,x+1)==true){
            x=x+1;
            cnt+=1;
        }
        longest=max(longest,cnt);
    }
    return longest;
}
int longestConsecutiveSeqBetter(vector<int>& arr){
    // array distortion
    int n=arr.size();
    sort(arr.begin(),arr.end()); //nlog(n)
    int longest=1;
    int lastSmall=INT_MIN;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]-1==lastSmall){
            count+=1;
            lastSmall=arr[i];
        }else if(arr[i]==lastSmall){
            //do nothing
        }else if(arr[i]!=lastSmall){
            count=1;
            lastSmall=arr[i];
        }

        longest= max(longest,count);
    }
    return longest;
}
int longestConsecutiveSeqOptimal(vector<int>& arr){ // under some contraint just use set data structure
    int n=arr.size();
    if(n==0) return 0;
    int longest=1;
    unordered_set<int> st;
    for(auto num : arr){
        st.insert(num);// O(N)- unordered set 
    }

    for(auto it : st){
        if(st.find(it-1)==st.end()){// it-1 not in set iterator end tak pahunch gaya
            int cnt = 1;
            int x= it;
            while(st.find(x+1)!=st.end()){// present in set
                x+=1;
                cnt+=1;
            }

            longest=max(longest,cnt);
        }
    }

    return longest;
    // TC = N + 2N = O(3N)
    // SC = O(N)

}

void printArray(vector<int> arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}

int main(){\
    vector<int> arr={3, 8, 5, 7, 6};
    int ans=longestConsecutiveSeqOptimal(arr);
    cout<<"Array : ";printArray(arr);
    cout<<"Longest consecutive seq. length : "<<ans<<endl;
    return 0;
}