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

// insert head position
Node* insertHead(Node* head,int val){
    return new Node(val,head);
}
// insert at tail
Node* insertTail(Node* head,int val){
    Node* curr = head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    Node* tail = new Node(val);
    curr->next=tail;
    return head;
}
// Insert at kth position
Node* insertKthPosition(Node* head,int el,int k){
    // head cases
    if(!head){
        if(k==1){
            return new Node(el);
        }else{
            return NULL;
        }
    }
    if(k==1){
        return new Node(el,head);
    }
    // kth traverse cases
    int cnt = 1;
    Node* curr = head;
    while(curr){
        if(cnt==k-1) break;
        curr=curr->next;
        cnt++;
    }
    // invalid cases
    if(!curr){
        cout << "Invalid position element is Not inserted"<<endl;
        return head;
    }
    // kth cases
    Node* temp = new Node(el,curr->next);
    curr->next = temp;
    return head;
}

Node* insertAfterValue(Node* head,int el,int value){
    // head cases
    if(!head) return NULL;
    
    // after value
    Node* curr = head;
    while(curr){
      if(curr->data==value){
        break;
      }
      curr=curr->next;
    }
    // invalid cases
    if(!curr){
        cout << "Invalid position element is Not inserted"<<endl;
        return head;
    }
    // after value
    Node* temp = new Node(el,curr->next);
    curr->next = temp;
    return head;
}


int main(){
    vector<int> arr={0,1,2};
    int val=5;
    Node* head = convertToList(arr);
    
    cout<<"List Eelements Before insertion : ";
    printList(head);
    cout<<"List length Before insertion : "<<lengthList(head)<<endl;
    head=insertAfterValue(head,val,5);
    cout<<"List Eelements after insertion : ";
    printList(head);
    cout<<"List length after insertion : "<<lengthList(head)<<endl;
    return 0;
}