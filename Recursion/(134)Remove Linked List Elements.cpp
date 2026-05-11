/*
Link: https://leetcode.com/problems/remove-linked-list-elements/
Problem: Remove Linked List Elements
Difficulty: Easy

Statement:Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []


Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50

Approach:

Time Complexity: O(n)
Space Complexity: O(n)
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
class Solution
{
public:
    void recur(ListNode *head, int val)
    {
        if (!head)
            return;
        if (head->next && head->next->val == val)
        {
            head->next = head->next->next;
            recur(head, val);
        }
        else
        {
            recur(head->next, val);
        }
    }
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }
        if (!head)
            return nullptr;
        ListNode *tmp = head;
        recur(tmp, val);
        return head;
    }
};
