#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *convertToList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthList(Node *head)
{
    int length = 0;
    Node *curr = head;
    while (curr)
    {
        length++;
        curr = curr->next;
    }
    return length;
}

void printList(Node *head){
    if (!head)
    { // agar list empty hai
        cout << "List is empty\n";
        return;
    }
    Node *mover = head;
    while (mover) // mover is valid
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << "\n";
}

int convertListToNum(Node* head){
    int num = 0;
    Node* mover = head;
    while (mover) // mover is valid
    {
        num = num*10 + mover->data;
        mover = mover->next;
    }
    return num;
}

Node* convertNumToList(int num){
    if (num == 0) return new Node(0);

    Node* head = nullptr;
    while(num > 0){
        Node* newNode = new Node(num % 10);
        newNode->next = head;
        head = newNode;
        num /= 10;
    }
    return head;
}


Node* addOneNaive(Node* head){
    int num = convertListToNum(head);
    num++;
    head = convertNumToList(num);
    return head;
    // TC = O(n+n)
    // SC = O(n) - not inplace
}

Node* reverseLL(Node* head){
    // base / edge case
    if(head==NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* front = NULL;
    Node* prev = NULL;

    while (curr){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front; 
    }

    return prev;
}

Node* addOneIterative(Node* head){
    head = reverseLL(head);
    int carry = 1;
    Node* temp = head;
    Node* prev = NULL;
    while (temp&&carry)
    {
        if(temp->data == 9){
            temp->data = 0;
            carry = 1;
        }else{
            temp->data += 1;
            carry = 0;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL&&carry){
        Node* newNode = new Node(1);
        prev->next = newNode;
    }

    head = reverseLL(head);
    return head;
}




// Reciursive approach - me Dhyan rakkna hain yahaan backTracking ka use kiya hainl without reverssal recursion kib wjah se 
int helper(Node* head){
    // base case
    if(head==NULL) return 1;

    int carry = helper(head->next);
    
    head->data += carry;
    if(head->data < 10){
        return 0;
    }
    head->data = 0;
    return 1;
}
Node* addOneRecursive(Node* head){
    int carry = helper(head);
    if(carry==1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

int main(){
    vector<int> arr = {4, 2, 1, 3, 9};
    Node *head = convertToList(arr);
    cout << "Original List : ";
    printList(head);
    head = addOneRecursive(head);
    cout << "After addition List : ";
    printList(head);
    return 0;
}