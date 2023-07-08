/*
Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

Problem Title: 1290. Convert Binary Number in a Linked List to Integer

Statement: Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number. Return the decimal value of the number in the linked list. The most significant bit is at the head of the linked list.



Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0


Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(nullptr){}  
    ListNode(int x) : val(x), next(nullptr){} 
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode *head)
{
    if (head == NULL)
        return 0;
    ListNode *tmp = head, *tmp1 = head;
    int ans = 0, size = 0;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    while (tmp1 != NULL)
    {
        if (tmp1->val)
            ans += pow(2, size - 1);
        size--;
        tmp1 = tmp1->next;
    }
    return ans;
}