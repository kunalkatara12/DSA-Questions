/*
Link: https://leetcode.com/problems/longest-increasing-subsequence/
Problem: 300. Longest Increasing Subsequence
Level: Medium
Statement: Given an integer array nums, return the length of the longest strictly increasing
subsequence
.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Recursive+Memoization
// T(n) = O(n^2)
// S(n) = O(n^2)

int lis(vector<int> &x, int i, int j, vector<vector<int>> &dp)
{
    if (i == x.size())
        return 0;
    if (dp[i][j + 1] != -1)
        return dp[i][j + 1];
    int take = 0;
    if (j == -1 || x[i] > x[j])
        take = 1 + lis(x, i + 1, i, dp);
    int notTake = 0 + lis(x, i + 1, j, dp);
    return dp[i][j + 1] = max(take, notTake);
}

int lengthOfLISrM(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return lis(nums, 0, -1, dp);
}


// Solution 2: Tabulation
// T(n) = O(n^2)
// S(n) = O(n^2)


int lengthOfLISTn2(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = -1; j < i; j++)
        {
            int take = 0;
            if (j == -1 || nums[i] > nums[j])
                take = 1 + dp[i + 1][i];
            int notTake = dp[i + 1][j + 1];
            dp[i][j + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

// Solution 3: Tabulation
// T(n) = O(n^2)
// S(n) = O(2n)

int lengthOfLIST2n(vector<int> &x)
{
    int n = x.size();
    vector<int> nextRow(n + 1, 0);
    vector<int> currRow(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int take = 0;
            if (j == -1 || x[i] > x[j])
                take = 1 + nextRow[i + 1];
            int notTake = 0 + nextRow[j + 1];
            currRow[j + 1] = max(take, notTake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

// Solution 4: Tabulation
// T(n) = O(n^2)
// S(n) = O(n)


int lengthOfLISTn(vector<int> &x)
{
    int n = x.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int take = 0;
            if (j == -1 || x[i] > x[j])
                take = 1 + dp[i + 1];
            int notTake = 0 + dp[j + 1];
            dp[j + 1] = max(take, notTake);
        }
    }
    return dp[0];
}

// Solution 5: Tabulation
// T(n) = O(n^2)
// S(n) = O(n)



int lengthOfLISTnbetter(vector<int> &x)
{
    int n = x.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int take = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] < x[j])
                take = max(take, 1 + dp[j]);
        }
        dp[i] = take;
    }
    return *max_element(dp.begin(), dp.end());
}

// Solution 6: DP + Binary Search
// T(n) = O(nlogn)
// S(n) = O(n)

int lengthOfLISDpbinary(vector<int> &x)
{
    int n = x.size();
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), x[i]);
        if (it == dp.end())
            dp.push_back(x[i]);
        else
            *it = x[i];
    }
    return dp.size();
}
