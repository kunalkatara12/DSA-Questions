/*
Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
Problem: BFS Traversal of Graph
Statement: Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

Example 1: Input: N = 4, E = 6, adj[] = {{0,1},{0,2},{0,3},{2,3},{1,3},{1,2}} Output: 0 1 2 3 Explanation: 0 is connected to 1 , 2 , 3 1 is connected to 2 , 3 2 is connected to 3 3 is connected to 3 (itself) so 0 1 2 3 will be the BFS traversal from 0.

Example 2: Input: N = 3, E = 4, adj[] = {{0,1},{0,2},{1,2},{2,0}} Output: 0 1 2 Explanation: 0 is connected to 1 , 2 1 is connected to 2 2 is connected to 0 , 1 so 0 1 2 will be the BFS traversal from 0.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> bfs;
    vector<bool> vis(V, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        bfs.push_back(u);
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return bfs;
}