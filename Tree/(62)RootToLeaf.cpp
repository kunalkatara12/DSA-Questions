#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;

class BinaryTreeNode
{
public:
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
        return NULL;
    // s+=" ";
    s += to_string(root->data);

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
    // s+=to_string(root->data);
    getPath(root, leaf, s);
    return s;
}
vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    vector<int> leaf;
    leafFind(root, leaf);
    vector<string> v;
    for (int i = 0; i < leaf.size(); i++)
    {
        string s = path(root, leaf[i]);
        v.push_back(s);
    }
    return v;
}
void func()
{
    int n;
    cin >> n;

}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }

    return 0;
}