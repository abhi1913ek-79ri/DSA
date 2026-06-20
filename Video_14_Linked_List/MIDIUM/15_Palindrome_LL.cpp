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

bool isPalindrome(Node* head){
    stack<int> st;
    Node* temp = head;
    // step - 1 : push all the nodes in stack
    while (temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    // step - 2 checking pallindrome
    temp = head;
    while (temp!=NULL)
    {
        if(temp->data == st.top()){
            st.pop();
            temp = temp->next;
        }else{
            return false;
        }
    }
    return true;
    // TC = O(n+n)
    // SC = O(n)
}

// Reverse LL 
Node* reverseLLItertive(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while (curr!=NULL){
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

// Pallindrome
bool isPalindromeOptimal(Node* head){
    // Use reverse half and and compare it with first half
    // Step 1 : Find Middle 
    Node* slow = head;
    Node* fast = head;
    // we need to find m1 here in case of even
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middleNode = slow;

    // reverse second half
    Node* newHead = reverseLLItertive(slow->next);

    Node* first = head;
    Node* second = newHead;

    while(second!=NULL){
        if(first->data!=second->data){
            reverseLLItertive(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLLItertive(newHead);
    return true;
    // TC = O(2n)
    // SC = O(n)
}



int main(){
    vector<int> arr={1,2,3,2};
    int val=5;
    Node* head = convertToList(arr);
    
    cout<<"List Eelements: ";
    printList(head);
    bool isPal = isPalindromeOptimal(head);

    if(isPal) cout << "List is Palindrome";
    else cout << "List is not Palindrome";
    return 0;
}