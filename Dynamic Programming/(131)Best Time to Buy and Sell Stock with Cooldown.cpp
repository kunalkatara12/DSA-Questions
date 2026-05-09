/*
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
Problem: Best Time to Buy and Sell Stock with Cooldown
Difficulty: Medium

Statement: You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


Constraints:

1 <= prices.length <= 5000,
0 <= prices[i] <= 1000,

Approach:
This problem is a classic dynamic programming problem with states that depend on previous actions. We can solve it by building up from simpler approaches.

**1. Recursive Approach**

Let's define a function `solve(index, can_buy)` which returns the maximum profit from `index` to the end.
- `index`: The current day.
- `can_buy`: A boolean indicating if we are allowed to buy (true) or if we are holding a stock and must sell (false).

- **Base Case:** If `index >= prices.size()`, we are past the last day, so profit is 0.
- **If `can_buy` is true:**
    - We can either buy the stock: `-prices[index] + solve(index + 1, false)`.
    - Or we can rest: `0 + solve(index + 1, true)`.
    - We take the maximum of these two.
- **If `can_buy` is false:**
    - We can sell the stock: `prices[index] + solve(index + 2, true)`. Note the `index + 2` due to the one-day cooldown.
    - Or we can hold the stock: `0 + solve(index + 1, false)`.
    - We take the maximum of these two.

The initial call is `solve(0, true)`. This approach has exponential time complexity due to overlapping subproblems.

**2. Memoization (Top-Down DP)**

We can optimize the recursion by storing the results of subproblems in a 2D array `dp[n][2]`. This reduces the time complexity to O(n) with O(n) space for the DP table.

**3. Tabulation (Bottom-Up DP)**

We can convert the memoized solution into an iterative one.
- Create a `dp[n+2][2]` table, initialized to 0. `n+2` handles the `index+2` jump safely.
- We iterate backwards from `index = n-1` to `0`.
- The transitions are the same as in the recursive approach. The final answer is `dp[0][1]`. This is also O(n) time and O(n) space.

**4. Space-Optimized DP (O(1) Space)**

In the tabulation approach, we only need values from `index+1` and `index+2`. This suggests we can optimize the space to O(1). A more intuitive way to think about the O(1) space solution is to model the states as we iterate forward:
- `buy`: The maximum profit if we end the day **holding** a stock.
- `sell`: The maximum profit if we end the day **not holding** a stock.
- `prev_sell`: The `sell` profit from the previous day. This is needed to calculate the `buy` state for the current day, enforcing the cooldown.

On day `i`, the transitions are:
- To be in the `buy` state today, we either held from yesterday (`old_buy`) or we bought today. If we buy today, we must have been in a `sell` state on day `i-2` (to respect the cooldown). The profit from that is `prev_sell - prices[i]`. `new_buy = max(old_buy, prev_sell - prices[i])`
- To be in the `sell` state today, we either rested from yesterday (`old_sell`) or we sold today. If we sell today, we must have been holding yesterday. The profit is `old_buy + prices[i]`. `new_sell = max(old_sell, old_buy + prices[i])`

The final implementation in this file uses this O(1) space approach.

Time Complexity:
O(n), where n is the number of days. We iterate through the prices array once.
Space Complexity:
O(1). We use a constant number of variables to store the profits from previous states.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Recursion (Will give TLE)
    int solveRec(int index, bool can_buy, vector<int> &prices)
    {
        if (index >= prices.size())
        {
            return 0;
        }

        if (can_buy)
        {
            // Option 1: Buy today
            int buy_profit = -prices[index] + solveRec(index + 1, false, prices);
            // Option 2: Rest (don't buy)
            int rest_profit = 0 + solveRec(index + 1, true, prices);
            return max(buy_profit, rest_profit);
        }
        else
        { // must sell or hold
            // Option 1: Sell today
            int sell_profit = prices[index] + solveRec(index + 2, true, prices);
            // Option 2: Hold
            int hold_profit = 0 + solveRec(index + 1, false, prices);
            return max(sell_profit, hold_profit);
        }
    }

    int maxProfitRecursive(vector<int> &prices)
    {
        return solveRec(0, true, prices);
    }

    // Approach 2: Memoization
    int solveMem(int index, int can_buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
        {
            return 0;
        }
        if (dp[index][can_buy] != -1)
        {
            return dp[index][can_buy];
        }

        if (can_buy == 1)
        { // can_buy is true
            int buy_profit = -prices[index] + solveMem(index + 1, 0, prices, dp);
            int rest_profit = 0 + solveMem(index + 1, 1, prices, dp);
            return dp[index][can_buy] = max(buy_profit, rest_profit);
        }
        else
        { // can_buy is false (0)
            int sell_profit = prices[index] + solveMem(index + 2, 1, prices, dp);
            int hold_profit = 0 + solveMem(index + 1, 0, prices, dp);
            return dp[index][can_buy] = max(sell_profit, hold_profit);
        }
    }

    int maxProfitMemoization(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveMem(0, 1, prices, dp); // 1 for can_buy = true
    }

    // Approach 4: Space-Optimized DP (This is the function that will be called by LeetCode)
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }

        int buy = -prices[0];
        int sell = 0;
        int prev_sell = 0;

        for (int i = 1; i < n; ++i)
        {
            int prev_buy = buy;
            // If we buy today, we must have been in sell state before cooldown (prev_sell)
            buy = max(buy, prev_sell - prices[i]);

            // Update prev_sell for the next iteration. It's the sell state from the previous day.
            prev_sell = sell;

            // If we sell today, we must have been in buy state yesterday (prev_buy)
            sell = max(sell, prev_buy + prices[i]);
        }

        return sell;
    }

    // Approach 3: Tabulation
    int maxProfitTabulation(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            // State: can_buy = true (1)
            dp[index][1] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);

            // State: can_buy = false (0)
            dp[index][0] = max(prices[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
        }

        return dp[0][1];
    }
};