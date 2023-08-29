/*
Link: https://leetcode.com/problems/binary-tree-paths/

Problem: Binary Tree Paths
Level: Easy
Company Tags: Amazon | Google | Microsoft | Facebook | Bloomberg
Statement: Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Input: root = [1,2,3,null,5]
Output: ["1 2 5","1 3"]
Example 2:

Input: root = [1]
Output: ["1"]
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void leafFind(BinaryTreeNode<int> *root, vector<int> &leaf)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        leaf.push_back(root->data);
        return;
    }

    leafFind(root->left, leaf);
    leafFind(root->right, leaf);
}

bool getPath(BinaryTreeNode<int> *root, int leaf, string &s)
{
    if (!root)
        return false;

    s += to_string(root->data);
    // s+=' ';

    if (root->data == leaf)
        return true;

    if (getPath(root->left, leaf, s) || getPath(root->right, leaf, s))
        return true;

    s.pop_back();
    return false;
}

string path(BinaryTreeNode<int> *root, int leaf)
{
    string s;
    getPath(root, leaf, s);
    return s;
}

void allRootToLeafHelper(BinaryTreeNode<int> *root, string currentPath, vector<string> &result)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        currentPath += to_string(root->data);
        result.push_back(currentPath);
        return;
    }

    currentPath += to_string(root->data) + " ";
    allRootToLeafHelper(root->left, currentPath, result);
    allRootToLeafHelper(root->right, currentPath, result);
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    vector<string> result;
    allRootToLeafHelper(root, "", result);
    return result;
}
