/*
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
19. Remove Nth Node From End of List
Medium
Company Tags: Facebook | Amazon | Microsoft | Google | Bloomberg | Walmart Global Tech | Apple | Uber
Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

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

ListNode *removeNthFromEnd(ListNode *head, int k)
{
    ListNode *size = head, *tmp = head;
    int n = 0;
    while (size)
    {
        n++;
        size = size->next;
    }
    if (k == n)
    {
        head = head->next;
        return head;
    }
    int kNew = n - k - 1;

    while (kNew > 0)
    {
        tmp = tmp->next;
        kNew--;
    }
    if (tmp->next)
        tmp->next = tmp->next->next;
    else
        head = NULL;
    return head;
}