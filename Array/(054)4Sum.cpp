/*
Link: https://practice.geeksforgeeks.org/problems/4-sum-problem1732/1

Problem: 4 Sum problem
Level: Medium
Statement: Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

Company Tags: Amazon | Facebook | Apple | Microsoft | Adobe | Google | Yahoo | Infosys | LinkedIn | 
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int t)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i <= n - 4; i++)
    {
        for (int j = i + 1; j <= n - 3; j++)
        {
            long long nT = (long long)t - nums[i] - nums[j];
            int l = j + 1, h = n - 1;
            while (l < h)
            {
                if (nums[l] + nums[h] < nT)
                    l++;
                else if (nums[l] + nums[h] > nT)
                    h--;
                else
                {
                    st.insert({nums[i], nums[j], nums[l], nums[h]});
                    int tempIndex1 = l, tempIndex2 = h;
                    while (l < h && nums[l] == nums[tempIndex1])
                        l++;
                    while (l < h && nums[h] == nums[tempIndex2])
                        h--;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                j++;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            i++;
    }
    for (auto it : st)
        res.push_back(it);

        
    return res;
}