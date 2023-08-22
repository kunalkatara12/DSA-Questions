/*
Link: https://leetcode.com/problems/powx-n/description/
Problem: Implement pow(x, n).
Level: Medium
Statement: Implement pow(x, n), which calculates x raised to the power n (x^n).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

#include <bits/stdc++.h>
using namespace std;

double myPowHelper(double x, long long n)
{
    if (!n) return 1.0; // base condition

    double temp = myPowHelper(x, n / 2); // recursive call
    long double tmpSquare=temp*temp; // square of temp
    if (!(n % 2)) // if n is even
        return double(tmpSquare);

    else // if n is odd
    {
        if (n > 0) // if n is positive
            return x * double(tmpSquare);
        else // if n is negative
            return (double(tmpSquare)) / x;
    }
}

double myPow(double x, int n)
{
    long long exp = n;
    if (n < 0)
    {
        x = 1 / x;
        exp = -exp;
    }

    return myPowHelper(x, exp);
}