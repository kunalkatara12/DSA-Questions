
/*
Link: Roman to Int-  https://leetcode.com/problems/roman-to-integer/description/
Int To Roman- https://leetcode.com/problems/integer-to-roman/description/
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

*/

#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;
int romanToInt(string s)
{
    int n = s.length();
    int a = 0;
    unordered_map<char, int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] >= mp[s[i + 1]])
            a += mp[s[i]];
        else
            a -= mp[s[i]];
    }
    return a;
}

string intToRoman(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hndrs[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thsnd[] = {"", "M", "MM", "MMM"};
    int j = 1, i = 1;
    vector<int> numA(5, 0);
    while (num > 0)
    {
        numA[i] = (num % 10) * j;
        i++;
        j *= 10;
        num /= 10;
    }
    return thsnd[numA[4] / 1000] + hndrs[numA[3] / 100] + tens[numA[2] / 10] + ones[numA[1]];
}