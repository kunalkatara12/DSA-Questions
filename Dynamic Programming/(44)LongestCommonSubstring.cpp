/*
Link: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
Problem: Longest Common Substring
Level: Medium

Statement: Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000
*/

#include<bits/stdc++.h>
using namespace std;
int longestCommonSubstr(string x, string y, int xn, int yn)
{
    int t[xn + 1][yn + 1];
    for (int i = 0; i < xn + 1; i++)
        t[i][0] = 0;

    for (int j = 0; j < yn + 1; j++)
        t[0][j] = 0;

    int res = 0;
    for (int i = 1; i < xn + 1; i++)
    {
        for (int j = 1; j < yn + 1; j++)
        {
            t[i][j] = (x[i - 1] == y[j - 1]) ? 1 + t[i - 1][j - 1] : 0;
            res = max(t[i][j], res);
        }
    }
    return res;
}