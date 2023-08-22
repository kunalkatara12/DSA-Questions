/*
Link: https://leetcode.com/problems/combination-sum/description/
Level: Medium
Problem: Combination Sum

Statement: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []


Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
     void findComb(vector<int> &arr, int tgt, int ind, vector<vector<int>> &ans, vector<int> &ds)
     {
         if (ind == arr.size())
         {
             if (tgt == 0)
                 ans.push_back(ds);

             return;
         }

         // Include the current element
         if (arr[ind] <= tgt)
         {
             ds.push_back(arr[ind]);
             tgt -= arr[ind];
             findComb(arr, tgt, ind, ans, ds);
             ds.pop_back();
             tgt += arr[ind];
         }
         // Exclude the current element
         findComb(arr, tgt, ind + 1, ans, ds);
     }

     vector<vector<int>> combinationSum(vector<int> &arr, int tgt)
     {
         vector<int> ds;
         vector<vector<int>> ans;
         findComb(arr, tgt, 0, ans, ds);
         return ans;
     }
};