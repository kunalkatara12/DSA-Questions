/*
Link:
84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:
Input: heights = [2,4]
Output: 4

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> nsl(vector<int> &arr)
{
    vector<int> ans;
    stack<pair<int, int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.size() == 0)
            ans.push_back(-1);
        else if (st.size() > 0 && st.top().first < arr[i])
            ans.push_back(st.top().second);
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
                st.pop();
            if (st.size() == 0)
                ans.push_back(-1);
            else if (st.top().first < arr[i])
                ans.push_back(st.top().second);
        }
        st.push({arr[i], i});
    }
    return ans;
}
vector<int> nsr(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
            ans.push_back(n);
        else if (st.size() > 0 && st.top().first < arr[i])
            ans.push_back(st.top().second);
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
                st.pop();
            if (st.size() == 0)
                ans.push_back(n);
            else if (st.top().first < arr[i])
                ans.push_back(st.top().second);
        }
        st.push({arr[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> widthA(vector<int> NSR, vector<int> NSL)
{
    vector<int> ans;
    for (int i = 0; i < NSR.size(); i++)
        ans.push_back(NSR[i] - NSL[i] - 1);

    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    vector<int> NSL = nsl(heights), NSR = nsr(heights);
    vector<int> width = widthA(NSR, NSL);
    int mx = -1;
    for (int i = 0; i < heights.size(); i++)
        mx = max(mx, heights[i] * width[i]);

    return mx;
}
