#include<bits/stdc++.h>
using namespace std;

// Reverse array - loop
void reverseArray(vector<int> & arr){
    int n = arr.size();
    int left = 0;
    int right = n-1;
    while (left<right)
    {
        swap(arr[left++],arr[right--]);
    }

    // TC  = O(n/2)
    // SC = O(1)
}

// using recursion swaps - two pointers
void reverseArray2(vector<int>& arr , int l , int r){
    if(l>=r) return;
    swap(arr[l],arr[r]);
    reverseArray2(arr,++l,--r);
    // TC  = (n/2)
    // SC = O(n/2) -- rescursion stack space is considered
}

// Using - single pointer
void reverseArray3(vector<int>& arr,int i){
    int n = arr.size();

    if(i >= n/2) return;

    swap(arr[i],arr[n-i-1]);

    reverseArray3(arr,i+1);
    // TC = O(n/2)
    // SC = O(n/2)
}

// Reverse array - recursion  using backtrack recontrsuct not by swaping --- memorised things using backtrack ans stack space 
void reverseArray1(vector<int> & arr,int i){
    int n = arr.size();
    if(i>=arr.size()) return;
    int curr  = arr[i];
    reverseArray1(arr,i+1);
    arr[n-i-1] = curr;
    // TC = O(n)
    // SC = O(n)
}


// Reverse array - recursion  using backtrack - n/2
void reverseArray4(vector<int> & arr,int i){
    int n = arr.size();
    if(i>=n/2) return;
    int curr  = arr[i];
    reverseArray4(arr,i+1);
    swap(arr[i],arr[n-i-1]);
    // TC = O(n/2)
    // SC = O(n/2)
}




void printArray(vector<int>& arr){
    for(auto ele : arr) cout << ele << " ";
    cout << "\n";
}

int main(){
    vector<int> arr = {0,1,2,3,4,5,6};
    cout << "Original arr = ";
    printArray(arr);
    reverseArray4(arr,0);
    cout << "Mutated arr = ";
    printArray(arr);


    return 0;
}