/*
Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

Problem: 662. Maximum Width of Binary Tree
Medium
Company Tags: 
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).


Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int sz = q.size(), mn = q.front().second, frst, lst;
        for (int i = 0; i < sz; i++)
        {
            int current_id = q.front().second - mn;
            TreeNode *temp = q.front().first;
            q.pop();
            if (i == 0)
                frst = current_id;
            if (i == sz - 1)
                lst = current_id;
            if (temp->left)
                q.push({temp->left, 2LL * current_id + 1});
            if (temp->right)
                q.push({temp->right, 2LL * current_id + 2});
        }
        ans = max(ans, lst - frst + 1);
    }
    return ans;
}
