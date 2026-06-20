#include<bits/stdc++.h>
using namespace std;

class Node{
public:
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

bool searchList(Node* head,int k){
    Node* curr = head;
    while(curr){
        if(curr->data==k) return true;
        curr=curr->next;
    }
    return false;
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



int main(){
    vector<int> arr={1,2,3,4};
    Node* head = convertToList(arr);
    int k=5;
    cout<<"List Eelements : ";
    printList(head);
    cout<<"List length : "<<lengthList(head)<<endl;
    cout<<k<< " is present  = " << searchList(head,k)<<endl;
    return 0;
}