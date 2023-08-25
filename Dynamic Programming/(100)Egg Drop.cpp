/*
Link: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
Problem: Egg Dropping Puzzle
Level: Medium
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

For more description on this problem see wiki page

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation:
1. Drop the egg from floor 1. If it
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
Example 2:

Input:
N = 2, K = 10
Output: 4
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*(K^2))
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200

Company Tags: VMWare | Amazon | Microsoft | Samsung | D-E-Shaw | Hike | MakeMyTrip | Oracle | Goldman Sachs | MAQ Software | Google | Myntra | nearbuy | Opera | Philips | Service Now | Unisys
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(201, vector<int>(201, -1));
// Solution 1: Recursive+Memoization
// T(n) = O(n^2)
// S(n) = O(n^2)
int eggDropRecMem(int n, int k)
{
    // your code here
    if (k == 0 || k == 1 || n == 1)
        return k;
    int mn = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int low = 0, high = 0;
        if (dp[n - 1][i - 1] != -1)
            low = dp[n - 1][i - 1];
        else
        {
            low = eggDropRecMem(n - 1, i - 1);
            dp[n - 1][i - 1] = low;
        }
        if (dp[n][k - i] != -1)
            high = dp[n][k - i];
        else
        {
            high = eggDropRecMem(n, k - i);
            dp[n][k - i] = high;
        }
        int tmp = 1 + max(low, high);
        mn = min(tmp, mn);
    }
    return dp[n][k] = mn;
}


// Solution 2: Tabulation
// T(n) = O(n^2)
// S(n) = O(n^2)

int eggDropTabulation(int n, int k)
{
    // Create a 2D table to store results
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base cases: If there's only one egg or one floor
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for (int j = 1; j <= k; j++)
        dp[1][j] = j;

    // Filling the table using bottom-up approach
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                int tmp = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                dp[i][j] = min(dp[i][j], tmp);
            }
        }
    }

    return dp[n][k];
}
