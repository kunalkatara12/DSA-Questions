/*
Link: https://leetcode.com/problems/minimum-path-sum/
Problem:64. Minimum Path Sum
Level: Medium
Company Tags: Amazon | Microsoft | Google | Goldman Sachs | Oracle | Apple | Uber | Square


Statement: Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion + Memoization
// Time Complexity: 
// Space Complexity:

int recur(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return grid[0][0];
    if (m < 0 || n < 0)
        return 1e9;
    if (dp[m][n] != -1)
        return dp[m][n];
    return dp[m][n] = grid[m][n] + min(recur(grid, m - 1, n, dp), recur(grid, m, n - 1, dp));
}
int minPathSumRM(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return recur(grid, m - 1, n - 1, dp);
}

// Approach 2: Tabulation
// Time Complexity:
// Space Complexity:

int minPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int up = 0, left = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j];
            else
            {

                up = left = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;

                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}