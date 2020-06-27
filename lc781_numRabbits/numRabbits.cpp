/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
781. Rabbits in Forest
In a forest, each rabbit has some color. Some subset of rabbits
(possibly all of them) tell you how many other rabbits have the
same color as them. Those answers are placed in an array.

Return the minimum number of rabbits that could be in the forest.

Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5:
3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0
Note:

answers will have length at most 1000.
Each answers[i] will be an integer in the range [0, 999].
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
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> um;
        for(auto a : answers) {
            ++um[a+1];
        }
        int ans=0;
        for(auto u : um) {
            ans += max(u.first, (u.first+u.second-1)/u.first*u.first);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
