/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
272 Closest Binary Tree Traversal II

Given a non-empty binary search tree and a target value,
find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values
in the BST that are closest to the target.

Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime
(where n = total nodes)?

https://leetcode.com/problems/closest-binary-search-tree-value-ii/
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
    vector<int> closestKValues(TreeNode* root， double target, int k) {
        stack<TreeNode*> st;
        deque<int> ans;
        while(!st.empty() || root != nullptr) {
            if(root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                if(ans.size() == k) {
                    int tmp = ans.front();
                    if(fabs(tmp - target) > fabs(root->val - target)) {
                        ans.pop_front();
                        ans.push_back(root->val);
                    }
                } else ans.push_back(root->val);
                root = root->right;
            }
        }
        return vector<int>(begin(ans), end(ans));
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
