#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(Node* next,int data){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};




// int main(){
//     vector<int> arr={1,2,3,4};
//     // first way
//     Node x = Node(arr[0]);
//     Node* y = &x; // head
//     cout << y->data;
//     Node x2 = Node(arr[1]); // initialise and declare new Node
//     y->next = &x2; // Linking
//     cout << y->next->data;

//     return 0;
// }

int main(){
    vector<int> arr={1,2,3,4};
    // 2nd Way
    Node* Head = new Node(arr[0]); // declared a neew pttr head and assigned address of head node 
    cout << Head->data<<" ";
    Head->next = new Node(arr[1]); // temp ptr jo ki temp object ko point kar ra hain node bana and assigned to head->next me 
    cout << Head->next->data;
    return 0;
}