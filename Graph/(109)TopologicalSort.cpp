/*
Link: https://practice.geeksforgeeks.org/problems/topological-sort/1
Problem: Topological Sort
Level: Medium
Statement: Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2

Company Tags: Moonfrog Labs | Flipkart | Morgan Stanley | Accolite | Amazon | Microsoft | OYO Rooms | Samsung | D-E-Shaw | Visa
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSortBFSKahnsAlgo(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0), ans;
        queue<int> q;
        for (int i = 0; i < V; i++)
            for (auto j : adj[i])
                indegree[j]++;

        for (int i = 0; i < indegree.size(); i++)
            if (!indegree[i])
                q.push(i);

        while (q.size())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto nbr : adj[front])
            {
                indegree[nbr]--;
                if (!indegree[nbr])
                    q.push(nbr);
            }
        }
        return ans;
    }
    void helper(int node, vector<int> adj[], stack<int> &st, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto i : adj[node])
            if (!vis[i])
                helper(i, adj, st, vis);

        st.push(node);
    }
    vector<int> topoSortDFS(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), ans;
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                helper(i, adj, st, vis);
        }
        while (st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};