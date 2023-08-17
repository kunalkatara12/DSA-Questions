/*
Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

Problem: Find Missing And Repeating
Medium

Statement: Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N

Company Tags: Amazon | Samsung | D-E-Shaw | Goldman Sachs | MAQ Software
*/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    int xor_sum = 0;

    // XOR of array elements and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xor_sum ^= arr[i];
        xor_sum ^= (i + 1);
    }

    // Find the rightmost set bit in xor_sum
    int rightmost_set_bit = xor_sum & -xor_sum;

    int x = 0, y = 0;

    // Separate elements into two groups based on rightmost_set_bit
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmost_set_bit)
            x ^= arr[i];
        else
            y ^= arr[i];

        if ((i + 1) & rightmost_set_bit)
            x ^= (i + 1);
        else
            y ^= (i + 1);
    }

    // Check which one is missing and which one is repeating
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) 
            return make_pair(y, x);
        if (arr[i] == y) 
            return make_pair(x, y);
    }

    return make_pair(-1, -1); // Default return
}
