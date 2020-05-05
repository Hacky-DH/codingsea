/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

https://leetcode-cn.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int *pre = nullptr;
        while(!st.empty() || cur != nullptr) {
            while(cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if(pre != nullptr && *pre >= cur->val)
                return false;
            pre = &cur->val;
            cur = cur->right;
        }
        return true;
    }

    // more simple inorder
    bool isValidBST2(TreeNode* root) {
        stack<TreeNode*> st;
        int *pre = nullptr;
        while(!st.empty() || root != nullptr) {
            if(root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                if(pre != nullptr && *pre >= root->val)
                    return false;
                pre = &root->val;
                root = root->right;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}
