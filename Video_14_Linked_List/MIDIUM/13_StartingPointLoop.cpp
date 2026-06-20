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


bool detectLoopNaive(Node* head){
    unordered_map<Node*,int> mpp;
    Node* temp = head;
    while (temp!=NULL)
    {
        if(mpp[temp]>0) return true; // log(n) - find
        mpp[temp]++; // log(n) - insert operation if unordered_map = O(1)
        temp=temp->next;
    }
    return false;
    // TC = O(nlog(n)) - unorederd map me - TC = O(n) average
    // SC = O(N)
}

bool detectLoopOptimal(Node* head){
    // tortoise and hare 
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL && fast->next!=NULL){ // condition for linear
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true; // why is always true - difference between steps of slow and fast = 1
    }
    return false;
    // TC = O(n)
    // SC = O(1)
}

/* -------------------------
   Loop Detection (Naive)
   -------------------------
   Idea: Use hashing to mark visited nodes.
   If a node is visited twice => cycle exists.
   TC: O(n) average (unordered_map O(1) insert/find)
   SC: O(n)
*/
Node* startLoopNaive(Node* head){
    // Hash -first node  visited twice is required node 
    unordered_map<Node*,int> mpp;
    Node* temp = head;
    while (temp!=NULL)
    {
        if(mpp[temp]>0) return temp;
        mpp[temp]++;
        temp = temp->next;
    }
    return NULL;
    // TC = O(n + insertion and find)
    // SC = O(n)
}

/* -------------------------
   Loop Detection (Optimal)
   -------------------------
   Idea: Floyd’s Cycle Detection (Tortoise & Hare)
   If slow == fast => cycle exists.
   TC: O(n)
   SC: O(1)
*/
Node* startLoopOptimal(Node* head){
    // Tortoise & hare  and using length of loop  = L1 + d , where L1 = distance of start from head ,
    // d = distance from fast to slow pointer 
    // step1 = detect Loop 
    // step2 = if found  - slow = head and move both by 1,1 and return the collision point.
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            // d + L1 concept
            slow = head;
            while (slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;// also fast 
            
        }
    }
    return NULL;
    // TC = O(n+)
    // SC = O(1)
}

int main(){
    Node* node1 =new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    // bool hasLoop = detectLoopOptimal(node1);
    // cout << "List has loop : " << hasLoop <<endl;
    // Cycle
    node5->next = node3;
    Node* startLoop = startLoopOptimal(node1);
    cout << "List loop starting point is : " << startLoop->data<<", with address : "<<startLoop<<endl;
    return 0;
}