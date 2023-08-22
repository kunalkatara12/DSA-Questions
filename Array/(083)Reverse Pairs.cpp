/*
Link: https://leetcode.com/problems/reverse-pairs/
Problem: 493. Reverse Pairs
Level: Hard
Companies: Amazon
Statement:  Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].


Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1


Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1

*/

// Solution1: Brute Force
// Time: O(n^2)
// Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if((long)nums[i] > 2LL * (long)nums[j]) {
                    res++;
                }
            }
        }
        return res;
    }

};

// Solution2: Merge Sort

// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
     int mergeAndCount(vector<int>& a, int left, int mid, int right) {
        int count = 0;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if ((long long)a[i] > 2LL * a[j]) {
                count += (mid - i + 1); // Count pairs in the left subarray
                j++;
            } 
            else i++;
        }

        // Merge the two sorted subarrays
        inplace_merge(a.begin() + left, a.begin() + mid + 1, a.begin() + right + 1);

        return count;
    }

    int mergeSortAndCount(vector<int>& a, int left, int right) {
        int count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            count += mergeSortAndCount(a, left, mid);
            count += mergeSortAndCount(a, mid + 1, right);
            count += mergeAndCount(a, left, mid, right);
        }
        return count;
    }

    int reversePairs(vector<int>& a) {
        return mergeSortAndCount(a, 0, a.size() - 1);
    }
};