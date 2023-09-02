/*
Link: https://www.codingninjas.com/studio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=3
Problem: Strongly Connected Components
Level: Hard
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.


Sample Input 1:
1
5 6
0 1
1 2
1 4
2 3
3 2
4 0
Sample Output 1:
0 1 4
2 3
Explanation For Sample Input 1:
For the first test case, the graph is shown below. There are two SCCs in the graph, which are enclosed in the boxes as shown in the image below.

Sample Input 2:
2
1 0
4 4
0 1
1 2
2 3
3 1
Sample Output 2:
0
0
1 2 3
Explanation For Sample Input 2:
For the first test case, the graph has 1 node(0) but there are no edges, therefore only 1 SCC exists and that is {0}.

For the second test case, one SCC is {0} and the other is {1, 2, 3}. Therefore the answer is 0, 1 2 3

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V+E).


Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ V-1
Sum of E over all testcases will not exceed 25*106

Company Tags: Amazon | Microsoft | Visa | D-E-Shaw | Accolite | Salesforce 
*/

#include<bits/stdc++.h>
using namespace std;

/* TopSort */
void helper(int node, vector<int> adj[], stack<int> &st, vector<int> &vis)
{
    vis[node] = 1;
    for (auto i : adj[node])
        if (!vis[i])
            helper(i, adj, st, vis);

    st.push(node);
}
void topoSort(int V, vector<int> adj[], stack<int> &st, vector<int> &vis)
{
    for (int i = 0; i < V; i++)
        if (!vis[i])
            helper(i, adj, st, vis);
}
/* TopSort */
/* Transpose */
void transpose(vector<int> trs[], int n, vector<int> adj[], vector<int> &vis)
{
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            trs[it].push_back(i);
        }
    }
}
/* Transpose */

/* DFS */
void dfs(int node, vector<int> &vis, vector<int> trs[], vector<int> &topush)
{
    vis[node] = 1;
    for (auto nbr : trs[node])
        if (!vis[nbr])
            dfs(nbr, vis, trs, topush);

    topush.push_back(node);
}
/* DFS */

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Adjacency List creation
    vector<int> adj[n];
    for (auto it : edges)
        adj[it[0]].push_back(it[1]);

    // 1. Topological Sort using DFS
    vector<int> vis(n, 0);
    stack<int> st;
    topoSort(n, adj, st, vis);

    // 2. Transpose of adjacency List
    vector<int> trs[n];
    transpose(trs, n, adj, vis);

    // 3. DFS in topSort order
    vector<vector<int>> ans;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        vector<int> topush;
        if (!vis[top])
            dfs(top, vis, trs, topush);

        ans.push_back(topush);
    }

    return ans;
}