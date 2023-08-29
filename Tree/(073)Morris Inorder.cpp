/*
Link:  https://leetcode.com/problems/binary-tree-inorder-traversal/
Problem: Binary Tree Inorder Traversal
Level: Medium
Company Tags: Microsoft | Amazon | Apple | Adobe

Statement: Given the root of a binary tree, return the inorder traversal of its nodes' values.



Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?
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
// Recursive Solution

void recur(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    recur(root->left, res);
    res.push_back(root->val);
    recur(root->right, res);
}
vector<int> inorderTraversalRecursive(TreeNode *root)
{
    vector<int> res;
    recur(root, res);
    return res;
}

vector<int> inorderTraversalIterative(TreeNode *root)
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
                root = root->left;
            }
            else
            {
                prev->right = NULL;
                res.push_back(root->val);
                root = root->right;
            }
        }
    }
    return res;
}