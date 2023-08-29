/*
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

Problem: Binary Tree Preorder Traversal
Level: Medium

Statement: Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1: 
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;

    while (root != NULL)
    {
        if (root->left == NULL)
        {
            res.push_back(root->val);
            root = root->right;
        }
        else
        {
            TreeNode *prev = root->left;
            while (prev->right && prev->right != root)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = root;
                res.push_back(root->val);
                root = root->left;
            }
            else
            {
                prev->right = NULL;
                root = root->right;
            }
        }
    }
    return res;
}
