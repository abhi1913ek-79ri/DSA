#include<bits/stdc++.h>
using namespace std;


// sort a stack using recursion
// strategy 
// 1. base case - stack has one elemet is sorted and empty stack is also sorted
// 2. what work we have to do :
//      every time  i.   pop
//                  ii.  sort remaining part 
//                  iii. insert poped elemnt to its right position
//   sorting and insertion should be recusive work


void insertStack(stack<int>& s,int popped){
    if(s.empty() || s.top() <= popped){
        s.push(popped);
        return;
    }

    int val = s.top();
    s.pop();
    insertStack(s,popped);
    s.push(val);
}

void sortStack(stack<int>& s){
    // base case
    if(s.empty()){
        return;
    }
    int val = s.top();
    s.pop();
    sortStack(s);
    insertStack(s,val);
    // TC  = O(n*n)
    // SC = O(n)
}


// Iterative version of sort Stack
void sortStackIterative(stack<int>& s){
    stack<int> helpStack;

    while (!s.empty())
    {
        int popped  = s.top();
        s.pop();

        while (!helpStack.empty() && helpStack.top() < popped)
        {
            s.push(helpStack.top()); // do bara se stack me dal de re hain 

            helpStack.pop(); // pop karte ja re hain 
        }
        helpStack.push(popped);
    }
    
    while (!helpStack.empty())
    {
        s.push(helpStack.top());
        helpStack.pop();
    }
    
}




int main(){
    stack<int> s;
    s.push(1);
    s.push(4);
    s.push(3);
    sortStackIterative(s);
    while(!s.empty()){
        cout << s.top() <<" ";
        s.pop();
    }
    return 0;
}