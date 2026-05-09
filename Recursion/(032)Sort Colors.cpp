/*
Link: https://leetcode.com/problems/sort-colors/
Problem: Sort Colors
Statement:
Medium

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

*/

#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &v)
{
    int low = 0, mid = 0, high = static_cast<int>(v.size()) - 1;
    while (mid <= high)
    {
        if (v[mid] == 0)
            swap(v[low++], v[mid++]);
        else if (v[mid] == 1)
            mid++;
        else
            swap(v[mid], v[high--]);
    }
}

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v = {2, 0, 2, 1, 1, 0};
    sortColors(v);
    print(v);
    return 0;
}
