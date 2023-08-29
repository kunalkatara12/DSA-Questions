/*
Link: https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/

Evaluation of Postfix Expression

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.


Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression,
we have -4 as result.
Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix
expression, we have -3 as result.

*/

#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(string str)
{
    stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
            st.push(str[i] - '0');

        else
        {
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            if (str[i] == '+')
                st.push(t1 + t2);
            else if (str[i] == '-')
                st.push(t2 - t1);

            else if (str[i] == '*')
                st.push(t1 * t2);

            else if (str[i] == '/')
                st.push(t2 / t1);
        }
    }
    return st.top();
}