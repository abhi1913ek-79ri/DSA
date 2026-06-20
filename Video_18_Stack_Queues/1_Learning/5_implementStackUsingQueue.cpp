#include<bits/stdc++.h>
using namespace std;
// Implementation of stack using queue
// intiution
//  after push reverse the order 
// [1,2,3]
// push(4)
// [1,2,3,4]
// rearrange:
// [4,1,2,3]
class stackQueue{
    private:
        queue<int> q;
    public:
        void push(int data){
            if(q.size()==0){
                q.push(data);
                return;
            }
            int size = q.size();
            q.push(data);
            for(int i=1;i<=size;i++){
                q.push(q.front());
                q.pop();
            }
            // TC = O(n)
        }

        int pop(){
            if(q.size()==0) return -1;
            int removed = q.front();
            q.pop();
            return removed;
            // TC = O(1)
        }

        int top(){
            if(q.size()==0) return -1;
            return q.front();
            // TC = O(1)
        }

        bool isEmpty(){
            return q.size() == 0;
            // TC = O(1)
        }
};

int main(){
    stackQueue st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Top : " << st.top() << endl;
    st.pop();

    cout << "Top : " << st.top() << endl;
    st.pop();

    cout << "Top : " << st.top() << endl;
    st.pop();

    cout << "Top : " << st.top() << endl;
    st.pop();

    cout << "Top : " << st.top() << endl;
    st.pop();

    cout << "Top : " << st.top() << endl;
    st.pop();

    cout << "Top : " << st.top() << endl;
    st.pop();

    return 0;
}