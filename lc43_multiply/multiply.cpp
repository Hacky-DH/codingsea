/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings,
return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
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
    string multiply(string num1, string num2) {
        int s1=num1.size(), s2=num2.size();
        string ans(s1+s2, '0');
        int n1,n2,prod;
        for(int i=s1-1;i>=0;--i) {
            n1 = num1[i] - '0';
            for(int j=s2-1;j>=0;--j) {
                n2 = num2[j] - '0';
                prod = n1 * n2 + ans[i+j+1] - '0';
                ans[i+j+1] = prod%10 + '0';
                ans[i+j] += prod/10;
            }
        }
        while(ans.size()>0&&ans[0]=='0') {
            ans = ans.substr(1);
        }
        if(ans.empty()) ans='0';
        return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	auto ans = s.multiply("2123443452345123","1233454534665546");
	if(ans == "2619170955400954193072169232158") cout<<"Passed"<<endl;
    return 0;
}
