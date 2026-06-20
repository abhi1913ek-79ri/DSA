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

// insertBeforeHead
Node* insertBeforeHead(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }

    Node* newNode = new Node(val,head,nullptr);

    head->back=newNode;

    head = head->back;
    return head;
}

// insertBeforeTail
Node* insertBeforeTail(Node* head,int val){
    // if empty list
    if(head==NULL){
        return new Node(val);
    }
    // if single element
    if(head->next==NULL){
        return insertBeforeHead(head,val);
    }
    Node* tail = head;
    while (tail->next!=NULL){
        tail=tail->next;
    }

    Node* prev = tail->back;

    Node* newNode = new Node(val,tail,prev);
    tail->back=newNode;
    prev->next=newNode;

    return head;  
}

// insertBeforeK()
Node* insertBeforeKthEle(Node* head,int val,int k){
    // k==1
    if(k==1){
        return insertBeforeHead(head,val);
    }

    Node* temp = head;
    int cnt = 0;

    while (temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }

    if(temp==NULL){
        cout<<"invalid position"<<endl;
        return head;
    }
    // // already handled by next lines 
    // // k==N
    // if(temp->next==NULL){
    //     return insertBeforeTail(head,val);
    // }

    Node* prev = temp->back;

    Node* newNode = new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;

    return  head;
    
}

// insertBeforeNode()
void insertBeforeNode(Node* node,int val){
    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
}

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertToDLL(arr);
    // Node* head = nullptr;
    cout<<"Original DLL : ";
    printDLL(head);
    insertBeforeNode(head->next->next->next->next,5);
    cout<<"DLL After insertion : ";
    printDLL(head);
    return 0;
}