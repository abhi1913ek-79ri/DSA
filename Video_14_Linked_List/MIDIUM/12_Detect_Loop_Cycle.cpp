#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data , Node* next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

// Node* convertToList(vector<int>& arr){
//     Node* head = new Node(arr[0]);
//     Node* mover = head;
//     for(int i=1;i<arr.size();i++){
//        Node* temp = new Node(arr[i]);
//        mover->next= temp;
//        mover=temp;
//     }
//     return head;
// }


// int lengthList(Node* head){
//     int length = 0;
//     Node* curr=head;
//     while(curr){
//         length++;
//         curr=curr->next;
//     }
//     return length;
// }

// void printList(Node* head){
//     if (!head) {  // agar list empty hai
//         cout << "List is empty\n";
//         return;
//     }
//     Node* mover = head;
//     while (mover) // mover is valid 
//     {
//         cout<<mover->data<<" ";
//         mover=mover->next;
//     }
//     cout<<"\n";
// }

bool detectLoopNaive(Node* head){
    unordered_map<Node*,int> mpp;
    Node* temp = head;
    while (temp!=NULL)
    {
        if(mpp[temp]>0) return true; // log(n) - find
        mpp[temp]++; // log(n) - insert operation if unordered_map = O(1)
        temp=temp->next;
    }
    return false;
    // TC = O(nlog(n)) - unorederd map me - TC = O(n) average
    // SC = O(N)
}

bool detectLoopOptimal(Node* head){
    // tortoise and hare 
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL && fast->next!=NULL){ // condition for linear
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true; // why is always true - difference between steps of slow and fast = 1
    }
    return false;
    // TC = O(n)
    // SC = O(1)
}


int main(){
    Node* node1 =new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    bool hasLoop = detectLoopOptimal(node1);
    cout << "List has loop : " << hasLoop <<endl;
    // Cycle
    node5->next = node2;
    hasLoop = detectLoopOptimal(node1);
    cout << "List has loop : " << hasLoop <<endl;
    return 0;
}