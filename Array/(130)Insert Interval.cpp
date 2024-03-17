/*
Link: https://leetcode.com/problems/insert-interval/

57. Insert Interval
Level: Medium
Topics :Array
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.



Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:

0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 10^5
*/

#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;
vector<vector<int>> insert(vector<vector<int>> &v, vector<int> &newV)
{
    vector<vector<int>> res;
    int m = v.size();
    if (m == 0)
    {
        res.push_back(newV);
        return res;
    }
    int strt = newV[0], end = newV[1];
    for (int i = 0; i < m; i++)
    {
        int s = v[i][0], e = v[i][1];
        if (strt > e)
            res.push_back(v[i]);
        else if (s > end)
        {
            res.push_back(newV);
            for (int j = i; j < m; j++)
                res.push_back(v[j]);
            return res;
        }
        else
            newV = {min(newV[0], s), max(e, newV[1])};
    }
    res.push_back(newV);
    return res;
}
void func()
{
    
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }

    return 0;
}