#include<bits/stdc++.h>
using namespace std;
// Reverse stack using recursion is easy
void push_bottom(stack<int>& s,int el){
    if(s.empty()){
        s.push(el);
        return;
    }

    int popped = s.top();
    s.pop();
    push_bottom(s,el);
    s.push(popped);
}


void reverseStack(stack<int>& s){
    if(s.empty()) {
        cout << "\n";
        return;
    }

    int val = s.top();
    s.pop();
    reverseStack(s);
    push_bottom(s,val);
    // TC = O(n*n)
    // SC = O(n)
}

// Iterative
void reverseStackIterative(stack<int>& s){
    vector<int> arr;
    while (!s.empty())
    {
        arr.push_back(s.top());
        s.pop();
    }
    
    for(int i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
    }
    // TC = O(n)
    // SC = O(n)
}

void printStack(stack<int> s){
    while(!s.empty())
    {
        cout<<s.top() << " ";
        s.pop();
    }
    cout << "\n";
}


int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    printStack(s);
    reverseStackIterative(s);
    printStack(s);
    return 0;
}