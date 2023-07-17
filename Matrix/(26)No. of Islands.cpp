/*
Link: https://leetcode.com/problems/number-of-islands/
https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

Problem: Number of Islands
Statement:
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0
There are two islands :- one is colored in blue
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500

Company Tags:
Paytm
Flipkart
Amazon
Microsoft
OYO Rooms
Samsung
Snapdeal
Citrix
D-E-Shaw
MakeMyTrip
Ola Cabs
Visa
Intuit
Google
Linkedin
Opera
One97
Streamoid Technologies
Informatica

*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    int m = grid.size(), n = grid[0].size();
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for (int dR = -1; dR <= 1; dR++)
        {
            for (int dC = -1; dC <= 1; dC++)
            {
                int nR = r + dR, nC = c + dC;

                if ((nR >= 0 && nR < m) && (nC >= 0 && nC < n) && vis[nR][nC] != 1 && grid[nR][nC] == '1')
                {
                    vis[nR][nC] = 1;
                    q.push({nR, nC});
                }
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int m = grid.size(), n = grid[0].size(), cnt = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == '1' && !vis[r][c])
            {
                cnt++;
                bfs(r, c, grid, vis);
            }
        }
    }
    return cnt;
}
