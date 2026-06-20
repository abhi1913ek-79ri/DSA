#include<bits/stdc++.h>
using namespace std;
//Median of Two Sorted Arrays of different sizes
// Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.
// Examples
// Example 1:
// Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
// Result: 3.5
// Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.
vector<double> merge(vector<int>& arr1,vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<double> result(n+m);
    int i=0,j=0,k=0;
    while (i<n&&j<m){
        if(arr1[i]<arr2[j]) result[k++]=arr1[i++];
        else result[k++]=arr2[j++];
    }
    while (i<n)
    {
        result[k++]=arr1[i++];
    }
    while (j<m)
    {
        result[k++]=arr2[j++];
    }
    return result;
}
double findMedianSortedArraysBrute(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int mergeN=n+m;
    double median = 0;
    vector<double> mergedArr1Arr2 = merge(arr1,arr2);
    if(mergeN%2==0){
        median = (mergedArr1Arr2[(mergeN-1)/2]+mergedArr1Arr2[(mergeN)/2])/2.0;
    }else{
        median = mergedArr1Arr2[(mergeN)/2];
    }
    return median;
    //Tc = O(n+M)
    //Sc = O(n+m)
}
double findMedianSortedArraysBetter(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
    // TC = O(n+m)
    // SC = O(1)
}

double medianOptimal(vector<int>& a, vector<int>& b){
    int n1=a.size();
    int n2=b.size();
    if(n1>n2) return medianOptimal(b,a);
    int n= n1+n2;
    int low=0,high=n1;
    int left=(n+1)/2;
    while (low<=high){
        int mid1=(low+high)>>1;
        int mid2= left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n1) r1=a[mid1];
        if(mid2<n2) r2=b[mid2];
        if(mid1-1>=0) l1=a[mid1-1];
        if(mid2-1>=0) l2=b[mid2-1];
        if(l1<=r2&&l2<r1){
            if(n%2==1) return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2))/2.0);
        }
        else if(l1>r2) high=mid1-1;
        else low = mid1+1;
    }
    return 0;
    // TC = O(log(min(n,m)))
    // SC = O(1)
}
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 3, 5};

    cout << "Array 1: ";
    printArray(arr1);

    cout << "Array 2: ";
    printArray(arr2);

    double median = findMedianSortedArraysBetter(arr1, arr2);
    cout << "Median: " << median << endl;

    return 0;
}