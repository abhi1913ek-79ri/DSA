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


// Delete nth from last 
Node* removeNlast(Node* head,int N){
    // naive approach
    // delete from start approach 
    // length -( N + 1 )th from start
    
    // Edge Cases 
    if(head==NULL) return NULL;

    // findLength
    int len = lengthList(head);

    if(N>len) return head;
    
    int nodeToRemove = len - N + 1;

    if(nodeToRemove == 1){ // head
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 1;

    Node* curr = head;
    Node* prev = NULL;

    while (curr){
        if(cnt == nodeToRemove){
            break;
        }
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    
    // if curr is NULL 
    if(!curr) return NULL;

    prev->next = curr->next;
    delete curr;
    
    return head;
    // TC = O(n+n)
    // SC = O(1)
}

Node* removeNlastOptimal(Node* head,int N){
    if(head==NULL) return NULL;
    
    Node* slow = head;

    Node* fast = head;


    for(int i=0;i<N;i++) fast = fast->next;

    if(fast == NULL){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }


    while (fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    

    Node* nodeDelete = slow->next;
    slow->next = slow->next->next;

    delete nodeDelete;
    
    return head;
    // TC = O(n)
    // SC = O(1)
}


int main(){
    vector<int> arr={1,2,3,4,5};
    int val=5;
    Node* head = convertToList(arr);
    
    cout<<"Original List : ";
    printList(head);
    head = removeNlastOptimal(head,5);
    cout<<"Deleted node  List : ";
    printList(head);
    return 0;
}