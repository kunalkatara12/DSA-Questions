/*
73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

// writing only Function
#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();    // rows
    int n = matrix[0].size(); // column
    bool rowFlag = false;
    bool colFlag = false;
    for (int i = 0; i < n; i++)
    {
        if (!matrix[0][i])
        {
            rowFlag = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (!matrix[i][0])
        {
            colFlag = true;
            break;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (!matrix[i][j])
                matrix[0][j] = matrix[i][0] = 0;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (!matrix[0][j] || !matrix[i][0])
                matrix[i][j] = 0;
        }
    }

    for (int i = 0; rowFlag && i < n; i++)
        matrix[0][i] = 0;

    for (int i = 0; colFlag && i < m; i++)
        matrix[i][0] = 0;
}
int main()
{
    return 0;
}