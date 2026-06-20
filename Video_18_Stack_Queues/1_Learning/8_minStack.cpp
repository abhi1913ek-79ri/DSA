#include<bits/stdc++.h>
using namespace std;
// Implementation of minStack
// Operations in constant time: push, pop, top, and retrieving the minimum element.
// Brute Force Using Space (2*N)
class MinStack{
    private:
        stack<int> st;
        stack<int> minS;
    public:
        MinStack(){
            minS.push(INT_MAX);
        }

        void push(int data){
            if(minS.top()>=data) minS.push(data);
            st.push(data);
        }

        void pop(){
            if(st.empty()){
                cout << "Stack is empty" << endl;
                return;
            }
            int removed = st.top();
            if(minS.top() == removed) minS.pop();
            st.pop();
            // TC = O(1) 
        }

        int top(){
            if(st.empty()){
                cout << "Stack is empty" << endl;
                return INT_MIN;
            }
            return st.top();
        }

        int getMin(){
            if(st.empty()){
                cout << "Stack is empty" << endl;
                return INT_MIN;
            }
            return minS.top();
        }
};


// Using space O(2N)
// using pair

class MinStack1{
    private:
        stack<pair<int,int>> st;
    public:
        MinStack1(){
            
        }

        void push(int data){
            if(st.empty()){
                st.push({data,data});
                return;
            }
            if(st.top().second > data){
                st.push({data,data});
            }else{
                st.push({data,st.top().second});
            }
        }

        void pop(){
            if(st.empty()){
                cout << "Stack is empty" << endl;
                return;
            }
            st.pop();
        }

        int top(){
            if(st.empty()){
                cout << "Stack is empty" << endl;
                return INT_MIN;
            }

            return st.top().first;
        }

        int getMin(){
            if(st.empty()){
                cout << "Stack is empty" << endl;
                return INT_MIN;
            }

            return st.top().second;
        }

        bool isEmpty(){
            return st.empty();
        }

        // TC = O(1)
        // SC = O(2N)
};


// Using space of O(n) only
// idea when minimum is modified store modified value in stack and minimum in minni
class MinStack2{
    private:
        stack<int> st;
        int minni;
    public:
        MinStack2(){};

        void push(int data){
            if(st.empty()){
                st.push(data);
                minni = data;
                return;
            }
            if(data<minni){
                st.push(2*data-minni); // Modified vale 2*val- min = newVal
                minni = data;
            }else{
                st.push(data);
            }
        }

        void pop(){
            if(st.empty()){
                cout << "Stack underflow" << endl;
                return;
            }
            if(st.top()<minni){
                minni = 2*minni - st.top();
            }
            st.pop();
        }

        int top(){
            if(st.empty()){
                cout << "Stack empty" << endl;
                return INT_MIN;
            }
            if(st.top() < minni){
                return minni;
            }
            return st.top();
        }

        int getMin(){
            if(st.empty()){
                cout << "Stack empty" << endl;
                return INT_MIN;
            }

            return minni;
        }

        bool isEmpty(){
            return st.empty();
        }

        // TC = O(1)
        // SC = O(1)
        // using modified value to store when minni is modified to store hsjtory chnage the configuration
};


int main(){
    MinStack2 st;
    st.push(1); // min = 1
    st.push(0); // min = 0
    st.push(10); // min = 0
    st.push(2); // min = 0;
    cout << st.top() << " and " << st.getMin() << endl; // 
    st.pop(); // min = 0
    cout << st.top() << " and " << st.getMin() << endl; // 
    st.pop();
    cout << st.top() << " and " << st.getMin() << endl; //
    st.pop();
    cout << st.top() << " and " << st.getMin() << endl; // 
    st.pop();
    cout << st.top() << " and " << st.getMin() << endl; // 
    return 0;
}


// | Class                 | Status                | Notes             |
// | --------------------- | --------------------- | ----------------- |
// | `MinStack` (2 stacks) | ✅ Correct             | Standard solution |
// | `MinStack1` (pair)    | ✅ Correct             | Clean & better    |
// | `MinStack2` (1 stack) | ✅ Correct (after fix) | ⭐ Best            |
