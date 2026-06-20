#include <bits/stdc++.h>
using namespace std;

// Function Prototype
// void insert_elements(int arr[][], int m ; int n);
// void display_array( int m, int n ,int arr[m][n]);




// 1D Array

// main2

// int main() {
//   int arr[5];
//   cout << "Enter values" << endl;
//   cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
//   for(int i = 0; i < 5; i++){
//     cout << arr[i] << " ";
//   }
//   return 0;
// }

// main2

// int main(){
//   int arr[5]={1,2,3,4,5};
//   cout << arr[4];
//   return 0;
// }

//main3

// int main() {
//   int arr[5]{arr[4] = 3};
//   for (int i = 0; i < 5; i++) {
//     cout << arr[i] << " ";
//   }
//   return 0;
// }




//For 2D Array

int main(){

// inster elemnts in 2D array M1
  int m,n;
  cout << "Enter number of rows m1 : ";
  cin >> m;
  cout << "Enter number of column m1 : ";
  cin >> n;
  int m1[m][n];
  for(int i=0; i<m ; i++){
    for(int j=0 ; j<n ; j++){
      cout << "Enter " << i << j << " th element m1 :";
      cin >> m1[i][j] ;
    }
  }


// inster elemnts in 2D array M2
  int p,q;
  cout << "Enter number of rows m2 : ";
  cin >> p;
  cout << "Enter number of column m2: ";
  cin >> q;
  int m2[p][q];
  for(int i=0; i<p ; i++){
    for(int j=0 ; j<q ; j++){
      cout << "Enter " << i << j << " th element m2:";
      cin >> m2[i][j] ;
    }
  }



// display
cout << "\n\n m1 Matrix............. \n\n";
for(int i=0; i<m ; i++){
  for (int j=0;j<n;j++){
    cout << m1[i][j] << "\t";
  }
  cout << endl;
}


// display
cout << "\n\n m2 Matrix.............. \n\n";
for(int i=0; i<p ; i++){
  for (int j=0;j<q;j++){
    cout << m2[i][j] << "\t";
  }
  cout << endl;
}


//Multiplication of m1 m2
int res[m][q];
if(n==p){
  for(int i=0;i<m;i++){
    for(int j=0;j<q;j++){
      int sum=0;
      for(int k=0;k<n;k++){
        sum+=m1[i][k]*m2[k][j];

      }
      res[i][j]=sum;
    }
  }
// display
cout << "\n\nresultant Matrix..............\n\n";
for(int i=0; i<m ; i++){
  for (int j=0;j<q;j++){
    cout << res[i][j] << "\t";
  }
  cout << endl;
}
}
else {
  cout << "Multiplication m1 and m2 is not possible......!";
}


cout << "\n\nprogram ends\n\n"; 
  return 0;
}



// Function Declaration
// void insert_elements(int arr[][]){

// }

// void display_array(int arr[m][n] , int m , int n){
//   for(int i=0;i<m;i++){
//     for (int j=0;j<n;j++){
//       cout << arr[i][j] << "\t";
//     }
//     cout << endl;
//   }
// }3
