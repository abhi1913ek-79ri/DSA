#include<bits/stdc++.h>
using namespace std;
//Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.
// Examples:
// Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5
// Output: 6
// Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
int kthElementBrute(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;
    vector<int> mergedArr(n);
    int i = 0;
    int j = 0;
    int idx = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            mergedArr[idx++] = a[i++];
        }
        else
        {
            mergedArr[idx++] = b[j++];
        }
    }
    while (i < n1)
    {
        mergedArr[idx++] = a[i++];
    }
    while (j < n2)
    {
        mergedArr[idx++] = b[j++];
    }

    return mergedArr[k - 1];
}
int kthElementOptimal(vector<int> &a, vector<int> &b, int k)
{
    int n1=a.size();
    int n2=b.size();
    if(n1>n2) kthElementOptimal(b,a,k);
    int low = max(0,k-n2);
    int high = min(k,n1);
    int left = k;
    int n=n1+n2;
    while (low<=high){
        
    }
    



}


int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout << "The " << k << "th element is: " << kthElement(a, b, k) << endl;
    return 0;
}