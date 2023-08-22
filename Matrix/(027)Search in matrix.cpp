/*
Link: https://leetcode.com/problems/search-a-2d-matrix/
Problem: Search a 2D Matrix
Level: Medium
Statement:
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

Company Tags:
Facebook
Amazon
Microsoft
Bloomberg
Apple
Adobe
Goldman Sachs
Oracle
Nvidia
Salesforce

*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    // int r=rowCheck(matrix,target,m,n);
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][n - 1] < target)
            continue;
        else if (matrix[i][n - 1] == target)
            return true;
        else
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
    }
    return false;
}

bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][n - 1] < target)
            continue;
        else if (matrix[i][n - 1] == target)
            return true;
        else
        {
            int l = 0, r = n - 2;

            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
    }
    return false;
}

bool searchMatrix3(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int sr = 0, er = n - 1; 
    int rowans = -1;
    while (sr <= er)
    {
        int mid = (sr + er) / 2;
        if (target >= matrix[mid][0] && target <= matrix[mid][m - 1])
        {
            rowans = mid;
            break;
        }
        else if (target < matrix[mid][0])
            er = mid - 1;
        else if (target > matrix[mid][m - 1])
            sr = mid + 1;
    }
    if (rowans == -1)
        return false;
    int sc = 0, ec = m - 1; 
    while (sc <= ec)
    {
        int mid = (sc + ec) / 2;
        if (matrix[rowans][mid] == target)
            return true;
        else if (matrix[rowans][mid] > target)
            ec = mid - 1;
        else if (matrix[rowans][mid] < target)
            sc = mid + 1;
    }
    return false;
}