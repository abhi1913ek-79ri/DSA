#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array, find the second smallest and second largest element
//  in the array. Print ‘-1’ in the event that either of them doesn’t exist.
// Brute Force : Sort , traverse reverse arr till get another different largest.
// Better : 1st pass for finding largest and 2nd pass for get secondlargest by compairing it with largest.
// Optimal Approach
int SecondLargestBrute(vector<int>& arr){
    int secondLargest=INT_MIN;
    sort(arr.begin(),arr.end());
    int largest=arr[arr.size()-1];
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]!=largest){
            secondLargest=arr[i];
            break;
        }
    }
    return secondLargest;
}

int SecondLargestBetter(vector<int>& arr){
    int secondLargest=INT_MIN;
    int largest=INT_MIN;
    // 1st pass
    for(auto num:arr){
        largest = max(largest,num);
    }
    for(auto num : arr){
        if(num>secondLargest && num!=largest){
            secondLargest=num;
        }
    }
    return secondLargest;
}

int SecondLargestOptimal(vector<int>& arr){
    int largest=INT_MIN;
    int secondLargest=INT_MIN;
    for(auto num:arr){
        if(num>largest){
            secondLargest=largest;
            largest=num;
        }
        else if(num<largest&& num> secondLargest){
            secondLargest=num;
        }
    }
    return secondLargest;
}


void printArray(vector<int>& arr){
    int n=arr.size();
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr={1,2,54,5,5,21,2,2};
    cout<<"Array : ";
    printArray(arr); 
    cout<<"SecondLargestBrute : "<<SecondLargestBrute(arr)<<"\n";
    cout<<"SecondLargestBetter : "<<SecondLargestBetter(arr)<<"\n";
    cout<<"SecondLargestOptimal : "<<SecondLargestOptimal(arr)<<"\n";


    return 0;
}