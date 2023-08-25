/*
Link: https://leetcode.com/problems/russian-doll-envelopes/description/
Problem: 354. Russian Doll Envelopes
Level: Hard
Companies: Google | tiktok
Statement: You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1


Constraints:

1 <= envelopes.length <= 10^5
envelopes[i].length == 2
1 <= wi, hi <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>> &v)
{
    sort(v.begin(), v.end(), [](const std::vector<int> &a, const std::vector<int> &b)
         {
             if (a[0] == b[0])
                 return a[1] > b[1]; // Sort in ascending order of 0th index
             return a[0] < b[0];     // Sort in descending order of 1st index if 0th indices are equal
         });

    vector<int> ans;
    ans.push_back(v[0][1]);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i][1] > ans.back())
            ans.push_back(v[i][1]);
        else
            ans[lower_bound(ans.begin(), ans.end(), v[i][1]) - ans.begin()] = v[i][1];
    }
    return ans.size();
}

// T(n) = O(nlogn)
// S(n) = O(n)