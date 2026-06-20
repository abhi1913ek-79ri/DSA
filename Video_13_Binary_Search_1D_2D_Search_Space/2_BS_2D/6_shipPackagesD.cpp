#include<bits/stdc++.h>
using namespace std;
// Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages
// from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are 
// loaded on the conveyor belts every day in the same order as they appear in the array.
//  The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.


bool isPossible(vector<int>& arr, int cap, int d) {
    int sum = 0, countDay = 1; // Start from 1 because at least 1 day is needed
    for (auto weight : arr) {
        sum += weight;
        if (sum > cap) { // (<=)not count for last accumulated weight
            countDay++;
            sum = weight; // Start new day's sum
        }
    }
    return countDay <= d;
}

int leastWeightCapacityBrute(vector<int>& arr, int d) {
    int low = *max_element(arr.begin(), arr.end());  // Fix: Start from max weight
    int high = accumulate(arr.begin(), arr.end(), 0); // Sum of all weights
    for(int i=low;i<=high;i++){
        if(isPossible(arr,i,d)) return i;
    }
    return high;
}
int leastWeightCapacityOptimal(vector<int>& arr, int d) {
    int low = *max_element(arr.begin(), arr.end());  // Fix: Start from max weight
    int high = accumulate(arr.begin(), arr.end(), 0); // Sum of all weights
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, mid, d)) {
            ans = mid;
            high = mid - 1; // Try for smaller capacity
        } else {
            low = mid + 1; // Increase capacity
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int d = 5;
    cout << "Minimum ship capacity Brute : " << leastWeightCapacityBrute(arr, d) << endl;
    cout << "Minimum ship capacity Optimal : " << leastWeightCapacityOptimal(arr, d) << endl;
    return 0;
}
