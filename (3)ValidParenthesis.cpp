/*
Link: https://leetcode.com/problems/valid-parentheses/description/
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.An input string is valid if:
      Open brackets must be closed by the same type of brackets.
      Open brackets must be closed in the correct order.
      Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    //   st.push(s[0]);
    int i = 0;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] != ')' && s[i] != '}' && s[i] != ']')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            if (s[i] == ')' && st.top() == '(')
                st.pop();
            else if (s[i] == ']' && st.top() == '[')
                st.pop();
            else if (s[i] == '}' && st.top() == '{')
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}
int main()
{
    return 0;
}