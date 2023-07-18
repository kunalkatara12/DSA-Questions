/*
 Link: https://leetcode.com/problems/maximal-rectangle/description/
 85. Maximal Rectangle
 Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 Example 1:
 Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 Output: 6
 Example 2:
 Input: matrix = [["0"]]
 Output: 0
 Example 3:
 Input: matrix = [["1"]]
 Output: 1

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
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<int> v;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        if (matrix[0][i] == '1')
            v.push_back(1);
        else
            v.push_back(0);
    }
    int mx = largestRectangleArea(v);
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
                v[j] += 1;
            else
                v[j] = 0;
        }
        mx = max(mx, largestRectangleArea(v));
    }
    return mx;
}