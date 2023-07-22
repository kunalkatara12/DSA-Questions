/*
Link: https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
Problem: Count Subsets with Sum K

You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'
Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
Since the number of ways can be very large, print it **modulo 10^9 +7**.
Example:
Input: 'arr': [1, 1, 4, 5]
Output: 3
Explanation: The possible ways are:
[1,4]
[1,4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently


Sample Input 1 :
4 5
1 4 4 5


Sample Output 1 :
 3


Explanation For Sample Output 1:
The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.


Sample Input 2 :
3 2
1 1 1


Sample Output 2 :
3


Explanation For Sample Output 1:
There are three 1 present in the array. Answer is the number of ways to choose any two of them.


Sample Input 3 :
3 40
2 34 5


Sample Output 3 :
0


Expected Time Complexity :
The expected time complexity is O('n' * 'k').


Constraints:
1 <= 'n' <= 100
0 <= 'arr[i]' <= 1000
1 <= 'k' <= 1000

Time limit: 1 sec
*/
#include <bits/stdc++.h>
using namespace std;

int mod = (int)1e9 + 7;
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    long long int tmp[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
        tmp[i][0] = 1;

    for (int j = 1; j <= k; j++)
        tmp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (arr[i - 1] <= j)
                tmp[i][j] = tmp[i - 1][j - arr[i - 1]] + tmp[i - 1][j];
            else
                tmp[i][j] = tmp[i - 1][j];
        }
    }
    return tmp[n][k] % mod;
}