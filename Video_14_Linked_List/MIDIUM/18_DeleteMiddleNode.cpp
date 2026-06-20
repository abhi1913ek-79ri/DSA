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


// Delete middle node : odd me beech ka and even me m2
Node* removeMidNaive(Node* head){
    if(!head) return NULL;
    if(head->next == NULL) return NULL;
    int n = lengthList(head);
    int mid = (n/2)+1;
    int cnt = 0;
    Node* temp = head;
    while (temp)
    {
        cnt++;
        if(cnt+1 == mid){
            Node* nodeToDel = temp->next;
            temp->next = temp->next->next;
            delete nodeToDel;
            return head;
        }
        temp = temp->next;
    }

    return head;
    // TC = O(n+n)
    // SC = O(1)
}

// Using Totoise and Hare Algorithm 
Node* removeMidOptimal(Node* head){
    if(!head || head->next == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* nodeToDel = prev->next;

    prev->next = prev->next->next;

    delete nodeToDel;

    return head;
    // TC = O(n/2)
    // Sc = O(1)
}

int main(){
    vector<int> arr={1,2,3,4};
    int val=5;
    Node* head = convertToList(arr); 
    cout<<"Original List : ";
    printList(head);
    head = removeMidOptimal(head);
    cout<<"Deleted node  List : ";
    printList(head);
    return 0;
}