/*
Link: https://practice.geeksforgeeks.org/problems/coin-change2448/1

Problem: Coin Change Problem
Medium

Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.

Example 1:

Input:
N = 3, sum = 4
coins = {1,2,3}
Output: 4
Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
N = 4, Sum = 10
coins = {2,5,3,6}
Output: 5
Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array coins its size N and sum as input parameters and returns the number of ways to make change for given sum of money.

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum)

Constraints:
1 <= sum, N, coins[i] <= 103

*/

#include <bits/stdc++.h>
using namespace std;
long long int count(int coins[], int n, int a)
{
    long long int t[n + 1][a + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;

    for (int i = 0; i < a + 1; i++)
        t[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < a + 1; j++)
            (coins[i - 1] <= j) ? t[i][j] = (t[i][j - coins[i - 1]] + t[i - 1][j]) : t[i][j] = t[i - 1][j];
   
    return t[n][a];
}