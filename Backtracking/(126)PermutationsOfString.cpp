/*
Link: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
Problem: Permutations of a given string
Level: Medium

Statement: Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order.

Example 1:
Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6
forms as ABC, ACB, BAC, BCA, CAB and CBA .

Example 2:
Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS
BASG BGAS BGSA BSAG BSGA GABS GASB
GBAS GBSA GSAB GSBA SABG SAGB SBAG
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
Your Task:
You don't need to read input or print anything. Your task is to complete the function find_permutation() which takes the string S as input parameter and returns a vector of string in lexicographical order.

Expected Time Complexity: O(n! * n)
Expected Space Complexity: O(n! * n)

Constraints:
1 <= length of string <= 5
*/

#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;
void generatePermute(string s, int idx, int n, vector<string> &result)
{
    if (idx == n)
    {
        result.push_back(s);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        swap(s[idx], s[i]);
        generatePermute(s, idx + 1, n, result);
        swap(s[idx], s[i]);
    }
}
vector<string> find_permutation(string S)
{
    vector<string> result;
    generatePermute(S, 0, S.size(), result);
    sort(result.begin(), result.end());
    auto it = unique(result.begin(), result.end());
    result.resize(distance(result.begin(), it));
    return result;
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