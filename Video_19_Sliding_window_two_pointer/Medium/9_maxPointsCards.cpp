#include<bits/stdc++.h>
using namespace std;
// Maximum Points You Can Obtain from Cards
// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
int maxScore_brute(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    
    int maxSum = -1;

    for(int i=0;i<=k;i++){
        int sum  = 0;
        // start sum 
        int startIdx = 0;
        for (int j = 1; j <= i; j++)
        {
            sum += cardPoints[startIdx++];
        }

        // End sum Points
        int endIdx = n-1;
        for (int j = 1; j <= k-i; j++)
        {
            sum += cardPoints[endIdx--];
        }

        maxSum = max(maxSum,sum);
    }
    return maxSum;
    // TC = O(k*k)
    // SC = O(1)
}

// Optimal
int maxScore_optimal(vector<int>& cardPoints, int k){
    int n = cardPoints.size();

    int total = 0;
    for (int i = 0; i < k; i++)
    {
        total += cardPoints[i];
    }
    
    int maxTotal = total;

    for (int i = 0; i < k; i++)
    {
        total -= cardPoints[k-i-1];
        total += cardPoints[n-i-1];
        maxTotal = max(maxTotal,total); 
    }
    return maxTotal;
    // TC = O(n)
    // SC = O(1)
}

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout << "Max Score : " << maxScore_brute(cardPoints,k) << "\n";
    cout << "Max Score : " << maxScore_optimal(cardPoints,k) << "\n";
    return 0;
}