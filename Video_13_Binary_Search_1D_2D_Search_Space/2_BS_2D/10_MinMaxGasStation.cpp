#include<bits/stdc++.h>
using namespace std;
//Minimise Maximum Distance between Gas Stations


// 169

// 5
// Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
// Find the minimum value of ‘dist’.

// Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, it is okay to return 0.654216. Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.

// Examples
// Example 1:
// Input Format:
//  N = 5, arr[] = {1,2,3,4,5}, k = 4
// Result:
//  0.5
// Explanation:


// Note : long doubloe return type,
// Hard Question

// 1st Approach Brute Force

long double minimiseMaxDistanceBrute(vector<int>& arr,int k){
    int n = arr.size();
    vector<int> howMany(n-1,0);
    for(int gasStations = 1;gasStations<=k;gasStations++){
        long double maxSection=-1;
        int maxInd = -1;
        for(int i =0;i<n-1;i++){
            long double diff = arr[i+1]-arr[i];
            long double sectionLength=diff/(long double)(howMany[i]+1);
            if(sectionLength>maxSection){
                maxSection = sectionLength;
                maxInd=i;
            }

        }
        howMany[maxInd]++;
    }

    long double maxAns =-1;
    for(int i=0;i<n-1;i++){
        long double diff =arr[i+1]-arr[i];
        long double sectionLength=diff/(long double)(howMany[i]+1);
        maxAns=max(maxAns,sectionLength);
    }
    return maxAns;
}

long double minimiseMaxDistancePQ(vector<int>& arr,int k){
    int n=arr.size();
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gasStation = 1;gasStation<=k;gasStation++){
        auto tp= pq.top();pq.pop();
        int secInd=tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd+1]-arr[secInd];
        long double newSecLen = iniDiff/(long double)(howMany[secInd]+1);
        pq.push({newSecLen,secInd});
    }
    return pq.top().first;
}

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    cout << fixed << setprecision(6) << minimiseMaxDistancePQ(arr, k) << endl;
    return 0;
}