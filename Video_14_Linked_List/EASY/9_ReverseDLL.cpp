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

// reverse DLL - Naive Approach - swaping data
Node* reverseDLLStack(Node* head){
    // empty list and single node 
    if(head->next==NULL || head == NULL){
        return  head;
    }

    stack<int> st;
    Node* temp = head;
    while (temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }


    temp= head;
    while (temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
    // TC = O(2N)
    // SC = O(N)
}

// Optimal One - swaping links 
// fisrtly think about single Node 
// then apply for whole

Node* reverseDLL(Node* head){
    // if empty list and single node 
    if(head==NULL || head->next==NULL) return head;

    Node* curr = head;
    Node* prev = NULL;
    while (curr!=NULL){
        prev = curr->back;
        curr->back = curr->next;
        curr->next = prev;
        curr=curr->back; // remember this as next is  and back is swappedd so go to next ww go to back of new list
    }
    head = prev->back;
    return head;
}




int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertToDLL(arr);
    // Node* head = nullptr;
    cout<<"Original DLL : ";
    printDLL(head);
    head=reverseDLL(head);
    cout<<"DLL After reversal : ";
    printDLL(head);
    return 0;
}