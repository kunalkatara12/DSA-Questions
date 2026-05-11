/*
Link: https://leetcode-cn.com/problems/merge-two-sorted-lists/
Problem: Merge Two Sorted Lists
Level: Easy
Company Tags: Amazon, Microsoft, Bloomberg, Uber, Facebook, Adobe, Oracle, Shopee, Accenture

Statement: You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.



Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    ListNode *tmp1 = list1, *tmp2 = list2;
    ListNode *newNode = new ListNode();
    ListNode *headN = newNode;
    while (tmp1 && tmp2)
    {
        if (tmp2->val <= tmp1->val)
        {
            headN->next = tmp2;
            tmp2 = tmp2->next;
        }
        else
        {
            headN->next = tmp1;
            tmp1 = tmp1->next;
        }

        headN = headN->next;
    }
    headN->next = tmp1 ? tmp1 : tmp2;
    return newNode->next;
}

/*
dummy node approach:

A dummy node is a temporary starting node created before the actual merged list.
It helps us avoid handling the first node separately.

How it works here:
1. Create a dummy node.
2. Keep a pointer `tail` at dummy.
3. Compare nodes of list1 and list2.
4. Attach the smaller node to `tail->next`.
5. Move `tail` forward.
6. After one list ends, attach the remaining part of the other list.
7. Return `dummy.next` because dummy itself is not part of the answer.

Example:
dummy -> 1 -> 1 -> 2 -> 3 -> 4

Here, dummy is only a helper node.
Actual merged list starts from dummy.next.
*/

ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy.next;
}
