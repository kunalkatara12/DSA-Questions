/*
Link: https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

Problem: Dynamic Programming Classics: The Longest Common Subsequence

Statement: A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. Longest common subsequence (LCS) of 2 sequences is a subsequence, with maximal length, which is common to both the sequences.

Given two sequences of integers, A and B, find the longest common subsequence and print it as a line of space-separated integers. If there are multiple common subsequences with the same maximum length, print any one of them.

In case multiple solutions exist, print any of them. It is guaranteed that at least one non-empty common subsequence will exist.




Function Description

Complete the longestCommonSubsequence function in the editor below. It should return an integer array of a longest common subsequence.

longestCommonSubsequence has the following parameter(s):

a: an array of integers
b: an array of integers
Input Format

The first line contains two space separated integers n and m, the sizes of sequences A and B.
The next line contains n space-separated integers .
The next line contains m space-separated integers .

Output Format

Print the longest common subsequence as a series of space-separated integers on one line. In case of multiple valid answers, print any one of them.

Sample Input

5 6
1 2 3 4 1
3 4 1 2 1 3
Sample Output

1 2 3
Explanation

There is no common subsequence with length larger than 3. And "1 2 3", "1 2 1", "3 4 1" are all correct answers.


*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lcs(vector<int> a, vector<int> b, int m, int n)
{
    vector<vector<int>> t(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
        t[i][0] = 0;

    for (int i = 0; i <= n; i++)
        t[0][i] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            t[i][j] = (a[i - 1] == b[j - 1]) ? t[i - 1][j - 1] + 1 : max(t[i - 1][j], t[i][j - 1]);

    return t;
}
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
{
    int m = a.size(), n = b.size();
    vector<vector<int>> t = lcs(a, b, m, n);

    int i = m, j = n;
    vector<int> res;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            res.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
            t[i - 1][j] > t[i][j - 1] ? i-- : j--;
    }
    reverse(res.begin(), res.end());
    return res;
}