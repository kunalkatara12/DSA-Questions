/*
Link: https://leetcode.com/problems/pascals-triangle/
Problem: Pascal's Triangle
Statement:
118. Pascal's Triangle
Easy
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:




Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

Company Tags: 
Google
Microsoft
Tekion-corp
Facebook
Netflix
Oracle
Samsung
Adobe
CRED
Meesho
Swiggy
Dream11
InMobi
Oyo
PayTM
Byju's

Constraints:

1 <= numRows <= 30

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> gen_row(int r)
{
    long long res = 1;
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i < r; i++)
    {
        res *= (r - i);
        res /= i;
        ans.push_back(res);
    }
    return ans;
}
vector<vector<int>> generate(int n)
{
    vector<vector<int>> ans;
    for (int r = 1; r <= n; r++)
        ans.push_back(gen_row(r));

    return ans;
}