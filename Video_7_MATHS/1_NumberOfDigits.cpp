#include<bits/stdc++.h>
using namespace std;
// 1-number of digits 
// 2-reverse number
// 3-Armstrong Number
// 4-pallindrome Number

// prtotype
int numberOfDigits_brute_force(int n){
    int count=0;
    while(n>0){
        count++;
        n/=10;
    }
    return count;
}
int numberOfDigits_logarithmic(int n){
    return (int)(log10(n)+1);
}
int reverseNumber(int n){
    int reverse=0;
    while(n>0){
        int lastDigit=n%10;
        reverse=reverse*10+lastDigit;
        n/=10;
    }
    return reverse;
}
string Pallindrome(int n){
    int m=n;
    if(reverseNumber(n)==m)return "Pallindrome";
    return "Not Pallindrome";
}
string armstrong(int n){
    int m=n;
    int res=0;
    while(n>0){
        int lastDigit=n%10;
        res+=lastDigit*lastDigit*lastDigit;
        n/=10;
    }
    if(m==res)return "Armstrong";
    return "Not Armstrong";
}


int main(){
    int n=101;
    cout<<"Number of Digits in "<<n<<" is "<<numberOfDigits_brute_force(n)<<endl;
    cout<<"Number of Digits in "<<n<<" is "<<numberOfDigits_logarithmic(n)<<endl;
    cout<<"Reverse of "<<n<<" is "<<reverseNumber(n)<<"."<<endl;
    cout<<"The number "<<n<<" is  "<<Pallindrome(n)<<"."<<endl;
    cout<<"The number "<<n<<" is  "<<armstrong(n)<<"."<<endl;
    cout<<"The number "<<153<<" is  "<<armstrong(153)<<"."<<endl;
    return 0;
}