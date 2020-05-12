/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
989. Add to Array-Form of Integer
For a non-negative integer X, the array-form of X is an array of its digits
in left to right order.
For example, if X = 1231, then the array form is [1,2,3,1].
Given the array-form A of a non-negative integer X,
return the array-form of the integer X+K.

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000


Note：
1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
*/

#include <iostream>
#include <vector>
#include <tuple>
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
    vector<int> addToArrayForm(vector<int>& A, int K) {
    	reverse(begin(A), end(A));
    	int i=0, t;
    	while(K != 0) {
    		if(i < A.size()) {
    			t = A[i] + K;
    			A[i] = t % 10;
    			K = t / 10;
    		} else {
    			t = K % 10;
    			K = K / 10;
    			A.push_back(t);
    		}
    		++i;
    	}
    	reverse(begin(A), end(A));
    	return A;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<tuple<vector<int>, int, vector<int>>> cases;
	cases.push_back({{2,7,4}, 981, {1,2,5,5}});
	cases.push_back({{1,2,0,0}, 34, {1,2,3,4}});
	cases.push_back({{2,1,5}, 806, {1,0,2,1}});
	cases.push_back({{9,9,9}, 1, {1,0,0,0}});
	for(auto c : cases) {
		vector<int> in = get<0>(c);
		int K = get<1>(c);
		vector<int> exp = get<2>(c);
		auto ans = s.addToArrayForm(in, K);
		for(int i=0; i<ans.size(); ++i) {
			if(exp[i] != ans[i]){
	        	cout<<"Failed"<<endl;
	        	return 1;
	    	}
		}
	}
	cout<<"Passed"<<endl;
    return 0;
}
