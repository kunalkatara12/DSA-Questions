/*
Link:https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0
Problem: Shortest path in an unweighted graph
Level: Medium

Statement: The city of Ninjaland is analogous to the unweighted graph. The city has 'N' houses numbered from 1 to 'N' respectively and are connected by M bidirectional roads. If a road is connecting two houses 'X' and 'Y' which means you can go from 'X' to 'Y' or 'Y' to 'X'. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.
A path between house 'S' to house 'T' is defined as a sequence of vertices from 'S' to 'T. Where starting house is 'S' and the ending house is 'T' and there is a road connecting two consecutive houses. Basically, the path looks like this: (S, h1, h2, h3, ... T). you have to find the shortest path from 'S' to 'T'.
For Example
In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go from 5=1 to T=8 via (1, 2, 5, 8) or (1, 4, 6, 7, 8) but these paths are not shortest.

Example:
Sample Input 1 :
1
4 4
1 4
1 2
2 3
3 4
1 3
Sample Output 1 :
( 1 , 3 , 4 )
Explanation Of Sample Input 1 :
In the above graph there are two ways to go from 1 to 4 ,
( 1 , 2 , 3 , 4 ) and ( 1 , 3 , 4 ) but the second path is the shortest path.

Sample Input 2 :
1
8 9
1 8
1 2
1 3
1 4
2 5
5 8
3 8
4 6
6 7
7 8
Sample Output 2 :
( 1 , 3 , 8 )
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    vector<vector<int>> adj(n + 1);
    for (auto i : edges)
    {
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto nbr : adj[front])
        {
            if (dist[nbr] == -1)
            {
                dist[nbr] = dist[front] + 1;
                parent[nbr] = front;
                q.push(nbr);
            }
        }
    }

    vector<int> path;
    int dest = t;

    if (dist[dest] == -1)
        return path;

    while (dest != -1)
    {
        path.push_back(dest);
        dest = parent[dest];
    }

    reverse(path.begin(), path.end());

    return path;
}