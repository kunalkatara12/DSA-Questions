/*
Link: https://leetcode.com/problems/move-zeroes/description/
283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements. Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
*/

#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int i = 0, j = 0;
    int n = nums.size();
    for (int k = 0; k < n; k++)
    {
        if (!nums[k] && k + 1 < n)
        {
            i = k;
            j = k + 1;
            break;
        }
    }
    while (j < n)
    {
        if (nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
}
int main ()
{
    return 0;
}