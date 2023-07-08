/*
Link:https://leetcode.com/problems/diameter-of-binary-tree/

543. Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root. The length of a path between two nodes is represented by the number of edges between them.



Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
*/

#include <bits/stdc++.h>
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
int height(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);
    maxi = max(lh + rh, maxi);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int dm = 0;
    height(root, dm);
    return dm;
}
