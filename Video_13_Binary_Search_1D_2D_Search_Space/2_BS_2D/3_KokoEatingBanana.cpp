#include<bits/stdc++.h>
using namespace std;
//Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas.
//  An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

// Examples
// Example 1:
// Input Format:
//  N = 4, a[] = {7, 15, 6, 3}, h = 8
// // Result:
//  5

// Function to find the maximum number in the array
int findMax(vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        maxVal = max(num, maxVal);
    }
    return maxVal;
}

// Function to calculate total hours required to eat all bananas at 'hourly' rate
int CalrequiredTime(vector<int>& arr, int hourly) {
    int totalTime = 0;
    for (int num : arr) {
        totalTime += ceil((double)num/(double)hourly);  // Equivalent to ceil(num / hourly)
    }
    return totalTime;
}


int kokoLinear(vector<int>& arr,int h){
    int maxii=findMax(arr);
    for(int i=1;i<=maxii;i++){
        if(CalrequiredTime(arr,i)<=h) return i;
    }
    return maxii;
    // TC = O(n*max(arr))
}
// Binary Search to find the minimum eating speed
int kokoBinarySearch(vector<int>& arr, int h) {
    int low=1;int ans=-1;
    int high =findMax(arr);
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        int requiredTime =CalrequiredTime(arr,mid);
        if(requiredTime<=h){
            ans =mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}


// Driver function
int main() {
    vector<int> a = {7, 15, 6, 3,10};
    int h = 8;
    cout << "Minimum bananas per hour: " << kokoBinarySearch(a, h) << endl;
    return 0;
}
