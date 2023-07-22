/*
Link: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

https://www.codingninjas.com/studio/problems/800284?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

Problem: Rod Cutting
Medium
We are given a rod of size ‘N’. It can be cut into pieces. Each length of a piece has a particular price given by the price array. Our task is to find the maximum revenue that can be generated by selling the rod after cutting( if required) into pieces.

Example:
Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24
*/

#include <bits/stdc++.h>
using namespace std;
int cutRod(vector<int> &price, int n)
{

    int a[n];

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int tmp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        tmp[0][i] = 0;

    for (int i = 0; i <= n; i++)
        tmp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] <= j)
                tmp[i][j] = max(price[i - 1] + tmp[i][j - a[i - 1]], tmp[i - 1][j]);
            else
                tmp[i][j] = tmp[i - 1][j];
        }
    }
    return tmp[n][n];
}
