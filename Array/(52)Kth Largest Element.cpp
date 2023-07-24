/*
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
Problem: 215. Kth Largest Element in an Array

Company Tags: Amazon | Adobe | Facebook | Google | Microsoft | LinkwdIn | TikTok | Goldmen Sachs | Bloomberg

Statement: Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

*/


#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v = nums;

    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i]);
        if (pq.size() > k)
            pq.pop();
    }
    
    return pq.top();
}