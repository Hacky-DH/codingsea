/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
187. Repeated DNA Sequences
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings)
that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
static bool init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return true;
}();

// bitmap and hash table
// use two bits to map ACGT
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> mapping({{'A',0},{'C',1},{'G',2},{'T',3}});
        int L=10, bitmap=0, N=s.size();
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) {
            nums[i] = mapping[s[i]];
        }
        unordered_set<string> ans;
        unordered_set<int> hash;
        for (int i = 0; i < N-L+1; ++i) {
            if(i) {
                bitmap <<= 2;
                bitmap |= nums[i+L-1];
                bitmap &= ~(3 << (L<<1));
            } else {
                for (int l = 0; l < L; ++l) {
                    bitmap <<= 2;
                    bitmap |= nums[l];
                }
            }
            if(!hash.insert(bitmap).second) {
                ans.insert(s.substr(i, L));
            }
        }
        return vector<string>(begin(ans), end(ans));
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    auto ans = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    if(ans.size()!=2) {
        cout<<"Failed 1-1"<<endl;
        return -1;
    }
    if (ans[0] != "CCCCCAAAAA") {
        cout<<"Failed 1-3"<<endl;
        return -1;
    }
    if (ans[1] != "AAAAACCCCC") {
        cout<<"Failed 1-2"<<endl;
        return -1;
    }
    ans = s.findRepeatedDnaSequences("AAAAAAAAAAAA");
    if(ans.size()!=1) {
        cout<<"Failed 2-1"<<endl;
        return -1;
    }
    if (ans[0] != "AAAAAAAAAA") {
        cout<<"Failed 2-2"<<endl;
        return -1;
    }
    cout<<"Passed"<<endl;
    return 0;
}
