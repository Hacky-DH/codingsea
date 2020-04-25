#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of numbers nums, in which exactly two elements appear only once
and all the other elements appear exactly twice.
Find the two elements that appear only once.
time complexity O(n)
space complexity O(1)
*/

class Solution {
public:
    // a&(a-1) clear last 1
    // a&(-a) only keep last 1
    vector<int> singleNumber(const vector<int>& nums) {
        int tmp = 0;
        for(auto n : nums) tmp ^= n;
        int last = tmp & (-tmp);
        int res = 0;
        for(auto n : nums) if(last&n) res ^= n;
        return {res, res^tmp};
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    auto res = s.singleNumber({2,1,2,3,4,1});
    for(auto e : {3,4}){
        auto exp = find(res.begin(), res.end(), e);
        if(exp == res.end()) {
            cout<<"Failed"<<endl;
            return 1;
        }
    }
    cout<<"Passed"<<endl;
    return 0;
}
