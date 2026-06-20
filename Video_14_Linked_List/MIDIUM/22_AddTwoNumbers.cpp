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

Node* add2(Node* h1,Node* h2){
    int carry = 0;
    Node* t1 = h1;
    Node* t2 = h2;
    Node* result = NULL;
    Node* temp = NULL;
    while (t1!=NULL&&t2!=NULL){
        Node* newNode = NULL;
        int sum = t1->data + t2->data + carry;
        if(sum<10){
            newNode = new Node(sum);
            carry = 0;
        }else{
            newNode = new Node(sum%10);
            carry = 1;
        }

        if(result == NULL){
            result = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = temp->next;
        }

        t1 = t1->next;
        t2 = t2->next;
    }

    while (t1){
        Node* newNode = NULL;
        int sum = t1->data + carry;
        if(sum<10){
            newNode = new Node(sum);
            carry = 0;
        }else{
            newNode = new Node(sum%10);
            carry = 1;
        }
        temp->next = newNode;
        t1 = t1->next;
        temp = temp->next;

    }
    while (t2){
        Node* newNode = NULL;
        int sum = t2->data + carry;
        if(sum<10){
            newNode = new Node(sum);
            carry = 0;
        }else{
            newNode = new Node(sum%10);
            carry = 1;
        }
        temp->next = newNode;
        t2 = t2->next;
        temp = temp->next;
    }
    

    if(carry){
        Node* newNode = new Node(1);
        temp->next = newNode;
    }
    return result;
}

Node* add2Simplified(Node* h1,Node* h2){
    int carry = 0;
    Node* t1 = h1;
    Node* t2 = h2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (t1 != NULL || t2 != NULL) {
        int sum = carry;
        if (t1) {
            sum += t1->data;
            t1 = t1->next;
        }
        if (t2) {
            sum += t2->data;
            t2 = t2->next;
        }

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        temp->next = newNode;
        temp = temp->next;
    }

    if (carry) {
        Node* newNode = new Node(carry);
        temp->next = newNode;
    }
    return dummy->next;
}


int main(){
    vector<int> arr1 = {2,4,3};
    vector<int> arr2 = {5,6,4};
    Node* h1 = convertToList(arr1);
    Node* h2 = convertToList(arr2);

    cout << "List - 1: ";
    printList(h1);
    cout << "List - 2: ";
    printList(h2);
    Node* result = add2Simplified(h1,h2);
    cout << "After addition List : ";
    printList(result);
    return 0;
}