#include<bits/stdc++.h>
using namespace std;
// Swap two nums

// Brute force using temp variable
void swap1(int & a,int & b){
    int temp = b;
    b= a;
    a= temp;
}

// Optimal using Mathematics equation
void swap2(int &a ,int &b){
    a = a+b;
    b = a-b;
    a = a-b;
    // can be overflow on addition etc
}

// Using Bit Manipulation
void swap3(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
    // for same numbers swap not happen
    // answer become 0
}


// optimal -1
void swap4(int &a, int &b){
    if(&a==&b){
        return;
    };
    a = a^b;
    b = a^b;
    a = a^b;
}



int main(){
    int a = 5;
    int b = 10;

    cout << "Before swap: a = " <<a<<" , b = "<<b<<"\n";
    swap3(a,b); //
    cout << "After swap : a = " <<a<<" , b = "<<b<<"\n";
    return 0;
}