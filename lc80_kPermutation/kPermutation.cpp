/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
60. Permutation Sequence
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
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
    string getPermutation(int n, int k) {
        vector<int> fact(n);
        string num="1", ans;
        --k;
        fact[0] = 1;
        for(int i=1;i<n;++i) {
        	fact[i] = fact[i-1]*i;
        	num += i + '1';
        }
        int index;
        for(int i=n-1;i>=0;--i) {
        	index = k / fact[i];
        	k %= fact[i];
        	ans += num[index];
        	num.erase(index, 1);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	s.getPermutation(5, 16); //1 4 3 5 2
    return 0;
}
