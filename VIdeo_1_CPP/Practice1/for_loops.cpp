#include<iostream>
using namespace std;

// Program for print table in cpp.........

// int main(){
//     int table;
//     cin >> table ;
//     int i;
//     for(i=1;i<=10;i++){
//         cout << table << " x " << i << " = " << table*i << endl;

//     }

//     cout <<"\n\nprogram is ended\n\n";

//     return 0;

// }


//using while loop
int main(){
    int table;
    cin >> table ;
    int i=1;
    while(i<=10){
        cout << table << " x " << i << " = " << table*i << endl;
        i++;

    }

    cout <<"\n\nprogram is ended\n\n";

    return 0;

}

