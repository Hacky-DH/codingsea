/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
16.07. Maximum LCCI
Write a method that finds the maximum of two numbers.
You should not use if-else or any other comparison operator.

Example:

Input:  a = 1, b = 2
Output:  2
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

//Karnaugh map
class Solution {
public:
    int maximum(int a, int b) {
        long diff = (long)a - b;
        int sign = (diff>>31) + 1;
        int asign = (a>>31) + 1;
        int bsign = (b>>31) + 1;
        cout<<asign<<bsign<<sign<<endl;
        sign = ((1^bsign)&asign) | ((1^bsign)&sign) | (asign&sign);
        return a*sign + b*(1^sign);
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    int ans;
    ans = s.maximum(19, 18);
    if(ans != 19) {
        cout<<"Failed 1"<<endl;
        return -1;
    }
    ans = s.maximum(18, 19);
    if(ans != 19) {
        cout<<"Failed 2"<<endl;
        return -1;
    }
    ans = s.maximum(-39, -56);
    if(ans != -39) {
        cout<<"Failed 3"<<endl;
        return -1;
    }
    ans = s.maximum(-56, -39);
    if(ans != -39) {
        cout<<"Failed 4"<<endl;
        return -1;
    }
    ans = s.maximum(-56, 98);
    if(ans != 98) {
        cout<<"Failed 5"<<endl;
        return -1;
    }
    ans = s.maximum(98, -56);
    if(ans != 98) {
        cout<<"Failed 6"<<endl;
        return -1;
    }
    ans = s.maximum(1<<31, ~(1<<31));
    if(ans != ~(1<<31)) {
        cout<<"Failed 7 "<<ans<<endl;
        return -1;
    }
    ans = s.maximum(~(1<<31), 1<<31);
    if(ans != ~(1<<31)) {
        cout<<"Failed 8 "<<ans<<endl;
        return -1;
    }
    cout<<"Passed"<<endl;
    return 0;
}
