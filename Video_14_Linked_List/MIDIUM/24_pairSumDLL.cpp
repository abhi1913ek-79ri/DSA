#include <bits/stdc++.h>
using namespace std;
// given sorted list

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

vector<pair<int,int>> findPairsSumNaive(Node* head,int key){
    vector<pair<int,int>> ans;
    Node* t1 = head;
    while (t1){
        Node* t2 = t1->next;
        while (t2&&t1->data+t2->data<=key){
            if(t1->data+t2->data == key){
                ans.push_back({t1->data,t2->data});
            }
           t2 =t2->next; 
        }
        t1 = t1->next;
    }
    return ans;
    // TC = O(N²)
    // SC = O(1) for solve 
    // SC = O(n) for ans
}


// findTail
Node* findTail(Node* head){
    Node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    return temp;
}

vector<pair<int,int>> findPairsSumOptimal(Node* head,int key){
    vector<pair<int,int>> ans;
    Node* left = head;
    Node* right = findTail(head); // o(n)

    while (left->data < right->data){ // O(n)
        if(left->data+right->data == key){
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }else if(left->data+right->data < key){
            left = left->next;
        }else{
            right = right->back;
        }
    }
    return ans;
    // TC = O(2N)
    // SC = O(1) for solve 
    // SC = O(n) for ans
}

void printAns(vector<pair<int,int>> & arr){
    for(auto pair : arr){
        cout<<"("<<pair.first<<","<<pair.second<<")\t";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};
    int key = 7;
    Node* head = convertToDLL(arr);
    cout<<"DLL : ";
    printDLL(head);
    vector<pair<int,int>> ans = findPairsSumOptimal(head,key);
    cout<<"pairs : ";
    printAns(ans);
    return 0;
}