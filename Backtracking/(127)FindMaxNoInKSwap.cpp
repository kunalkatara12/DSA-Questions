/*
Link: https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
Problem: Largest number in K swaps
Level: Medium
Topic Tags: Strings Backtracking
Company Tags: Amazon Microsoft MakeMyTrip Walmart Intuit Google
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
Example 2:

Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input
3435335 to 5543333, swapping 3
with 5, 4 with 5 and finally 3 with 4

Your task:
You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an integer as input and returns a string containing the largest number formed by perfoming the swap operation at most k times.


Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ |str| ≤ 30
1 ≤ K ≤ 10

*/

#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;
void findMaxBT(string &res, string str, int n, int k, int idx)
{
    if (k == 0 || idx == n)
    {
        res = max(str, res);
        return;
    }
    for (int i = idx + 1; i < n; i++)
    {
        if (str[i] > str[idx] && str[i] == *max_element(str.begin() + idx + 1, str.end()))
        {
            swap(str[i], str[idx]);
            findMaxBT(res, str, n, k - 1, idx + 1);
            swap(str[i], str[idx]);
        }
    }
    findMaxBT(res, str, n, k, idx + 1);
}
string findMaximumNum(string str, int k)
{
    string res = str;
    int n = str.length();
    findMaxBT(res, str, n, k, 0);
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