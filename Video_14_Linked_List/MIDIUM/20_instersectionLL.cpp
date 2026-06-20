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
Node* intersectionHash(Node* h1,Node* h2){
    // Using Hashing 
    unordered_map<Node*, int > mpp;
    Node* temp = h1;
    while (temp){
        mpp[temp]++; // insertion - O(1)
        temp = temp->next;
    }

    temp = h2;
    while (temp){
        if(mpp[temp]>0) return temp; // O(1)
        temp = temp->next;
    }

    return NULL;
    // TC = O(n+m)
    // SC = O(n)
}

Node* intersectionBetter(Node* h1,Node* h2){
    // Length difference method
    // Edge Case
    if(h1==NULL || h2 == NULL) return NULL;
    // count
    int N1 = lengthList(h1); // O(n1)
    int N2 = lengthList(h2); // O(n2)
    int d = 0;

    Node* temp1 = NULL;
    Node* temp2 = NULL;


    if(N1>N2){
        temp1=h1;
        temp2 = h2;
        d=N1 - N2;

    }else{
        temp1=h2;
        temp2 = h1;
        d=N2 - N1;
    }

    for(int i=1;i<=d;i++){  // O(d)
        temp1 = temp1->next;
    }

    while (temp1!=temp2){ // O(n2-d)
        temp1=temp1->next;
        temp2=temp2->next;
    }

    return temp1;
    // TC = o(n1+2n2) or o(n2+2n1)
    // SC = O(1)  
}


Node* intersectionOptimal(Node* h1,Node* h2){
    // twice traversal method 
    if(h1==NULL ||  h2==NULL) return NULL;
    Node* temp1 = h1;
    Node* temp2 = h2;

    while (temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;

        if(temp1==NULL) temp1 = h2;
        if(temp2==NULL) temp2 = h1;
    }

    return temp1;
}

int main(){
    // LL1
    Node* h1 = new Node(4);
    Node* n2 = new Node(1);
    Node* n3 = new Node(8);

    // Link LL1
    h1->next = n2;
    n2->next = n3;

    // LL2
    Node* h2 = new Node(5);
    Node* m2 = new Node(6);
    Node* m3 = new Node(1);

    // Link LL2
    h2->next = m2;
    m2->next = m3;

    
    // Linking Node 
    m3->next = n3;

    Node* i1 = n3;
    Node* i2 = new Node(4);
    Node* i3 = new Node(5);

    i1->next = i2;
    i2->next = i3;

    // print LL 
    cout<<"LL1 : ";printList(h1);
    cout<<"LL2 : ";printList(h2);
    Node* intersected = intersectionOptimal(h1,h2);
    cout << "NOI : "<<intersected->data;
    return 0;
}