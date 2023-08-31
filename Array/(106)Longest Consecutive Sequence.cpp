#include<bits/stdc++.h>
using namespace std;

// Solution 1: O(nlogn) time, O(n) space

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int n = nums.size();
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(nums[i]);

    vector<int> v;
    for (auto i : s)
        v.push_back(i);
    int cnt = 1, mx = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1] + 1)
        {
            cnt++;
            mx = max(cnt, mx);
        }
        else
            cnt = 1;
    }
    return mx;
}

// Solution 2: O(n) time, O(n) space

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int mx = 0;

    for (int num : numSet)
    {
        if (numSet.find(num - 1) == numSet.end())
        { // Start of a sequence
            int currNum = num;
            int currStreak = 1;

            while (numSet.find(currNum + 1) != numSet.end())
            { // Check consecutive elements
                currNum++;
                currStreak++;
            }

            mx = max(mx, currStreak);
        }
    }

    return mx;
}