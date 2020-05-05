/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode *cur;
        while(!st.empty() || root != nullptr) {
            while(root != nullptr) {
                st.push(root);
                root = root->left;
            }
            cur = st.top();
            if(cur->right == nullptr) {
                ans.push_back(cur->val);
                st.pop();
            }
            root = cur->right;
            cur->right = nullptr; // modify the tree
        }
        return ans;
    }

    //not modify tree, use deque push_front
    vector<int> postorderTraversal2(TreeNode* root) {
        stack<TreeNode*> st;
        deque<int> ans;
        while(!st.empty() || root != nullptr) {
            if(root != nullptr) {
                st.push(root);
                ans.push_front(root->val);
                root = root->right;
            } else {
                root = st.top();
                st.pop();
                root = root->left;
            }
        }
        return vector<int>(begin(ans), end(ans));
    }
};

int main(int argc, char* argv[]) {
	return 0;
}
