#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
//Input: 
// [[1,2,3],  Ouput : [[7,4,1],
// [4,5,6],    [8,5,2],
// [7,8,9]]    [9,6,3]]
void RotateMatrix90DegBrute(vector<vector<int>>& matrix){
    // Just Obeserve : maping of matrix[i][j] --> ans [j][n-i-1]  
    int n = matrix.size(); // square matrix n*n
    vector<vector<int>> ans(n, vector<int>(n, 0));
    // compute ans helper
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-i-1]=matrix[i][j];
        }
    }
    // change original matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=ans[i][j];
        }
    }
    // TC = O(N*N)
    // SC = O(N*N)
}

void RotateMatrix90DegOptimal(vector<vector<int>>& matrix){
    // 1. DO Transpose : why ? Becoz we see that we have to convert row to column
    // 2. Just Reverse Every row
    int n = matrix.size(); 
    // Transpose
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // reverse every row
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

    // TC = O(N*N)
    // SC = O(1)  - In Place
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

int main(){
    vector<vector<int>> matrix ={
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    cout<<"Matrix : \n";printMatrix(matrix);
    RotateMatrix90DegOptimal(matrix);
    cout<<"Rotated Matrix : \n";printMatrix(matrix);
    return 0;
}