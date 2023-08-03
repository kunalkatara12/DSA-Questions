/*
Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

Problem: 151. Reverse Words in a String
Medium

Companies : Microsoft | Apple | LinkedIn | Amazon | Google | Visa |

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.


Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string trim(string s)
{
    int left = 0, right = s.length() - 1;

    // Trim leading spaces
    while (left <= right && s[left] == ' ')
        left++;

    // Trim trailing spaces
    while (right >= left && s[right] == ' ')
        right--;

    // Remove extra spaces between words
    string trimmed;
    bool space = false;
    for (int i = left; i <= right; i++)
    {
        if (s[i] != ' ')
        {
            trimmed += s[i];
            space = false;
        }
        else if (!space)
        {
            trimmed += ' ';
            space = true;
        }
    }

    return trimmed;
}
//O(n^2) time | O(n) space
string reverseWords(string s)
{
    string str = trim(s);
    int n = str.length();
    string ans = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            string wrd = "";
            int j;
            for (j = i; j >= 0 && str[j] != ' '; j--)
                wrd += str[j];

            reverse(wrd.begin(), wrd.end());
            ans += wrd;
            if (i > 0)
                ans += ' ';
            i = j + 1; // Skip the word and the space
        }
    }

    return ans;
}

// O(n) time | O(n) space

string reverseWordsBetter(string s)
{
    string str = trim(s), ans = "";
    int n = str.length();
    int j = n;

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            if (i < j)
                ans += str.substr(i + 1, j - i - 1) + ' ';

            j = i;
        }
        else if (i == 0)
            ans += str.substr(i, j - i);
    }

    return ans;
}