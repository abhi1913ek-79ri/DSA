#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

    ListNode* reverse(ListNode* head, int k)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(k--)
        {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;

        for(int i=0;i<k;i++)
        {
            if(temp==nullptr) return head;
            temp = temp->next;
        }

        ListNode* newHead = reverse(head,k);

        head->next = reverseKGroup(temp,k);

        return newHead;
    }
};
int main()
{

    return 0;
}