/*
Link:
Problem:  Left View of Binary Tree

Easy
Statement:

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

       1
     /   \
    2     3
   / \   / \
  4   5 6    7
   \
    8

Example 1:

Input:
  1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000



*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void recur(vector<int> &res, Node *root, int l)
{
    if (!root)
        return;
    if (l == res.size())
        res.push_back(root->data);
    if (root->left)
        recur(res, root->left, l + 1);
    if (root->right)
        recur(res, root->right, l + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> res;

    recur(res, root, 0);
    return res;
}