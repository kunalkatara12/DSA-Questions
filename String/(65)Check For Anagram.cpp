/*
Link: https://leetcode-cn.com/problems/valid-anagram/
Problem: Valid Anagram
Difficulty: Easy
Statement: Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true
Example 2:
    Input: s = "rat", t = "car"
    Output: false

Hint: You may assume the string contains only lowercase alphabets.

*/
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> mp;

    int m = s.length();
    for (int i = 0; i < m; i++)
        mp[s[i]]++;
    for (int i = 0; i < m; i++)
    {
        if (!mp[t[i]])
            return false;
        mp[t[i]]--;
    }
    return true;
}