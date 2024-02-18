/*
Link: https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-ii/description/
Problem: 3040. Maximum Number of Operations With the Same Score II
Level: Medium
Statement: Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements:

Choose the first two elements of nums and delete them.
Choose the last two elements of nums and delete them.
Choose the first and the last elements of nums and delete them.
The score of the operation is the sum of the deleted elements.

Your task is to find the maximum number of operations that can be performed, such that all operations have the same score.

Return the maximum number of operations possible that satisfy the condition mentioned above.



Example 1:

Input: nums = [3,2,1,2,3,4]
Output: 3
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
- Delete the first and the last elements, with score 1 + 4 = 5, nums = [2,3].
- Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
We are unable to perform any more operations as nums is empty.
Example 2:

Input: nums = [3,2,6,1,4]
Output: 2
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
- Delete the last two elements, with score 1 + 4 = 5, nums = [6].
It can be proven that we can perform at most 2 operations.


Constraints:

2 <= nums.length <= 2000
1 <= nums[i] <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int maxRes(int a, int b, int c)
    {
        return max(a, max(b, c));
    }

public:
    int recur(int l, int r, int score, vector<int> &nums,
              vector<vector<int>> &dp)
    {
        if (l >= r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0, p1 = INT_MIN, p2 = INT_MIN, p3 = INT_MIN;
        if (nums[l] + nums[l + 1] == score)
            p1 = recur(l + 2, r, score, nums, dp);
        if (nums[l] + nums[r] == score)
            p2 = recur(l + 1, r - 1, score, nums, dp);
        if (nums[r] + nums[r - 1] == score)
            p3 = recur(l, r - 2, score, nums, dp);

        return dp[l][r] = ans = max(ans, 1 + maxRes(p1, p2, p3));
    }

    int maxOperations(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 3)
            return 1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int p1 = recur(2, n - 1, nums[0] + nums[1], nums, dp);
        int p2 = recur(0, n - 3, nums[n - 1] + nums[n - 2], nums, dp);
        int p3 = recur(1, n - 2, nums[0] + nums[n - 1], nums, dp);

        int ans = 1 + maxRes(p1, p2, p3);
        return ans;
    }
};