/*
Link: https://leetcode.com/problems/maximum-product-subarray/
Problem: 152. Maximum Product Subarray
Level: Medium
Statement: Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
It is guaranteed that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.
Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

Constraints:
1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Kadane's Algorithm
// T(n) = O(n)
// S(n) = O(1)

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int mx = nums[0], mn = nums[0], ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        int temp = mx;
        mx = max({nums[i], nums[i] * mx, nums[i] * mn});
        mn = min({nums[i], nums[i] * temp, nums[i] * mn});
        ans = max(ans, mx);
    }
    return ans;
}
int maxProduct2Loops(vector<int> &nums)
{
    int prd = 1, mx = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        prd *= nums[i];
        mx = max(prd, mx);
        if (prd == 0)
            prd = 1;
    }
    prd = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        prd *= nums[i];
        mx = max(prd, mx);
        if (prd == 0)
            prd = 1;
    }
    return mx;
}
