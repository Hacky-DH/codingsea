/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
318. Maximum Product of Word Lengths
Given a string array words, find the maximum value of
length(word[i]) * length(word[j]) where the two words
do not share common letters. You may assume that each
word will contain only lower case letters.
If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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
    int maxProduct(vector<string>& words) {
    	unordered_map<int, int> bm;
    	int ans=0, bit=0;
    	for(auto word : words) {
    		bit=0;
    		for(auto ch : word) {
    			bit |= 1<<(ch-'a');
    		}
    		if(bm.count(bit)) {
    			bm[bit] = max<int>(bm[bit], word.size());
    		} else {
    			bm[bit] = word.size();
    		}
    	}
    	for(auto m : bm) {
    		for(auto n : bm) {
    			if((m.first & n.first) == 0) {
    				ans = max(ans, m.second * n.second);
    			}
    		}
    	}
    	return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<string> words({"abcw","baz","foo","bar","xtfn","abcdef"});
	auto ans = s.maxProduct(words);
	if(ans == 16) cout<<"Passed"<<endl;
    return 0;
}
