/*

Problem: Minimum Spanning Tree using Kruskal's Algorithm
Level: Medium
Statement: Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree. Given  adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.



Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.


Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree() which takes a number of vertices V and an adjacency list adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).


Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.

Company Tags: Flipkart| Amazon| Microsoft| Samsung| Cisco

*/

#include<bits/stdc++.h>
using namespace std;
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}
void mergeNodes(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] > rank[v])
        parent[v] = u;
    else if (rank[u] < rank[v])
        parent[u] = v;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalMST(int n, vector<vector<int>> &adj)
{
    int ans = 0;
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(adj.begin(), adj.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    for (int i = 0; i < adj.size(); i++)
    {
        int u = findParent(parent, adj[i][0]);
        int v = findParent(parent, adj[i][1]);
        int wt = adj[i][2];

        if (u != v)
        {
            mergeNodes(parent, rank, u, v);
            ans += wt;
        }
    }
    return ans;
}
