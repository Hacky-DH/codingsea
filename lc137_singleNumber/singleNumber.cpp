/*******************************************************************
Copyright (c) 2018 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
137. Single Number II
Given a non-empty array of integers, every element appears three times
except for one, which appears exactly once. Find that single one.

time complexity O(n)
space complexity O(1)
*/

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        int one = 0, two = 0;
        for (auto n : nums){
            one = ~two & (one ^ n);
            two = ~one & (two ^ n);
        }
        return one;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    auto res = s.singleNumber({2,2,3,2});
    if(3 == res)
    	cout<<"Passed"<<endl;
    else
    	cout<<"Failed"<<endl;
    return 0;
}
