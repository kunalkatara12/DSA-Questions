/*
Link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
Problem: Maximum sum increasing subsequence
Level: Medium
Statement: Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100}
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.


Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 10^3
1 ≤ arr[i] ≤ 10^5

Company Tags: Morgan Stanley | Amazon | Microsoft
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumIS(vector<int> x, int n)
{
    vector<int> dp = x; // dp[i] will store the maximum sum of increasing subsequence ending at index i
    int res = x[0];     // Initialize the result with the first element of x

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (x[i] > x[j] && dp[i] < dp[j] + x[i])
                dp[i] = dp[j] + x[i];

        res = max(res, dp[i]);
    }

    return res;
}