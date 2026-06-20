#include<bits/stdc++.h>
using namespace std;
// Implement Stack using Array

// Problem Statement: Implement a Last-In-First-Out (LIFO) stack using an array.
// The implemented stack should support the following operations: 
// push, pop, peek, and isEmpty.

// Implement the ArrayStack class:

// void push(int x): Pushes element x onto the stack.
// int pop(): Removes and returns the top element of the stack.
// int top(): Returns the top element of the stack without removing it.
// boolean isEmpty(): Returns true if the stack is empty, false otherwise.

class ArrayStack{
private:
    int *st;
    int topIdx;
    int capacity;
public:
    ArrayStack(int size = 5){
        capacity = size;
        st = new int[capacity];
        topIdx = -1; // Empty
    }

    void push(int a){
        if(topIdx==capacity-1){
            cout <<"Stack overflow"<<endl;
            return;
        }
        topIdx++;
        st[topIdx] = a;
    }

    int pop(){
        if(topIdx==-1){
            cout <<"Stack underflow"<<endl;
            return -1;
        }

        return st[topIdx--];
    }

    int top(){
        if(topIdx==-1){
            cout <<"Stack is Empty"<<endl;
            return -1; // empty
        }
        return st[topIdx];
    }

    bool isEmpty(){
        return topIdx == -1;
    }

    int size(){
        return topIdx + 1;
    }

    ~ArrayStack(){
        delete[] st;
    }

    // ALL functions 
    // TC = O(1)
    // SC = O(capacity)
    // --- Disadvanteges
    // Constant size
};

int main(){
    ArrayStack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    st.push(11);




    cout << "Top :" << st.top() << endl;
    st.pop();
    cout << "Top :" << st.top() << endl;
    st.pop();

    cout << "Top :" << st.top() << endl;
    st.pop();

    cout << "Top :" << st.top() << endl;
    st.pop();

    cout << "Top :" << st.top() << endl;
    
    st.pop();
    
    return 0;
}