#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
    {
        return list2;
    }

    if (!list2)
    {
        return list1;
    }
    ListNode *dummy = new ListNode(-101);
    ListNode *newList = dummy;
    ListNode *curr1 = list1;
    ListNode *curr2 = list2;
    while (curr1 && curr2)
    {
        if (curr1->val <= curr2->val)
        {
            dummy->next = curr1;
            curr1 = curr1->next;
        }
        else
        {
            dummy->next = curr2;
            curr2 = curr2->next;
        }
        dummy = dummy->next;
    }

    while (curr1)
    {
        dummy->next = curr1;
        dummy = dummy->next;
        curr1 = curr1->next;
    }

    while (curr2)
    {
        dummy->next = curr2;
        dummy = dummy->next;
        curr2 = curr2->next;
    }

    return newList->next;
}


void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // List1: 1 -> 2 -> 4
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // List2: 1 -> 3 -> 4
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    ListNode *merged = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}