/*
Link: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
https://leetcode.com/problems/longest-common-subsequence/description/

Problem: 1143. Longest Common Subsequence
Level: Medium
Statement: Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

Company Tags: 
Amazon
DoorDash
Bloomberg
Karat


Related Topics: Dynamic Programming
*/

// Solution 1: Recursive
// T(n) = O(2^n)
// S(n) = O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1, text2, text1.size(), text2.size());
    }
    
    int lcs(string text1, string text2, int m, int n) {
        if (m == 0 || n == 0) return 0;
       return (text1[m-1] == text2[n-1]) ?  1 + lcs(text1, text2, m-1, n-1) :  max(lcs(text1, text2, m-1, n), lcs(text1, text2, m, n-1));
    }
};

// Solution 2: Recursive + Memoization
// T(n) = O(m*n)
// S(n) = O(m*n)

class Solution_2 {
public:
  int lcs(string text1, string text2, int m, int n, vector<vector<int>>& memo) {
        if (m == 0 || n == 0) return 0;
        if (memo[m][n] != -1) return memo[m][n];
        return memo[m][n] = (text1[m-1] == text2[n-1]) ?  1 + lcs(text1, text2, m-1, n-1, memo) :  max(lcs(text1, text2, m-1, n, memo), lcs(text1, text2, m, n-1, memo));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        return lcs(text1, text2, m, n, memo);
    }
};

// Solution 3: Iterative/TABULATION
// T(n) = O(m*n)
// S(n) = O(m*n)

class Solution_3 {
 public:
     int lcs(string s1, string s2, int m, int n)
     {
        int t[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
            t[i][0] = 0;

        for (int i = 0; i <= n; i++)
            t[0][i] = 0;

        for (int i = 1; i < m + 1; i++)
            for (int j = 1; j < n + 1; j++)
                t[i][j] = (s1[i - 1] == s2[j - 1]) ? (t[i - 1][j - 1] + 1) : (max(t[i - 1][j], t[i][j - 1]));

        return t[m][n];
     }
     int longestCommonSubsequence(string text1, string text2)
     {
        int m = text1.size(), n = text2.size();
        return lcs(text1, text2, m, n);
     }
};