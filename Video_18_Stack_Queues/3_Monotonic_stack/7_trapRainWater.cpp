#include<bits/stdc++.h>
using namespace std;
// Trap rain water
//Brute : summataion of min(leftMax,rightMax) - h[i]
int trap_brute(vector<int>& height){
    int n = height.size();
    // prefix max
    vector<int> prefixMax(n,0);
    prefixMax[0] = height[0];
    for(int i=1;i<n;i++){
        prefixMax[i] = max(prefixMax[i-1],height[i]);
    }

    // suffix max
    vector<int> suffixMax(n,0);
    suffixMax[n-1] = height[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i+1],height[i]);
    }

    int total = 0;
    for(int i=0;i<n;i++){
        if(height[i]<prefixMax[i] && height[i]<suffixMax[i]){
            total+=min(prefixMax[i],suffixMax[i]) - height[i];
        }
    }

    return total;
    // TC = O(3n)
    // SC = O(2n)
}

// Better Approach space O(n)
int trap_better(vector<int>& height){
    int n = height.size();

    // suffix max
    vector<int> suffixMax(n,0);
    suffixMax[n-1] = height[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i+1],height[i]);
    }

    int total = 0;
    int lmax = 0;
    for(int i=0;i<n;i++){
        lmax = max(lmax,height[i]);
        if(height[i]<lmax && height[i]<suffixMax[i]){
            total+=min(lmax,suffixMax[i]) - height[i];
        }
    }

    return total;
    // TC = O(2n)
    // SC = O(n)
}


// Optimal
// two pointer : idea we need only one : smaller one of lmax or rMax
// SC = O(1) - optimal
int trap_optimal(vector<int>& height){
    int n = height.size();
    int left = 0;
    int right = n-1;
    int lMax = 0;
    int rMax = 0;

    int total = 0;
    while (left<right){
        if(height[left] <= height[right]){
            if(height[left]<=lMax){
                total+=lMax-height[left];
            }else{
                lMax = height[left];
            }
            left++;
        }else{
           if(height[right]<=rMax){
                total+=rMax-height[right];
            }else{
                rMax = height[right];
            }
            right--;
        }
    }

    return total;
    // TC = O(n)
    // SC = O(1)
    
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; // 6
    cout << "Trapped Water : " << trap_brute(height) << endl;
    cout << "Trapped Water : " << trap_better(height) << endl;
    cout << "Trapped Water : " << trap_optimal(height) << endl;
    return 0;
}