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
33. Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated
at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search.
If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

https://leetcode-cn.com/problems/search-in-rotated-sorted-array
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1, mid;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(nums[mid] == target) return mid;
            // go first part when s<t<m or m<s<t or t<m<s
            if (nums[start] <= nums[mid]) {
                if((nums[start] <= target) && (target < nums[mid]))
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                if((nums[mid] >= target) || (target >= nums[start]))
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return -1;
    }

    // more short
    int search2(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1, mid;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(nums[mid] == target) return mid;
            // go second part when m<t t<s m<s all is true
            // or only one of first two is true
            if((nums[mid] < target) ^ (target < nums[start]) ^ (nums[mid] < nums[start])) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    //vector<int> nums = {6, 2, 4};
    bool pass = true;
    for(int i=0; i < nums.size(); ++i) {
        auto res = s.search2(nums, nums[i]);
        pass = res == i;
        if(!pass) break;
    }
    pass = -1 == s.search2(nums, 8);
    if(pass)
        cout<<"Passed"<<endl;
    else
        cout<<"Failed"<<endl;
    return 0;
}

