#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of
// pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all
// the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to
// a student is minimum. If the allocation of books is not possible. return -1

int NoOfStudents(vector<int>& arr,int maxPages){
    int students=1;
    int allocatedPages=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+allocatedPages<=maxPages){
            allocatedPages+=arr[i];
        }else{
            students++;
            allocatedPages=arr[i];
        }
    }
    return students;
}
int bookAllocationBrute(vector<int>& arr,int m){
    int low = *max_element(arr.begin(),arr.end());
    int high= accumulate(arr.begin(),arr.end(),0);
    for(int i=low;i<=high;i++){
        int numberOfSTudents=NoOfStudents(arr,i);
        if(numberOfSTudents==m) return i;
    }
    return low;
}
int bookAllocationOptimal(vector<int>& arr,int m){
    if(m>arr.size()) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high= accumulate(arr.begin(),arr.end(),0);
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        int numberOfSTudents=NoOfStudents(arr,mid);
        if(numberOfSTudents<=m){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}


int main(){
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = bookAllocationOptimal(arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}