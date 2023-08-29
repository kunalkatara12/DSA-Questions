/*
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
https://www.codingninjas.com/studio/problems/search-pattern-kmp-algorithm_8416386?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Problem: Pattern Matching using KMP Algorithm
Statement: Given two strings needle and haystack, return the vector of positions of the occurrence of needle in haystack.

Sample Input 1:
cxyzghxyzvjkxyz
xyz


Sample Output 1:
3
2 7 13


Explanation Of Sample Input 1 :
The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.


Sample Input 2 :
ababacabab
aba


Sample Output 2 :
3
1 3 7


Explanation Of Sample Input 2 :
Here we have an overlap between the first occurrence (at position 1) and the second occurrence (at position 3), and we are considering both.


Sample Input 3 :
abcd
xy


Sample Output 3 :
0


Expected Time Complexity:
The expected time complexity is O(n + m).


Constraints:
1 <= ‘n’ <= 10 ^ 5
1 <= ‘m’ <= ‘n’
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pre(string s, int n)
{
    vector<int> preS(n, 0);
    int i = 1, len = 0;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            preS[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = preS[len - 1];
            else
            {
                preS[i] = 0;
                i++;
            }
        }
    }
    return preS;
}
vector<int> stringMatch(string s, string t)
{
    int m = s.length(), n = t.length(), i = 0, j = 0;
    vector<int> ans, lps = pre(t, n);
    while (i < m)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == n)
        {
            ans.push_back(i - j + 1);
            j = lps[j - 1];
        }
    }
    return ans;
}
