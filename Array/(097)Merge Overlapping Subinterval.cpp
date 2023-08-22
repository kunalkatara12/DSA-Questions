/*
Link: https://leetcode.com/problems/merge-intervals/description/
Problem: 56. Merge Intervals
Medium
Company Tags: Facebook | Amazon | Google | Bloomberg | Salesforce | Apple | Microsoft | Uber | Adobe | IBM | LinkedIn | Snapchat | Walmart Global Tech | VMware | Oracle | Yandex | Shopee | Twitter | Cisco | Intuit | Nvidia | Morgan Stanley | ByteDance | tiktok

Statement:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &v)
{
    vector<vector<int>> res;
    int n = v.size();

    if (!n)
        return res;

    // Sort the intervals based on their start points
    sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    res.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (v[i][0] <= res.back()[1])
            res.back()[1] = max(res.back()[1], v[i][1]);
        else
            res.push_back(v[i]);
    }

    return res;
}