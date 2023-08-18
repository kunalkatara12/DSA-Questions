/*
Link: https://practice.geeksforgeeks.org/problems/print-shortest-common-supersequence/0
https://www.leetcode.com/problems/shortest-common-supersequence/

Problem: 1092. Shortest Common Supersequence
Level: Hard
Statement: Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them. A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"


Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;
static int t[1001][1001];
void lcs(string a, string b, int m, int n)
{

    for (int i = 0; i <= m; i++)
        t[i][0] = 0;

    for (int i = 0; i <= n; i++)
        t[0][i] = 0;

    for (int i = 1; i <= m; i++)
    { // Fix: Start from 1, not 0
        for (int j = 1; j <= n; j++)
        { // Fix: Start from 1, not 0
            t[i][j] = (a[i - 1] == b[j - 1]) ? (t[i - 1][j - 1] + 1) : max(t[i - 1][j], t[i][j - 1]);
        }
    }
}

string shortestCommonSupersequence(string a, string b)
{
    int m = a.length();
    int n = b.length();
    memset(t, 0, sizeof(t));
    lcs(a, b, m, n);
    int i = m, j = n;
    string res = "";
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            res.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (t[i][j - 1] > t[i - 1][j - 1])
        {
            res.push_back(b[j - 1]);
            j--;
        }
        else
        {
            res.push_back(a[i - 1]);
            i--;
        }
    }
    while (i > 0)
    {
        res.push_back(a[i - 1]);
        i--;
    }
    while (j > 0)
    {
        res.push_back(b[j - 1]);
        j--;
    }
    reverse(res.begin(), res.end());
    return res;
}