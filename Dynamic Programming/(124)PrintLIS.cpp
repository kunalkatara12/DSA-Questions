/*
Problem: Print Longest Increasing Subsequence
*/
#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;
vector<int> printingLongestIncreasingSubsequence(vector<int> nums, int n)
{
    vector<int> dp(n, 1), hash(n), ans;
    int mx = 1, lst = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        hash[i] = i;
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (dp[i] > mx)
        {
            mx = dp[i];
            lst = i;
        }
    }
    while (hash[lst] != lst)
    {
        ans.push_back(nums[lst]);
        lst = hash[lst];
    }
    ans.push_back(nums[lst]);
    reverse(ans.begin(), ans.end());
    return ans;
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