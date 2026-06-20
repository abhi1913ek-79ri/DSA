#include<bits/stdc++.h>
using namespace std;
// Union of  Two  array 
// Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.
//The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in 
// the union should be in ascending order.
//  Here we have to understood That we have to 2 things : Common and Distinct;

vector<int> unionTwoSortedArrayBrute(vector<int>& A ,vector<int>& B){
    // Brute ::
    // using set : Uniqueness and sorted 
    int n=A.size();int m=B.size();
    set<int> st;
    vector<int> unionArray;
    for(auto num : A){
        st.insert(num);
    }
    for(auto num : B){
        st.insert(num);
    }
    for(auto num : st){
        unionArray.push_back(num);
    }
    return unionArray;
}

vector<int> unionTwoSortedArrayOptimal(vector<int>& A ,vector<int>& B){
    // Optimal :: 
    // Using Two pointer Approach i, j
    int n=A.size();int m=B.size();
    int i=0,j=0;
    vector<int> ans;
    while(i<n&&j<m){
        if(A[i]<=B[j]){
            if(ans.size()==0 || ans.back()!=A[i]){
                ans.push_back(A[i]);
            }i++;
        }
        else{
            if(ans.size()==0 || ans.back()!=B[j]){
                ans.push_back(B[j]);
            }j++;
        }
    }
    while(i<n){
        if(ans.size()==0 || ans.back()!=A[i]){
            ans.push_back(A[i]);
        }i++;
    }
    while(j<m){
        if(ans.size()==0 || ans.back()!=B[j]){
            ans.push_back(B[j]);
        }j++;
    }
    return ans;
}

vector<int> uinonTwoArrayMapping(vector<int>& a,vector<int>& b){
    // Using Mapping Concept
    map<int,int> freq;
    vector<int> unionArray;
    for(auto it : a) freq[it]++;
    for(auto it : b) freq[it]++;
    for(auto pair : freq) unionArray.push_back(pair.first);
    return unionArray;
}

void printArray(vector<int>& arr){
    for(auto num : arr) cout<<num<<" ";
    cout<<endl;
}


int main(){
    vector<int> a={1,2,2,2,3,4,5,6,7,8,9};
    vector<int> b={4,5,7,9,10};
    vector<int> unionArray;
    unionArray=uinonTwoArrayMapping(a,b);
    cout<<"A : ";printArray(a);
    cout<<"B : ";printArray(b);
    cout<<"A U B : ";printArray(unionArray);
    return 0;
}