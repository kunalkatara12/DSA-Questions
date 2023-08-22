/*
Link: https://leetcode.com/problems/partition-equal-subset-sum/
Problem: Partition Equal Subset Sum
Statement:
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include<bits/stdc++.h>
using namespace std;
bool knap(vector<int> &arr, long t)
{
    int n = arr.size();
    bool tmp[n + 1][t + 1];
    for (int i = 0; i <= t; i++)
        tmp[0][i] = false;

    for (int i = 0; i <= n; i++)
        tmp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (arr[i - 1] <= j)
                tmp[i][j] = tmp[i - 1][j - arr[i - 1]] || tmp[i - 1][j];
            else
                tmp[i][j] = tmp[i - 1][j];
        }
    }
    return tmp[n][t];
}
bool canPartition(vector<int> &nums)
{
    long int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];

    if (sum % 2 != 0)
        return false;

    return knap(nums, sum / 2);
}