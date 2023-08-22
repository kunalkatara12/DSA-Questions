/*
Link: https://leetcode.com/problems/unique-paths/
Problem: 62. Unique Paths
Medium

Companies:
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time. Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3

Example 3:
Input: m = 19, n = 13
Output: 86493225

Constraints:
1 <= m, n <= 200
It's guaranteed that the answer will be less than or equal to 2 * 10^9.

*/
#include <bits/stdc++.h>
using namespace std;

int uniquePathsTabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    return dp[m - 1][n - 1];
}
int cntPath(int m, int n, vector<vector<int>> &dp, int i, int j)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i > m - 1 || j > n - 1)
        return 0;
    if (dp[i][j] != 0)
        return dp[i][j];
    return dp[i][j] = cntPath(m, n, dp, i + 1, j) + cntPath(m, n, dp, i, j + 1);
}
int uniquePathsDPrecursion(int m, int n)
{
    int i = 0, j = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    return cntPath(m, n, dp, i, j);
}

int uniquePathsCombinatorics(int m, int n)
{
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}