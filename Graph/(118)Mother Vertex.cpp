/*
Link:
Problem: Mother Vertex
Level: Medium
Statement: Given a Directed Graph, find a Mother Vertex in the Graph (if present).
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

Example 1:

Input:

Output: 0
Explanation: According to the given edges, all
nodes can be reached from nodes from 0, 1 and 2.
But, since 0 is minimum among 0,1 and 2, so 0
is the output.
Example 2:

Input:

Output: -1
Explanation: According to the given edges,
no vertices are there from where we can
reach all vertices. So, output is -1.
Your Task:
You don't need to read or print anything. Your task is to complete the function findMotherVertex() which takes V denoting the number of vertices and adjacency list as input parameter and returns the vertices from through which we can traverse all other vertices of the graph. If there is more than one possible nodes then return the node with minimum value. If not possible returns -1.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V ≤ 10^5


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = true;
        for (auto i : adj[node])
            if (!vis[i])
                dfs(i, adj, vis);
    }
    int findMotherVertex(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        int last = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                last = i;
            }
        }
        fill(vis.begin(), vis.end(), false);
        dfs(last, adj, vis);
        for (int i = 0; i < V; i++)
            if (!vis[i])
                return -1;
        
        return last;
    }
};
