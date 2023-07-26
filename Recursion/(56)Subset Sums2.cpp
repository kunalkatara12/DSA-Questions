/*
Link: https://leetcode.com/problems/subsets-ii/description/

Problem: 90. Subsets II
Medium

Companies: Facebook | Amazon | Bloomberg | Adobe
Given an integer array nums that may contain duplicates, return all possible
subsets(the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:
Input: nums = [1,2,2] Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0] Output: [[],[0]]

Example 3:
Input: nums = [1,2,3] Output: [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]
Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &res, vector<int> &nums, int n, int idx, vector<int> &ds)
{
    res.push_back(ds);
    for (int i = idx; i <= n - 1; i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        helper(res, nums, n, i + 1, ds);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> v = nums, ds;
    int n = nums.size();
    sort(v.begin(), v.end());
    helper(res, v, n, 0, ds);
    return res;
}