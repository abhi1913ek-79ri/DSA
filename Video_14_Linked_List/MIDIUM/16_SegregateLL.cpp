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

// naive approach : Data replace
Node* segregateNaive(Node* head){
    // edge cases : NULL and single node 
    if(!head || head->next==NULL) return head;
    vector<int> list;
    Node* temp = head;
    while (temp && temp->next!=NULL)
    {
        list.push_back(temp->data);
        temp = temp->next->next;
    }
    // add last node
    if(temp) list.push_back(temp->data);

    temp = head->next;
    while (temp && temp->next!=NULL){
        list.push_back(temp->data);
        temp = temp->next->next;
    }
    // add last node
    if(temp) list.push_back(temp->data);

    // replace data
    temp = head;
    int i = 0;
    while (temp)
    {
        temp->data = list[i];
        i++;
        temp=temp->next;
    }
    return head;
    // TC = O(n+n)
    // SC = O(n)
}

// n/2 * 2 = n approach striver - cannical in place approach
Node* segregateStriver(Node* head){
    // edge cases : NULL and single node 
    if(!head || head->next==NULL) return head;

    Node* odd = head;
    Node* even = head->next;

    Node* evenHead = even;
    while (even && even->next != NULL) // stopping condition depends on only even : becoz even is always ahead of odd so
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
    // TC = O(n)
    // SC = O(1)
    
}

Node* segregate(Node* head){
    // me
    // edge cases : NULL and single node 
    if(!head || head->next==NULL) return head;

    Node* oddHead = head;
    Node* evenHead = head->next;
    Node* oddTail = oddHead;
    Node* evenTail = evenHead;

    Node* temp = evenHead->next; // 3rd Node
    bool isOdd = true;
    while (temp!=NULL)
    {
        if(isOdd){
            oddTail->next = temp;
            oddTail = temp;
            isOdd = false;
            temp=temp->next;
        }else{
            evenTail->next = temp;
            evenTail = temp;
            isOdd = true;
            temp=temp->next;
        }
    }

    // Joining odd and even list
    oddTail->next = evenHead;
    evenTail->next = NULL;

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
    head = segregateStriver(head);
    cout<<"Segregated List : ";
    printList(head);
    return 0;
}