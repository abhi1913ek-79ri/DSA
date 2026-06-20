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
Node* deleteHead(Node* head){
    // empty list
    if(head==NULL){
        return NULL;
    }
    // single element in list
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    // more than 1 element
    Node* temp = head;
    head = head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    // empty list
    if(head==NULL){
        return NULL;
    }
    // single element in list
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    // more than 1 element
    Node* tail = head;
    while (tail->next !=NULL)
    {
        tail=tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;

    delete tail;
    return head;
}

Node* deleteKnode(Node* head,int k){
    if(head==NULL) return NULL;
    int cnt = 0;
    Node* kNode = head;
    while (kNode!=NULL){
        cnt++;
        if(cnt == k)  break;
        kNode = kNode->next;
    }
    if(kNode == NULL) return head;
    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(front==NULL&&prev==NULL){
        return NULL;
    }else if(prev==NULL){
        return deleteHead(head);
    }else if(front==NULL){
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    kNode->back=kNode->next=NULL;
    delete kNode;
    return head;
}

// void deleteNode(Node* node){
//     // Doubly linked list
//     if(node->next==NULL){ // if node = tail
//         Node* prev = node->back;
//         prev->next=NULL;
//         node->back=NULL;
//         delete node;
//         return;
//     }
//     Node* prev = node->back;
//     Node* front = node->next;

//     prev->next = front;
//     front->back = prev;
    
//     node->back=node->next=NULL;
//     delete node;
//     return;  
// }

void deleteNode(Node* node){
    Node* prev = node->back;
    Node* front = node->next;

    // node is tail
    if(front==NULL){
        prev->next=NULL;
        node->back=NULL;
        delete node;
        return;
    }
    // establish the links
    prev->next=front;
    front->back=prev;

    // break the links 
    node->back=node->next=NULL;

    // free the memory
    // free(node); -- kar skate hain but dono me bahut diffrence hain - destructor call hoga delete ke case me but 
    // free ke case me destructor call nhi hoga  ye bus malloc wagera se jo memory hoti hain uske liye hain 
    delete node;
}

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertToDLL(arr);
    cout<<"Original DLL : ";
    printDLL(head);
    deleteNode(head->next->next);
    cout<<"DLL After deletion : ";
    printDLL(head);
    return 0;
}