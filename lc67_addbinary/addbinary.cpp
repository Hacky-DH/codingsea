/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.


415. Add Strings
Given two non-negative integers num1 and num2 represented as string,
return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or
convert the inputs to integer directly.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return true;
}();

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size()) return addBinary(b, a);
        else if(a.size() < b.size()) {
            int t = b.size() - a.size();
            while(t--) a = '0' + a;
        }
        bool c = false;
        for(int i=a.size()-1; i>=0; --i) {
            if(a[i] != b[i]) a[i] = (c ? '0' : '1');
            else if(a[i] == '1') {
                a[i] = c ? '1' : '0';
                c = true;
            } else {
                if(c) {
                    a[i] = '1';
                    c = false;
                }
            }
        }
        if(c) a = '1'+a;
        return a;
    }

    string addStrings(string num1, string num2) {
        if(num1.size() > num2.size()) return addStrings(num2, num1);
        else if(num1.size() < num2.size()) {
            int t = num2.size() - num1.size();
            while(t--) num1 = '0' + num1;
        }
        int c = 0, tmp;
        for(int i=num1.size()-1; i>=0; --i) {
            tmp = num1[i] + num2[i] - '0' - '0' + c;
            num1[i] = (tmp % 10) + '0';
            c = tmp / 10;
        }
        if(c!=0) num1 = '1' + num1;
        return num1;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
