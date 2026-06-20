#include<bits/stdc++.h>
using namespace std;
// Implementation Stack
// Using LL
struct Node{
    int val;
    Node* next;
    Node (int data){
        val = data;
        next = NULL;
    }
};

class stackLL{
    private:
        Node* Head;
        int size;
    public:
        // Constructor
        stackLL(){
            Head = NULL;
            size = 0;
        }

        // methods
        void push(int data){
            Node* newNode = new Node(data);
            newNode->next = Head;
            Head = newNode;
            size++;
        }

        int pop(){
            if(size==0){
                cout << "Stack underflow"<<endl;
                return -1;
            }
            Node* temp = Head;
            int removed = temp->val; 
            Head = temp->next;
            delete temp;
            size--;
            return removed;
        }

        bool isEmpty(){
            return size == 0;
        }

        int top(){
            if(size==0){
                cout << "Stack Empty"<<endl;
                return -1;
            }
            return Head->val;
        }

        // Destructor
        ~stackLL(){
            while(Head != NULL){
                Node* temp = Head;
                Head = Head->next;
                delete temp;
            }
        }
        // TC = O(1) -- all operations 
        // SC = O(size) - not constant or capacity dynamically 
};


int main(){
    stackLL st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Top : " << st.top() << endl;
    cout<<"poped element : "<<st.pop()<<endl;
    cout << "Top : " << st.top() << endl;
    cout<<"poped element : "<<st.pop()<<endl;
    cout << "Top : " << st.top() << endl;
    cout<<"poped element : "<<st.pop()<<endl;
    cout << "Top : " << st.top() << endl;
    cout<<"poped element : "<<st.pop()<<endl;
    cout << "Top : " << st.top() << endl;
    cout<<"poped element : "<<st.pop()<<endl;
    return 0;
}