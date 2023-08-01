/*
Link: https://leetcode.com/problems/sliding-window-maximum/description/
Problem: 239. Sliding Window Maximum
Hard
Companies: Amazon | Google | Microsoft | Salesforce | Uber | Facebook | Adobe | Citadel | ByteDance | Apple | Twilio | tiktok | Bloomberg | VMware | Booking.com | DoorDash | DE Shaw | Quora
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    vector<int> ans;
    list<int> l;

    while (j < nums.size())
    {
        while (!l.empty() && l.back() < nums[j])
            l.pop_back();
  
        l.push_back(nums[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());
            if (nums[i] == l.front())
                l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}