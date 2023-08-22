/*
Link: https://leetcode-cn.com/problems/reverse-linked-list/

Problem:
    Reverse a singly linked list.

    Example:
        Input: 1->2->3->4->5->NULL
        Output: 5->4->3->2->1->NULL

    Follow up:
        A linked list can be reversed either iteratively or recursively. Could you implement both?

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Iterative
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }


};

// Solution 2: Recursive

class Solution_2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};