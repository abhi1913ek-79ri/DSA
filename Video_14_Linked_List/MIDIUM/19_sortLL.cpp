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

void printList(Node *head)
{
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

Node *sortLLNaiveByData(Node *head){
    // BY data : using array
    Node *temp = head;
    vector<int> arr;
    while (temp)
    {
        arr.push_back(temp->data);
        temp = temp->next; // Fix: advance the pointer
    }

    sort(arr.begin(), arr.end());

    temp = head;
    int i = 0;

    while (temp)
    {
        temp->data = arr[i++];
        temp = temp->next; // Fix: advance the pointer
    }

    return head;
    // TC = O(n + nlogN + n)
    // SC = O(n)
}

Node* mergeLL(Node* h1,Node* h2){
    if(!h1) return h2;
    if(!h2) return h1;

    Node* temp1 = h1;
    Node* temp2 = h2;
    Node* temp = NULL;

    if(h1->data>h2->data){
        temp = h2;
        temp2 = temp2->next;
    }else{
        temp = h1;
        temp1 = temp1->next;
    }
    Node* headM = temp;


    while (temp1&&temp2){
        if(temp1->data >= temp2->data){
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }else{
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    while (temp1){
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    }

    while (temp2){
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    
    

    return headM;
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; 
}

Node* sortLLOptimalMerge(Node* head){
    // base case
    if(!head || head->next == NULL) return head;

    Node* middle = findMid(head);
    
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = NULL ; // split 

    leftHead = sortLLOptimalMerge(leftHead);
    rightHead = sortLLOptimalMerge(rightHead);

    return mergeLL(leftHead,rightHead);
}

int main(){
    vector<int> arr = {4, 2, 1, 3, 5}; // Changed to unsorted array for better testing
    Node *head = convertToList(arr);
    cout << "Original List : ";
    printList(head);
    head = sortLLOptimalMerge(head);
    cout << "Sorted List : ";
    printList(head);
    return 0;
}