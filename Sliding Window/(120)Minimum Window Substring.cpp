/*
76. Minimum Window Substring
Level: Hard
Topics: Hash Table,String,Sliding Window
Given two strings s and t of lengths m and n respectively, return the minimum window
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
*/


#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;
string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    int st = s.length(), lt = t.length();
    for (int i = 0; i < lt; i++)
        mp[t.at(i)]++;
    pair<int, int> mnL = {INT_MAX, 0};
    int i = 0, j = 0, cnt = mp.size();
    while (j < st)
    {
        if (mp.find(s.at(j)) != mp.end())
        {
            mp[s.at(j)]--;
            if (mp[s.at(j)] == 0)
                cnt--;
        }
        if (cnt == 0)
        {
            while (cnt == 0)
            {
                if (mp.find(s.at(i)) != mp.end())
                {
                    mp[s.at(i)]++;
                    if (mp[s.at(i)] > 0)
                    {
                        cnt++;
                        if (j - i + 1 < mnL.first)
                            mnL = {j - i + 1, i};
                    }
                }
                i++;
            }
        }
        j++;
    }
    if (mnL.first == INT_MAX)
        return "";
    return s.substr(mnL.second, mnL.first);
}
void func()
{
    
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }

    return 0;
}