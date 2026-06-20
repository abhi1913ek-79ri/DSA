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
Node* reverseLLStack(Node* head){
    // Only data get reversed not the links 
    Node* temp = head;
    stack<int> st;
    while (temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;
    }

    temp = head;
    while (temp!=NULL)
    {
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }

    return  head;
    // TC = O(2n)
    // SC = O(n)
}


Node* reverseLLIterative(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while (curr!=NULL){
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
    // TC = O(n)
    // SC = O(1)
}

Node* reverseLLRecursive(Node* head){
    // Base Case
    if(head==NULL || head->next == NULL) return head;

    Node* newHead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
    // TC = O(n)
    // SC = O(n)
}




int main(){
    vector<int> arr={0,1,2,3,4,5};
    int val=5;
    Node* head = convertToList(arr);
    
    cout<<"List Eelements Before Reversal : ";
    printList(head);
    head = reverseLLRecursive(head);
    cout<<"List Eelements After reversal : ";
    printList(head);
    return 0;
}