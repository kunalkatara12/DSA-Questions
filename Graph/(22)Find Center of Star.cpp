/*
Link: https://leetcode.com/problems/find-center-of-star-graph/
Problem: 1791. Find Center of Star Graph
Statement: There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node. You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

Example 1:
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1


Constraints:

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.

*/

#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>> &e)
{
    // O(n) solution
    /*
    int n=edges.size();
    // Make adjacency list of size n+2
    vector<vector<int>> adj(n+2);
    for(int i=0;i<n;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    // if any node has degree n then it is the center
    for(int i=1;i<=n+1;i++)
    {
        if(adj[i].size()==n)return i;
    }
    return -1;
    */

    // O(1) solution
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}