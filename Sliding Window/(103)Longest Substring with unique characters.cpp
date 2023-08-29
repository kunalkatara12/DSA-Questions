/*
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Problem: Longest Substring without repeating characters
Level: Medium
Company Tags: Amazon | Microsoft | Facebook | Bloomberg | Apple | Google | Spotify | Adobe | Uber | VMware | Yahoo | Goldman Sachs | Oracle | Walmart Global Tech | Salesforce | Paypal | Samsung | Intuit | Yandex | Zoho | JPMorgan

Statement: Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int i = 0, j = 0, mx = 0, n = s.length();
    unordered_map<char, int> mp;

    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() == j - i + 1)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (!mp[s[i]])
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }

    return mx;
}