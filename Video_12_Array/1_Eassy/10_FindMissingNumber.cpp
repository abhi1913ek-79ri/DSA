#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N.
// Find the number(between 1 to N), that is not present in the given array.

int findMissingNumberBrute(vector<int>& arr, int N){
    int n=arr.size();
    for(int i=1;i<N;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(i==arr[j]) flag=1;
        }
        if(flag==0) return i;
    }

    // TC = O(N*N)

}

int findMissingNumberBetter(vector<int>& arr, int N){
    // Using Hashing
    int n=arr.size();
    vector<int> hash_map(N+1,0);
    // Pre-computation
    for(auto num : arr){
        hash_map[num]++;
    }
    //Missing
    for(int i=1;i<=N;i++){
        if(hash_map[i]==0) return i;
    }
    return -1;

    // TC = O(2N)
    // SC = O(N)

}
int findMissingNumberOptimalSum(vector<int>& arr, int N){
    int sumN=(N*(N+1))/2;int sumn=0;
    for(auto num : arr) sumn+=num;
    return sumN-sumn;

    // TC = O(N)
    // SC = O(1)
    // But sumN varibale me be sum bigger to bceome long long etc...


}
int findMissingNumberOptimalXor(vector<int>& arr, int N){
    int n=arr.size();
    int xor1=0;
    int xor2=0;
    for(int i=0;i<N-1;i++){
        xor2^=arr[i];
        xor1^=(i+1);
    }
    xor1=xor1^N;
    return (xor1^xor2);

    // TC = O(N)  // it is Optimised as we are using two loops to calculate xor1 and xor2 seprately.
    // SC = O(1)
    // But XOR cant be exceed till it max means max number in exor oprtaion of multiple numbers 
}
void printArray(vector<int>& arr){
    for(auto num : arr) cout<<num<<" ";
    cout<<endl;
}



int main(){
    vector<int> arr={1,2,3,4,5,6};
    int N=7;
    int size = arr.size(); // inters are from 1 to size + 1
    cout<<"Array : ";
    printArray(arr);
    int missingNumber=findMissingNumberOptimalXor(arr,N);
    cout<< "Missing Number : "<<missingNumber<<endl;
    return 0;
}