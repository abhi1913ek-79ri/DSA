#include<bits/stdc++.h>
using namespace std;
// pair
int main(){
    int num;
    char name[10];
    cout<<"Enter num : ";
    cin>>num;
    cout<<"Enter name : ";
    cin>>name;
    pair<int,string> a ={1,"name"};
    a.first=num;
    a.second=name;
    cout<<a.first<< " "<<a.second;
    // declaring pair<int ,string> array
    pair<int,string> arr[5]={{1,"2"},{1,"2"},{1,"2"},{1,"2"},{1,"2"}};
    cout<<arr[0].first<<arr[0].second;


}