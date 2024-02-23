/*
44. Wildcard Matching
Hard
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        // base conditions
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;
        if (i < 0 && j >= 0)
        {
            while (j >= 0)
            {
                if (p[j] != '*')
                    return false;
                j--;
            }
            return true;
        }
        // base conditions
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[j] == s[i] || p[j] == '?')
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        else if (p[j] == '*')
            return dp[i][j] = solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp);

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s, p, m - 1, n - 1, dp);
    }
};