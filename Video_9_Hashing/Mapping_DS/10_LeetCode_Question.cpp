#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());  // Step 1: Sort the array
    long long l = 0, total = 0, max_freq = 0;

    for (long long r = 0; r < nums.size(); r++) {
        total += nums[r];  // Add the current element to the total sum
        
        // Check if the cost to make all elements nums[l:r] equal to nums[r] exceeds k
        while ((r - l + 1) * nums[r] - total > k) {
            total -= nums[l];  // Remove the leftmost element from total
            l++;  // Shrink the window
        }

        max_freq = max(max_freq, r - l + 1);  // Update max frequency
    }

    return max_freq;
}

int main() {
    vector<int> nums = {3, 9, 6, 2, 8};
    int k = 4;
    cout << "Maximum possible frequency: " << maxFrequency(nums, k) << endl;
    return 0;
}
