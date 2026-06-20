#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given a matrix if an element in the matrix is 0 then you will
// have to set its entire column and row to 0 and then return the matrix.
// Approach:
// The steps are the following:

// First, we will use two loops(nested loops) to traverse all the cells of the matrix.
// If any cell (i,j) contains the value 0, we will mark all cells in row i and column j with -1 except those which contain 0.
// We will perform step 2 for every cell containing 0.
// Finally, we will mark all the cells containing -1 with 0.
// Thus the given matrix will be modified according to the question.

// /Examples 1:
// Input:
//  matrix=[[1,1,1],[1,0,1],[1,1,1]]

// Output:
//  [[1,0,1],[0,0,0],[1,0,1]]

// Explanation:
//  Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.
void markRow(vector<vector<int>>& matrix ,int n ,int m,int i){
    for(int j=0;j<m;j++){
        matrix[i][j] = -1;
    }
}
void markCol(vector<vector<int>>& matrix ,int n ,int m,int j){
    for(int i=0;i<m;i++){
        matrix[i][j] = -1;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n=matrix.size(); //rows  
    int m = (n > 0) ? matrix[0].size() : 0;  // Number of columns
    // mark for -1
    // o(N*M)(N+M)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                markRow(matrix,n,m,i);
                markCol(matrix,n,m,j);
            }
        }
    }
    // mark for zeroes
    // o(N*M)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
    // TC = O(N*N*N) type 
    // SC = O(1)   
}
void setZeroesBetter(vector<vector<int>>& matrix) { // using track of column or row to be marked not marked instantly
    int n=matrix.size(); 
    int m = (n > 0) ? matrix[0].size() : 0;  // Number of columns
    vector<int> row(n,0);
    vector<int> col(m,0);

    // Keep Track
    for(int i=0;i<n;i++){ // O(N*M)
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    // Marking 
    for(int i=0;i<n;i++){ // O(N*M)
        for(int j=0;j<m;j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;
            }
        }
    }    

    // TC = O(2*N*M)
    // SC = O(N+M) -- optimisation only in space can be done usin inplace 
}

void setZeroesOptimal(vector<vector<int>>& matrix) { // using track of column or row to be marked not marked instantly
    // inplace row = matrix[..][0]
    // inplace col = matrix[0][..]

    int n=matrix.size(); 
    int m = (n > 0) ? matrix[0].size() : 0;  // Number of columns

    int col0=1;
    // Keep Track
    for(int i=0;i<n;i++){ // O(N*M)
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;

                if(j!=0){
                    matrix[0][j]=0;
                }else{
                    col0=0;
                }
            }
        }
    }
    // // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for(int i=1;i<n;i++){ // O(N*M)
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
           }
        }
    } 
    //Finally mark the 1st col & then 1st row:   
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }


    // TC = O(2*N*M)
    // SC = O(1) 
}


void printMatrix(vector<vector<int>>& matrix ){
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
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {0, 1, 0},
        {1, 1, 0}
    };

    cout<<"Matrix : \n";
    printMatrix(matrix);
    setZeroesOptimal(matrix);
    cout<<"Matrix after setZeroes : \n";
    printMatrix(matrix);

    return 0;
}