/*
Link: https://leetcode.com/problems/rotting-oranges/
https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/
Problem: Rotting Oranges
Statement: In a given grid, each cell can have one of three values:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.


Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and
(2,1) in unit time.

Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).


Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)


Constraints:
1 ≤ n, m ≤ 500


*/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int vis[m][n];
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                vis[i][j] = 2;
                q.push({{i, j}, 0});
            }
            else
                vis[i][j] = 0;
        }
    }
    int tm = 0;
    int dR[] = {-1, 0, 1, 0};
    int dC[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm = max(t, tm);
        for (int i = 0; i < 4; i++)
        {
            int nR = r + dR[i];
            int nC = c + dC[i];
            if (
                (nR >= 0 && nR < m) &&
                (nC >= 0 && nC < n) &&
                vis[nR][nC] != 2 &&
                grid[nR][nC] == 1)
            {
                q.push({{nR, nC}, t + 1});
                vis[nR][nC] = 2;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] != 2 && grid[i][j] == 1)
                return -1;
        }
    }
    return tm;

}