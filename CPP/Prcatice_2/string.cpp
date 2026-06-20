#include<bits/stdc++.h>
using  namespace std;

//funcion prototype 
void printname(string name,int n);
void greeting(string name);

int main(){
  string s;
  cout << "Enter your name : ";
  cin >> s;
  int n=s.size();
  printname(s,n);
  greeting(s);
  
  return 0;
}


// function definition 
void printname(string name,int n){
  cout << "Your name is : " << name <<" and your name size is " << n << endl;
}

void greeting(string name){
cout << "helo " << name << endl;
  
}