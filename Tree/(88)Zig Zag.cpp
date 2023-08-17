
/*
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Problem: 103. Binary Tree Zigzag Level Order Traversal
Level: Medium

Companies: Amazon | Facebook | Microsoft | Bloomberg | Google | Apple | LinkedIn | Oracle | Adobe  
Statement: Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> lvl(sz);
        TreeNode *tmp;
        for (int i = 0; i < sz; i++)
        {
            tmp = q.front();
            q.pop();
            int idx = flag ? i : sz - i - 1;
            lvl[idx] = tmp->val;
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        flag = !flag;
        res.push_back(move(lvl));
    }
    return res;
}