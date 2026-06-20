#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum element in the array
int max_array(vector<int>& nums) {
    int maxVal = INT_MIN;
    for (auto num : nums) {
        if (num > maxVal) maxVal = num;
    }
    return maxVal;
}

int main() {
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    vector<int> hashh(max_array(arr) + 1, 0);

    // Computation of frequency
    for (int i = 0; i < arr.size(); i++) hashh[arr[i]]++;
    int maxFreqElement = -1, minFreqElement = -1;
    int maxFreq = INT_MIN, minFreq = INT_MAX;

    // Loop over hashh instead of arr
    for (int i = 0; i < hashh.size(); i++) {
        if (hashh[i] > 0) { // Only consider elements that appeared in arr
            if (hashh[i] > maxFreq) {
                maxFreq = hashh[i];
                maxFreqElement = i;
            }
            if (hashh[i] < minFreq) {
                minFreq = hashh[i];
                minFreqElement = i;
            }
        }
    }

    // Output the highest and lowest frequency elements
    cout << "The frequency of " << maxFreqElement << " is " << maxFreq << ", i.e. the highest, ";
    cout << "and the frequency of " << minFreqElement << " is " << minFreq << ", i.e. the lowest." << endl;

    return 0;
}
