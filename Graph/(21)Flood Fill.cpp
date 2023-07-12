/*
Link: https://leetcode.com/problems/flood-fill/
Problem :  733. Flood Fill
Statement: An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc]. To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color. Return the modified image after performing the flood fill.

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.


Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n

*/

#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &image, vector<vector<int>> &cpy, int sr, int sc, int newColor, int m, int n, int delRow[], int delCol[], int inColor)
{
    // change the color of copy matrix element having indices [sr][sc] to newColor
    cpy[sr][sc] = newColor;
    // now traverse in its neighbor
    for (int i = 0; i < 4; i++)
    {
        // neighbor row and neighbor column index
        int nRow = sr + delRow[i], nCol = sc + delCol[i];
        // conditions i. nRow between 0 and m
        // ii. same for nCol
        // iii. image should have initial color
        // iv. cpy should not have newColor
        if ((nRow >= 0 && nRow < m) &&
            (nCol < n && nCol >= 0) &&
            (image[nRow][nCol] == inColor) &&
            (cpy[nRow][nCol] != newColor))
            dfs(image, cpy, nRow, nCol, newColor, m, n, delRow, delCol, inColor);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    vector<vector<int>> cpy(image); // Make a copy of image data
    // m=Rows, n=Columns, inColor=initial color
    int m = cpy.size(), n = cpy[0].size(), inColor = image[sr][sc];
    // delRow & delCol= for traversing in neighborhood(up,down,left,right)
    int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
    dfs(image, cpy, sr, sc, newColor, m, n, delRow, delCol, inColor);
    return cpy;
}