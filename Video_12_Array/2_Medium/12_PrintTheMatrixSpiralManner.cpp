#include<bits/stdc++.h>
using namespace std;
// Spiral Traversal of Matrix
// Problem Statement: Given a Matrix, print the given matrix in spiral order.

// Examples:

// Example 1:
// Input: Matrix[][] = { { 1, 2, 3, 4 },
// 		      { 5, 6, 7, 8 },
// 		      { 9, 10, 11, 12 },
// 	              { 13, 14, 15, 16 } }

// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

vector<int> spiralMatrix(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;

    int left =0,right=m-1;
    int top =0,bottom=n-1;
    // right - bottom - left - top

    while(top<=bottom&&left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;

}

void printMatrix(vector<vector<int>>& matrix){
    int n=matrix.size(); //rows  
    int m = (n > 0) ? matrix[0].size() : 0;  // Number of columns
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printArray(vector<int> arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<vector<int>> matrix ={
        {1,2,3},
        {8,9,4},
        {7,6,5},
    };
    cout<<"Matrix : \n";printMatrix(matrix);
    vector<int> ans=spiralMatrix(matrix);
    cout<<"Spiral : \n";printArray(ans);
    return 0;
}