/*
Link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


Problem: Palindromic Partitioning
Level: Hard

Statement: Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500

Company Tags: Amazon | Microsoft | Google
*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isPalindrome(string String, int i, int j)
    {
        if (i >= j)
            return true;

        while (i < j)
        {
            if (String[i] != String[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(string s, int i, int j, int (&t)[501][501])
    {
        if (i >= j)
            return 0;
        if (isPalindrome(s, i, j))
            return 0;
        if (t[i][j] != -1)
            return t[i][j];

        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int left = 0, right = 0;
            if (t[i][k] != -1)
                left = t[i][k];
            else
            {
                left = helper(s, i, k, t);
                t[i][k] = left;
            }
            if (t[k + 1][j] != -1)
                right = t[k + 1][j];
            else
            {
                right = helper(s, k + 1, j, t);
                t[k + 1][j] = right;
            }
            int tmp = left + right + 1;
            mn = min(mn, tmp);
        }
        return t[i][j] = mn;
    }
    int palindromicPartition(string str)
    {
        int n = str.length();
        int t[501][501];
        memset(t, -1, sizeof(t));
        return helper(str, 0, n - 1, t);
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}