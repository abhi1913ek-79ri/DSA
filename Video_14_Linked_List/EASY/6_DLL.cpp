#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertToDLL(vector<int> & arr){
    // 1st Node ya Head ban gyaa & linked bhi done 
    Node* head = new Node(arr[0]);

    // now all next nodes 
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return  head;
}

void printDLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}


int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertToDLL(arr);
    cout<<"Original DLL : ";
    printDLL(head);
    return 0;
}