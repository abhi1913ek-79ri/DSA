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

Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* removeTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* curr = head;
    while(curr->next->next != NULL){
        curr=curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    return head;
}
Node* removeK(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt = 1;
    Node* curr = head;
    Node* prev = NULL;
    while (curr!=NULL)
    {
        if(cnt == k){
            prev->next=prev->next->next;
            delete curr;
            break;
        }
        prev = curr;
        curr =curr->next;
        cnt++;
    }
    return head;
}

Node* removeEl(Node* head,int el){
    if(head==NULL) return head;
    if(head->data==el){
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    while (curr!=NULL)
    {
        if(curr->data==el){
            prev->next=prev->next->next;
            delete curr;
            break;
        }
        prev = curr;
        curr =curr->next;
    }
    return head;
}

int main(){
    vector<int> arr={0,1,2};
    int val=5;
    Node* head = convertToList(arr);
    
    cout<<"List Eelements Before removal : ";
    printList(head);
    cout<<"List length Before removal : "<<lengthList(head)<<endl;
    head=removeEl(head,1);
    cout<<"List Eelements after removal : ";
    printList(head);
    cout<<"List length after removal : "<<lengthList(head)<<endl;
    return 0;
}