/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
45. Jump Game II
Given an array of non-negative integers,
you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:
You can assume that you can always reach the last index.

https://leetcode-cn.com/problems/jump-game-ii
*/

class Solution {
public:
    int jump_wrong(vector<int>& nums) {
        // not pass [1,2,1,1,1]
        int s = nums.size();
        if(s <= 1) return 0;
        if(s == 2) return 1;
        int ans = 1;
        for(int i=s-3; i>=0; --i) {
            //Only two cases are considered, wrong!
            if(nums[i] >= (s-i-1)) ans = 1;
            else ++ans;
        }
        return ans;
    }

    int jump(vector<int>& nums) {
        int s = nums.size();
        int end=0, mp=0, ans=0;
        for(int i=0; i<s-1; ++i) {
            mp = max(mp, i + nums[i]);
            if(i == end) {
                end = mp;
                ++ans;
            }
        }
        return ans;
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {1,2,1,1,1};
    //vector<int> nums = {2,3,1,1,4};
    auto res = s.jump(nums);
    if(res == 3)
        cout<<"Passed"<<endl;
    else
        cout<<"Failed"<<endl;
    return 0;
}

