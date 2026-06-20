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

Node *deleteKeyALL(Node *head, int key)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == key)
        {
            Node *nodeToDel = temp;
            Node *prev = temp->back;
            Node *front = temp->next;
            if (prev == NULL)
            {
                head = head->next;
                if (head)
                    head->back = NULL;
            }
            else if (front == NULL)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = front;
                front->back = prev;
                temp->back = temp->next = NULL;
            }
            temp = front;
            delete nodeToDel;
            continue;
        }
        temp = temp->next;
    }
    return head;
}


Node* deleteKeyALLStriver(Node* head,int key){
    Node* temp = head;
    while (temp){
        if(temp->data == key){
            if(temp==head){
                head = head->next;
            }
            Node* prev = temp->back;
            Node* front = temp->next;

            if(prev) prev->next = front;
            if(front) front->back = prev;

            delete temp;

            temp = front;
        }
        else temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {3, 1, 2, 3, 5, 3};
    int key = 3;
    Node *head = convertToDLL(arr);
    // Node* head = NULL;
    cout << "Original DLL : ";
    printDLL(head);
    head = deleteKeyALLStriver(head, key);
    cout << "DLL After deletion : ";
    printDLL(head);
    return 0;
}