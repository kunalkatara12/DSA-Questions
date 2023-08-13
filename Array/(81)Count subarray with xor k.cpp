/*
Link: https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTab=0

Problem: Subarrays with XOR K
Statement: Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.

Input Format: The first line of input contains two integers n and m. The next line contains n space-separated integers representing the array arr[].

Output Format: Print the count of subarrays having XOR of their elements as m.

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= 10^5
1 <= m <= 10^5

Sample Input: 5 2
4 2 2 6 4

Sample Output: 2

*/

#include<bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector<int> arr, int K)
{
    int count = 0;
    int xor_sum = 0;
    unordered_map<int, int> xor_freq;

    for (int num : arr)
    {
        xor_sum ^= num;

        if (xor_sum == K)
            count++;

        if (xor_freq.find(xor_sum ^ K) != xor_freq.end())
            count += xor_freq[xor_sum ^ K];

        xor_freq[xor_sum]++;
    }

    return count;
}