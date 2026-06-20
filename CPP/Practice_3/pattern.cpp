#include <iostream>
 using namespace std;
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "* ";
        }
        cout << endl;
    }
 }
void pattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << "* ";
        } 
        cout << endl;
    }
}
void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern5(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void pattern6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern7(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i;j++){
            cout << " ";
        }
        for(int j=1; j<=2*i-1; j++){
            cout << "*";
        }
        for(int j=1; j<=n-i;j++){
            cout << " ";
        }
        cout << endl;
    }
}
void pattern8(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i;j++){
            cout << " ";
        }
        for(int j=1; j<=2*i-1; j++){
            cout << "*";
        }
        for(int j=1; j<=n-i;j++){
            cout << " ";
        }
        cout << endl;
    }
}
void pattern9(int n){
    //for upper part 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i;j++){
            cout << " ";
        }
        for(int j=1; j<=2*i-1; j++){
            cout << "*";
        }
        for(int j=1; j<=n-i;j++){
            cout << " ";
        }
        cout << endl;
    }
    //for lower part
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i;j++){
            cout << " ";
        }
        for(int j=1; j<=2*i-1; j++){
            cout << "*";
        }
        for(int j=1; j<=n-i;j++){
            cout << " ";
        }
        cout << endl;
    }

}
void pattern10(int n){
    for(int i = 1;i<=(2*n-1);i++){
        if(i<n+1){
            for(int j=1;j<=i;j++){
                cout << "*" << " ";
            }
            for(int j =1;j<=n-i;j++){
                cout << " ";
            }
            cout << endl;
        }
         else {
            for(int j =1;j<=2*n-i;j++){
                cout << "*" << " ";
            }
            for(int j =1;j<=n-i;j++){
                cout << " ";
            }
            cout << endl;

        }
    }
}
void pattern11(int n){
    for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
            if (i%2){
            if(j%2!=0){
                cout << 1;
            }
            else{
                cout << 0;
            }
            }

        
        else {
            if(j%2!=0){
                cout << 0;
            }
            else{
                cout << 1;
            }
            
        }
        }
        cout << endl;
    }
}
void pattern12(int n){
    for(int i=1; i<=n; i++){
        //numbers
        for(int j=1;j<=i;j++){
            cout << j;
        }
        //spcaes
        for(int j=1;j<=2*(n-i);j++){
            cout << " ";
        }
        //numbers
        for(int j=i;j>=1;j--){
            cout << j;

        }
        cout << endl;
    }
}
void pattern13(int n){
    int start=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << start << " ";
            start+=1;
        }
        cout << endl;
    }
}
void pattern14(int n){
    for(int i=1;i<=n;i++){
        char start='A';
        for(int j=1;j<=i;j++){
            cout << start << " ";
            start+=1;
        }
        cout << endl;
    }
}
void pattern15(int n){
    for(int i=1;i<=n;i++){
        char start='A';
        for(int j=1;j<=n-i+1;j++){
            cout << start << " ";
            start+=1;
        }
        cout << endl;
    }
}
void pattern16(int n){
    char start='A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << start << " ";
        }
        start+=1;
        cout << endl;
    }
}
void pattern23(int n){
    for(int i=1;i<=n;i++){
        //prevspaces
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        //stars
        for(int j=1;j<=n;j++){
            cout<<"*";
        } 
        //postspaces
        for(int j=1;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
// void pattern23(int n){
//     for(int i=1;i<=n;i++){
//         //prevspaces
//         for(int j=1;j<=n-i;j++){
//             cout<<" ";
//         }
//         //stars
//         for(int j=1;j<=n;j++){
//             cout<<"*";
//         } 
//         //postspaces
//         for(int j=1;j<i;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }
//main
int main(){
    int test_case[3]={3,7,9};
    for(int i=0; i<3;i++){
        int n;
        n=test_case[i];
        pattern1(n);
        pattern2(n);
        pattern3(n);
        pattern4(n);
        pattern5(n);
        pattern6(n);
        pattern7(n);
        pattern8(n);
        pattern9(n);
        pattern10(n);
    //    pattern23(n);
       cout << endl;
    }
    return 0;
 }
