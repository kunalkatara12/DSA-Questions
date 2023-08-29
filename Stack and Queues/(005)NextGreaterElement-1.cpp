/*
Link: https://leetcode.com/problems/next-greater-element-i/description/
496. Next Greater Element I
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

*/

#include<bits/stdc++.h>
using namespace std;

// Solution 1
vector<int> chkForIndex(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
                ans.push_back(j);
        }
    }

    return ans;
}
vector<int> ngl(vector<int> &nums2)
{
    vector<int> ans;
    stack<int> st;
    int n = nums2.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
            ans.push_back(-1);
        else if (st.size() > 0 && st.top() > nums2[i])
            ans.push_back(st.top());
        else if (st.size() > 0 && st.top() <= nums2[i])
        {
            while (st.size() > 0 && st.top() <= nums2[i])
                st.pop();
            if (st.size() == 0)
                ans.push_back(-1);
            else if (st.top() > nums2[i])
                ans.push_back(st.top());
        }
        st.push(nums2[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> nextGreaterElement1(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> NGL = ngl(nums2);
    vector<int> chk = chkForIndex(nums1, nums2);
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
        ans.push_back(NGL[chk[i]]);
    return ans;
}
// Solution 1


// Solution 2
vector<int> nextGreaterElement2(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    stack<int> st;
    unordered_map<int, int> mp;
    for (int i = m - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
            st.pop();
        if (st.empty())
            mp[nums2[i]] = -1;
        else
            mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
        ans[i] = mp[nums1[i]];
    return ans;
}
// Solution 2

int main()
{
 return 0;
}