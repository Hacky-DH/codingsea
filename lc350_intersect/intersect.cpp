/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map<int, int> um;
        for(int n : nums1) ++um[n];
        int r=0;
        for(int n : nums2)
            if(um.count(n) > 0 && um[n]-- > 0){
                nums1[r++] = n;
            }
        return vector<int>(begin(nums1), begin(nums1) + r);
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    auto res = s.intersect(nums1, nums2);
    for(auto e : {9,4}){
        auto exp = find(res.begin(), res.end(), e);
        if(exp == res.end()) {
            cout<<"Failed"<<endl;
            return 1;
        }
    }
    cout<<"Passed"<<endl;
    return 0;
}
