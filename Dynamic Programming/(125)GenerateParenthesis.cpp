/*
Problem:  22. Generate Parentheses
Link: https://leetcode.com/problems/generate-parentheses/

Level: Medium
Topics : String, Backtracking, Dynamic Programming

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8
*/

#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;
// Solution 1
// Time complexity:  O(n*n!)
// Space complexity: O(n + n!)
//Not working for n=7,8
bool isValid(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            if (s[i] == ')' && st.top() == '(')
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}
void permuteBT(string s, vector<string> &res, int n, int i,
               set<string> &st)
{
    if (i == n)
    {
        if (isValid(s) && st.find(s) == st.end())
        {
            res.push_back(s);
            st.insert(s);
        }
        return;
    }
    for (int j = i; j < n; j++)
    {
        if (i != j && s[i] == s[j])
        {
            continue; // Skip swapping identical characters
        }
        swap(s[j], s[i]);
        permuteBT(s, res, n, i + 1, st);
        swap(s[j], s[i]);
    }
}
vector<string> generateParenthesis(int n)
{
    if (n == 0)
        return {""};
    if (n == 1)
        return {"()"};
    string inpt = "";
    for (int i = 0; i < n; i++)
        inpt += '(';
    for (int i = 0; i < n; i++)
        inpt += ')';
    sort(inpt.begin(), inpt.end()); // Sort the input string
    vector<string> res;
    set<string> st;
    permuteBT(inpt, res, 2 * n, 0, st);
    return res;
}
// Solution 2
// Time complexity:  O(4^n / sqrt(n)
// Space complexity: O(n)
// Working for n=[1,8]

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    if (n == 0)
        ans.push_back("");
    
    else
    {
        for (int c = 0; c < n; c++)
        {
            for (string left : generateParenthesis(c))
            {
                for (string right : generateParenthesis(n - 1 - c))
                {
                    ans.push_back("(" + left + ")" + right);
                }
            }
        }
    }
    return ans;
}
// Solution 3
// Time complexity: O((4^n) / (n^(3/2)))
// Space complexity:O(4^n / (n^(3/2)))
// Woeking for n=[1,8]
void genPar(int open, int close, int n, string tmp, vector<string> &res, unordered_map<string, bool> &mp)
{
    if (mp.find(tmp) != mp.end())
        return;
    if (!open && !close)
    {
        res.push_back(tmp);
        mp[tmp] = true;
        return;
    }
    if (open)
        genPar(open - 1, close, n, tmp + '(', res, mp);
    if (close > open)
        genPar(open, close - 1, n, tmp + ')', res, mp);
}
vector<string> generateParenthesis3(int n)
{
    if (n == 0)
        return {""};
    if (n == 1)
        return {"()"};
    vector<string> res;
    string tmp = "";
    unordered_map<string, bool> mp;
    genPar(n, n, n, tmp, res, mp);
    return res;
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