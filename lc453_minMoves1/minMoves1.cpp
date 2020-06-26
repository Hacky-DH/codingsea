/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
453. Minimum Moves to Equal Array Elements
Given a non-empty integer array of size n, find the minimum number of
moves required to make all array elements equal, where a move is
incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
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
    int minMoves(vector<int>& nums) {
    	int ans=0, m=nums[0];
    	for (int i = 1; i < nums.size(); ++i) {
    		m = min(m, nums[i]);
    	}
    	for (int i = 0; i < nums.size(); ++i) {
    		ans += nums[i] - m;
    	}
    	return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums = {1,4,6};
	s.minMoves(nums);
    return 0;
}
