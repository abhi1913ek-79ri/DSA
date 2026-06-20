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

/* -------------------------
   Length of Loop (Naive)
   -------------------------
   Idea: Use hashing to store the time (index) when a node
   is first visited. If visited again → loop length = difference.
   TC: O(n) average
   SC: O(n)
*/
int lengthLoopNaive(Node* head){
    // hashing Concept
    unordered_map<Node*, int> mpp;
    Node* temp = head;
    int timer = 0;
    while (temp!=NULL)
    {
        if(mpp.find(temp) != mpp.end()){
            return timer - mpp[temp];
        }
        mpp[temp]=timer;
        timer++;
        temp = temp->next;
    }
    return 0;
    // TC = O(n + insertion + find)
    // SC = O(n) 
}


/* -------------------------
   Helper: Count length of cycle
   -------------------------
*/
int findLength(Node* slow,Node* fast){
    int count = 1;
    fast = fast->next;
    while(slow!=fast){
        fast = fast->next;
        count++;
    }
    return count;
}

/* -------------------------
   Length of Loop (Optimal)
   -------------------------
   Idea: Floyd’s Cycle Detection.
   Step 1: Detect cycle using slow & fast.
   Step 2: If found, call findLength().
   TC: O(n)
   SC: O(1)
*/
int lengthLoopOptimal(Node* head){
    // Tortoise & Hare Algorithm
    // using find length after detection
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return findLength(slow,fast);
        }
    }
    return 0;
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
    node5->next = node2;
    int lengthLoop= lengthLoopOptimal(node1);
    cout << "List length of loop is : " << lengthLoop<<endl;
    return 0;
}