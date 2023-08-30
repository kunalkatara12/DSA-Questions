
/*
Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
Problem: Construct Binary Search Tree from Preorder Traversal
Level: Medium
Company Tags: Amazon | Microsoft | Facebook | Bloomberg
Statement: Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.



Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]


Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.
*/
#include <bits/stdc++.h>

using namespace std; 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 TreeNode *bstFromPreorder(vector<int> &v)
 {
     if (v.empty())
         return nullptr;

     TreeNode *root = new TreeNode(v[0]);
     stack<TreeNode *> nodes;
     nodes.push(root);

     for (int i = 1; i < v.size(); ++i)
     {
         TreeNode *node = nullptr;

         while (nodes.size() && v[i] > nodes.top()->val)
         {
             // !nodes.empty(): This condition ensures that we don't pop from an empty stack. If the stack is empty, we should stop the loop because there are no more potential parent nodes to compare with.

             // v[i] > nodes.top()->val: This condition checks whether the current element v[i] is greater than the value of the top node in the nodes stack. If this condition is true, it means that the current element should be a right child of the top node in the stack (since it's greater than the top node's value).

             node = nodes.top();
             nodes.pop();
         }
         // it helps us find the correct parent node in the binary search tree (BST) for the current element being processed from the preorder sequence.

         // After this loop, the variable node will either point to the correct parent node for the current element (which is its left child), or it will be nullptr, indicating that the current element should be the left child of the top node in the stack.
         TreeNode *tmp = new TreeNode(v[i]);
         if (node)
             node->right = tmp;
         else
         {
             node = nodes.top();
             node->left = tmp;
         }
         nodes.push(tmp);
     }

     return root;
 }
