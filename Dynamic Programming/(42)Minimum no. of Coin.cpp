/*
Link: https://leetcode.com/problems/coin-change/
https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
Problem: Minimum No. of Coins Change
Medium
Statement: You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104


*/

#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int a)
{
    int n = coins.size();
    int t[n + 1][a + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 0;

    for (int i = 0; i < a + 1; i++)
    {
        t[0][i] = INT_MAX - 1;
        if (i != 0)
            t[1][i] = (i % coins[0]) == 0 ? i / coins[0] : INT_MAX - 1;
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < a + 1; j++)
            coins[i - 1] <= j ? t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]) : t[i][j] = t[i - 1][j];
    }

    return (t[n][a] == INT_MAX - 1) ? -1 : t[n][a];
}