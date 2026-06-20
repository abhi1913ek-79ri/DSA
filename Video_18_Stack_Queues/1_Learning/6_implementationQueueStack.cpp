#include<bits/stdc++.h>
using namespace std;
// Implementation of queue using stack
// Using  two stacks
class QueueStack{
    private:
        stack<int> st;
    public:
        void push(int data){
            stack<int> temp;
            while (!st.empty())
            {
                temp.push(st.top()); 
                st.pop();
            }

            // push new element
            st.push(data);

            while (!temp.empty())
            {
                st.push(temp.top());
                temp.pop();
            }
            
            // TC = O(n+n)
            // SC = O(n) - Tempstack
        }

        int pop(){
            if(st.size()==0) return -1;
            int removed = st.top();
            st.pop();
            return removed;
            // TC = O(1)
        }

        int peek(){
            if(st.size()==0) return -1;
            return st.top();
            // TC = O(1)
        }
};

int main(){
    QueueStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Top : " << q.peek() << endl;
    q.pop();

    cout << "Top : " << q.peek() << endl;
    q.pop();

    cout << "Top : " << q.peek() << endl;
    q.pop();

    cout << "Top : " << q.peek() << endl;
    q.pop();

    cout << "Top : " << q.peek() << endl;
    q.pop();

    cout << "Top : " << q.peek() << endl;
    q.pop();

    cout << "Top : " << q.peek() << endl;
    q.pop();

    cout << "Top : " << q.peek() << endl;
    q.pop();

    return 0;
}

// Approach 2
// stack1 for push
// stack2 for pop/top
// class QueueStack{
// private:
//     stack<int> s1, s2;

// public:
//     void push(int x){
//         s1.push(x);   // O(1)
//     }

//     int pop(){
//         if(s1.empty() && s2.empty()){
//             cout << "Queue is empty\n";
//             return -1;
//         }

//         if(s2.empty()){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }

//         int val = s2.top();
//         s2.pop();
//         return val;
//     }

//     int peek(){
//         if(s1.empty() && s2.empty()){
//             cout << "Queue is empty\n";
//             return -1;
//         }

//         if(s2.empty()){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }

//         return s2.top();
//     }

//     bool isEmpty(){
//         return s1.empty() && s2.empty();
//     }
// };