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

Node* convertToList(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
       Node* temp = new Node(arr[i]);
       mover->next= temp;
       mover=temp;
    }
    return head;
}


int lengthList(Node* head){
    int length = 0;
    Node* curr=head;
    while(curr){
        length++;
        curr=curr->next;
    }
    return length;
}

void printList(Node* head){
    if (!head) {  // agar list empty hai
        cout << "List is empty\n";
        return;
    }
    Node* mover = head;
    while (mover) // mover is valid 
    {
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    cout<<"\n";
}

Node* middleNodeNaive(Node* head){
    Node* temp = head;
    int len = 0;
    while (temp!=NULL){
        len++;
        temp=temp->next;
    }

    int middleNode = len/2 + 1;

    temp = head;
    while (temp!=NULL)
    {
        middleNode--;
        if(middleNode==0) break;
        temp=temp->next;
    }

    return temp;
    // TC = O(n+n/2)
    // SC = O(1)
}


// intitution : slow is just x/2 step and fast is with x step then for distance automatically slow is at half when fast is at last
Node* middleNodeOptimal(Node* head){
    // tortoise and hare Algorithm
    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    // TC = O(n/2)
    // SC = O(1)
}

int main(){
    vector<int> arr={0,1,2,3,4,5};
    int val=5;
    Node* head = convertToList(arr);
    
    cout<<"List Eelements: ";
    printList(head);
    Node* middleNode = middleNodeOptimal(head);
    cout << "Middle Node is : "<<middleNode->data<<", With Address : "<<middleNode<<endl;
    return 0;
}