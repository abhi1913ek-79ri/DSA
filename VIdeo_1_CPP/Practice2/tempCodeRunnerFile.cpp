#include <bits/stdc++.h>
 using namespace std;

int main(){
    int arr[3][3];
    // display
    for(int i=0;i<3;i++){
      for (int j=0;j<3;j++){
        cout << arr[i][j] << "\t\t";
      }
      cout << endl;
    }

    arr[0][0]=1;
    for(int i=0;i<3;i++){
      for (int j=0;j<3;j++){
        cout << arr[i][j] << "\t\t";
      }
      cout << endl;
    }
    return 0;
}