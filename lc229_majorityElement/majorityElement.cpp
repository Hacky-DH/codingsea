/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
229. Majority Element II
Given an integer array of size n, find all elements that appear more than n/3 times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
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
    vector<int> majorityElement(vector<int>& nums) {
    	int a=0,b=0,ca=0,cb=0;
    	for(auto num : nums){
    		if((ca==0||num==a)&&num!=b){
    			++ca; a=num;
    		}else if(cb==0||num==b) {
    			++cb; b=num;
    		}else {
    			--ca;--cb;
    		}
    	}
    	ca=0,cb=0;
    	for(auto num : nums){
    		if(num==a) ++ca;
    		if(num==b) ++cb;
    	}
    	vector<int> res;
    	if(ca>nums.size()/3) res.push_back(a);
    	if(cb>nums.size()/3 && a != b) res.push_back(b);
    	return res;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums{1,2,1,1,3,2,3,2};
	vector<int> exp{1,2};
	vector<int> res = s.majorityElement(nums);
	if(equal(exp.begin(), exp.end(), res.begin())){
		cout<<"Pass"<<endl;
	}
    return 0;
}
