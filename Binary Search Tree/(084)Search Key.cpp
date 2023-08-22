/*
Link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/
Problem:  Search in a binary Tree
Level: Easy
Statement: You are given the root of a binary search tree (BST) and an integer val. Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.


Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []


Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 10^7
root is a binary search tree.
1 <= val <= 10^7
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive
TreeNode *searchBSTRecursive(TreeNode *root, int val)
{
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    root = (val < root->val)? searchBSTRecursive(root->left, val): searchBSTRecursive(root->right, val);

    return root; 
}
// Iterative
TreeNode *searchBSTIterative(TreeNode *root, int val)
{
    if(root == NULL) return NULL;

    while (root != NULL && root->val != val)
        root = (root->val > val) ? root->left : root->right;

    return root;
}