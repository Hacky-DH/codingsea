/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
421. Maximum XOR of Two Numbers in an Array
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 2^31.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:
Input: [3, 10, 5, 25, 2, 8]
Output: 28
Explanation: The maximum result is 5 ^ 25 = 28.
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
	// save prefix in hash
    int findMaximumXOR(vector<int>& nums) {
        int ans=0, cur=0;
        for(int i=31; i>=0; --i) {
            ans <<= 1;
            cur = ans | 1;
            unordered_set<int> us;
            for(auto n : nums) us.insert(n>>i);
            for(auto s : us) {
                if(us.count(s^cur)) {
                    ans = cur;
                    break;
                }
            }
        }
        return  ans;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
