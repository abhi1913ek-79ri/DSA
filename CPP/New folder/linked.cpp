#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int pos = 1;
    ListNode *prev = NULL;
    ListNode *current = head;
    while (pos<n && current->next!=NULL){
        prev=current;
        current=current->next;
        pos++;
    }
    if(pos==n&&current->next!=NULL){
        prev=current->next;
        current->next=NULL;
    }else{
        prev=NULL;
    }
    return head;
}

int main()
{

    return 0;
}