#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertToDLL(vector<int> &arr)
{
    // 1st Node ya Head ban gyaa & linked bhi done
    Node *head = new Node(arr[0]);

    // now all next nodes
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node* deleteDuplicatesNaive(Node* head){
    if(!head || head->next == NULL) return head;
    Node* temp = head;
    while (temp){
        Node* prev = temp->back;
        Node* front = temp->next;
        if(prev&&prev->data == temp->data){
            prev->next = front;
            if(front) front->back =prev;
            delete temp;
        }
        temp = front;
    }
    return head;
}

Node* deleteDuplicatesOptimal(Node* head){
    Node* temp = head;
    while (temp!=NULL && temp->next!=NULL)
    {
        Node* nextNode = temp->next;
        while (nextNode!= NULL && temp->data == nextNode->data)
        {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->back = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,1,2,2,2,3,4,4,4,4};
    Node *head = convertToDLL(arr);
    // Node* head = NULL;
    cout << "Original DLL : ";
    printDLL(head);
    head = deleteDuplicatesOptimal(head); // sorted
    cout << "DLL After deletion : ";
    printDLL(head);
    return 0;
}