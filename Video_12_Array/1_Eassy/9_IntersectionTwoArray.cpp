#include<bits/stdc++.h>
using namespace std;
//Intersection of Two Array

vector<int> intersectionTwoSortedArrayBrute(vector<int>& a ,vector<int>& b){
    // Brute ::
    // using nested for loop
    int n=a.size();int m=b.size();
    vector<int> intersectionArray;
    vector<int> visited(b.size(),0);
    for(int  i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]&&visited[j]==0){
                intersectionArray.push_back(a[i]);
                visited[j]=1;
                break;
            }
            if(b[j]>a[i]) break;
        }
    }
    return intersectionArray;
}

vector<int> intersectionTwoSortedArrayOptimal(vector<int>& a,vector<int>& b){
    // Optimal :: 
    // Using Two pointer Approach i, j
    int n=a.size();int m=b.size();
    int i=0;int j=0;
    vector<int> ans;
    while (i<n&&j<m)
    {
        if(a[i]<b[j]) i++;
        else if(b[j]<a[i]) j++;
        else{
            ans.push_back(a[i]);
            i++;j++;
        }
    }
    return ans;
    
}

void printArray(vector<int>& arr){
    for(auto num : arr) cout<<num<<" ";
    cout<<endl;
}


int main(){
    vector<int> a={1,2,2,2,3,4,5,6,7,8,9};
    vector<int> b={4,5,7,9,10};
    vector<int> intersectionArray;
    intersectionArray=intersectionTwoSortedArrayOptimal(a,b);
    cout<<"A : ";printArray(a);
    cout<<"B : ";printArray(b);
    cout<<"A Intesect B : ";printArray(intersectionArray);
    return 0;
}