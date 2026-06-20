#include<bits/stdc++.h>
using namespace std;
// Implementation of queue using array
// Circular queue concept used 
// Becoz start goes to end 
// queue get treamed after every pop operation
class QueueArray{
private:
    int* q;
    int frontIdx;
    int backIdx;
    int capacity;
    int currSize;

public:
    // constructor
    QueueArray(int size = 10){
        capacity = size;
        q = new int[capacity];
        frontIdx = -1;
        backIdx = -1;
        currSize = 0;
    }

    

    // push or enqueue
    void enqueue(int a){
        if(currSize == capacity){
            cout << "Queue Overflow" << endl;
            return;
        }

        if(currSize == 0){
            frontIdx = 0;
            backIdx = 0;
        }else{
            backIdx = (backIdx+1)%capacity;
        }

        q[backIdx] = a;

        currSize++;
    }

    // pop  dequeue
    int dequeue(){
        if(currSize == 0){
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int element = q[frontIdx];

        if(currSize == 1){
            frontIdx = -1;
            backIdx = -1;
        }else{
            frontIdx = (frontIdx+1)%capacity;
        }

        currSize--;

        return element;
    }

    bool isEmpty(){
        return currSize==0;
    }

    int size(){
        return currSize;
    }

    int front(){
        if(currSize==0) return -1;
        return q[frontIdx];
    }

    int back(){
        if(currSize==0) return -1;
        return q[backIdx];
    }
};

int main(){
    QueueArray q(5);
    q.enqueue(1); // front
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5); // back

    cout << "Front : " << q.front() << " back : " << q.back() << endl;
    q.dequeue();

    cout << "Front : " << q.front() << " back : " << q.back() << endl;
    q.dequeue();

    cout << "Front : " << q.front() << " back : " << q.back() << endl;
    q.dequeue();

    cout << "Front : " << q.front() << " back : " << q.back() << endl;
    q.dequeue();

    cout << "Front : " << q.front() << " back : " << q.back() << endl;
    q.dequeue();

    cout << "Front : " << q.front() << " back : " << q.back() << endl;
    q.dequeue();

    cout << "Front : " << q.front() << " back : " << q.back() << endl;
    q.dequeue();



    return 0;
}