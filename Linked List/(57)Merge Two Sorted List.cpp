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
 if(tmp1) headN->next = tmp2;
 else headN->next = tmp1;
    return newNode->next;
}