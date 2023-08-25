/*
Link: https://leetcode.com/problems/word-break/
Problem: 139. Word Break
Medium
Companies: Amazon | Facebook | Apple | Qualtrics | Microsoft | Bloomberg | Oracle | Adobe | Google
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.


Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

*/
#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    set<string> st;
    int n = s.length();
    for (auto i : wordDict)
        st.insert(i);

    bool dp[301] = {false};
    dp[n] = true;
    for (int i = n - 1; i >= 0; i--)
    {
        string tmp;
        for (int j = i; j < n; j++)
        {
            tmp += s[j];
            if (st.find(tmp) != st.end()) // This checks if the current substring tmp is in the dictionary (wordDict). If it is, then it means that the substring from index i to j can be segmented into words. Here, dp[j+1] represents whether the substring from j+1 onwards can be segmented into words. The dp[i] is updated using logical OR (||) to account for all possible segmentations of the current substring
                dp[i] = dp[i] || dp[j + 1];
        }
    }
    return dp[0];
} 

// TC=O(n^2)
// SC=O(n)