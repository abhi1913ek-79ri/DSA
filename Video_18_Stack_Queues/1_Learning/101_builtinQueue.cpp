#include<bits/stdc++.h>
using namespace std;
// Queue 
// GOLDEN RULE
// 👉 Always check before access/remove
// if(!container.empty())

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    q.pop();

    if(!q.empty()){
        cout << "front : " << q.front() << " back : " << q.back() << endl;
    } else {
        cout << "Queue is empty" << endl;
    }
    return 0;
}