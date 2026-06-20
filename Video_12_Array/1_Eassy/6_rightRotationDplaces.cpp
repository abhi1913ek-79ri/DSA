#include<bits/stdc++.h>
using namespace std;
// Left Rotation By one place .

void rightRotationDplaceBrute(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;  // Handle cases where d > n
    
    vector<int> temp;
    
    // Step 1: Store last 'd' elements in temp
    for (int i = n - d; i < n; i++) {
        temp.emplace_back(arr[i]); // O(d)
    }

    // Step 2: Shift remaining elements to the right
    for (int i = n - 1; i >= d; i--) {
        arr[i] = arr[i - d]; // O(n-d)
    }

    // Step 3: Copy temp back to the beginning
    for (int i = 0; i < d; i++) {
        arr[i] = temp[i]; // O(d)
    }
}


void rightRotationDplaceOptimal(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // Handle cases where d > n

    reverse(arr.end() - d, arr.end()); // Reverse last 'd' elements
    reverse(arr.begin(), arr.end() - d); // Reverse first 'n-d' elements
    reverse(arr.begin(), arr.end()); // Reverse entire array
}
void printArray(vector<int>& arr){
    int n=arr.size();
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    int d=4;
    cout<<"Original Array : ";
    printArray(arr);
    rightRotationDplaceOptimal(arr,d);
    cout<<"Right Rotated "<<d<<" places Array : ";
    printArray(arr);
    return 0;
}