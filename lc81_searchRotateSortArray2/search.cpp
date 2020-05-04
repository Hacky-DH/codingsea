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
81. Search in Rotated Sorted Array II
Suppose an array sorted in ascending order is rotated
at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search.
If found in the array return true, otherwise return false.


https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[right]) {
                if(nums[left] == nums[right]) {
                    for (int i=left; i<=right; ++i) {
                        if(target == nums[i]) return true;
                    }
                    return false;
                } else {
                    right = mid - 1;
                }
            } else {
                // go right, m<t<l, l<m<t, t<l<m
                if((nums[mid] < target) ^ (target < nums[left]) ^ (nums[mid] < nums[left]))
                    left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    //vector<int> nums = {2,1};
    //vector<int> nums = {2,5,6,0,0,1,2};
    vector<int> nums = {4,5,5,0,1,1,2,3,3};
    bool pass = true;
    for(size_t i=0; i < nums.size(); ++i) {
        pass = s.search(nums, nums[i]);
        if(!pass) {
            cout<<"Failed"<<endl;
            return -1;
        }
    }
    pass = s.search(nums, 8);
    if(pass) {
        cout<<"Failed"<<endl;
        return -1;
    }
    pass = s.search(nums, -1);
    if(pass) {
        cout<<"Failed"<<endl;
        return -1;
    }
    cout<<"Passed"<<endl;
    return 0;
}

