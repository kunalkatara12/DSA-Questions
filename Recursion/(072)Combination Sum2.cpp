/*
Link: https://leetcode.com/problems/combination-sum-ii/

Problem: Combination Sum II
Level: Medium
Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]


Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/
#include <bits/stdc++.h>
using namespace std;

void findComb(vector<int> &candidates, int target, set<vector<int>> &st, vector<int> &ds, int ind)
{
    if (target == 0)
    {
        st.insert(ds);
        return;
    }
    for (int i = ind; i < candidates.size(); i++)
    {
        if (i > ind && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        ds.push_back(candidates[i]);
        findComb(candidates, target - candidates[i], st, ds, i + 1);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int tgt) {
    set<vector<int>> st;
    vector<int> ds;
    sort(candidates.begin(), candidates.end()); // Sorting the array to handle duplicates
    findComb(candidates,tgt,st, ds, 0);

    vector<vector<int>> ans;
    for (auto it : st) 
        ans.push_back(it);
    
    return ans;
}
