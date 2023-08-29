/*
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

Problem: Kth largest element in BST
Easy
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2
Output: 4

Example 2:

Input:
       9
        \
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H) where H is max recursion stack of height h at a given time.


Constraints:
1 <= N <= 1000
1 <= K <= N
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
    void helper(vector<int> &v, Node *root)
    {
        if (root)
        {
            helper(v, root->left);
            v.push_back(root->data);
            helper(v, root->right);
        }
    }
    int kthLargest(Node *root, int k)
    {

        vector<int> v;
        helper(v, root);
        reverse(v.begin(), v.end());
        return v[k - 1];
    }