#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;

//function prototype
int minimum(int a, int b);
int maximum(int a, int b);




//main................

//main1
// int main() {
//   string s;
//   cout << "Enter a string: ";
//   cin >> s;
//   cout << "Hello World!\n" << s;
//   return 0;
// }

//main2

// int main() {
//   int a, b;
//   cout << "Enter number 1: ";
//   cin >> a;
//   cout << "Enter number 2: ";
//   cin >> b;
//   cout << "Min: " << minimum(a,b) << endl;  
//   cout << "Max: " << maximum(a,b) << endl;
//   return 0;
// }

//main3

int main(){
  return 0 ;
}





//Function Definition
int minimum(int a, int b){
  if(a<b) return a;
  else return b;
}


int maximum(int a, int b){
  if(a>b) return a;
  else return b;
}