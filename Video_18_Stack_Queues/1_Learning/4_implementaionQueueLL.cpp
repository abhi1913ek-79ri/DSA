#include<bits/stdc++.h>
using namespace std;
// Implementation of queue using LL
struct Node{
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

class queueLL{
    private:
        Node* front;
        Node* back;
        int size; 
    public:
        queueLL(){
            front = NULL;
            back = NULL;
            size = 0;
        }

        void enqueue(int data){
            Node* newNode = new Node(data);
            if(size == 0){
                front = newNode;
                back = newNode;
            }else{
                back->next = newNode;
                back = newNode;
            }
            size++;
        }

        int dequeue(){
            if(size == 0){
                cout << "Queue underflow" << endl;
                return -1;
            }
            if(size == 1){
                Node* temp = front;
                int removed = temp->val;
                front = NULL;
                back = NULL;
                delete temp;
                size--;
                return removed;
            }

            Node* temp = front;
            int removed = temp->val;
            front = front->next;
            delete temp;
            size--;
            return removed;
        }

        bool isEmpty(){
            return size == 0;
        }

        int start(){
            if(size==0){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return front->val;
        }

        int end(){
            if(size==0){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return back->val;
        }

        ~queueLL(){
            while(front != NULL){
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        // TC = O(1)
        // SC = O(n)    
        }
};

int main(){
    queueLL q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "front : " << q.start() << " back : " << q.end() << endl;
    q.dequeue();
    q.enqueue(6);

    cout << "front : " << q.start() << " back : " << q.end() << endl;
    q.dequeue();

    cout << "front : " << q.start() << " back : " << q.end() << endl;
    q.dequeue();

    cout << "front : " << q.start() << " back : " << q.end() << endl;
    q.dequeue();
    cout << "front : " << q.start() << " back : " << q.end() << endl;
    q.dequeue();

    cout << "front : " << q.start() << " back : " << q.end() << endl;
    q.dequeue();

    cout << "front : " << q.start() << " back : " << q.end() << endl;
    q.dequeue();

    cout << "front : " << q.start() << " back : " << q.end() << endl;
    q.dequeue();

    return 0;
}