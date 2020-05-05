/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
501. Find Mode in Binary Search Tree
Given a binary search tree (BST) with duplicates,
find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys
less than or equal to the node's key.
The right subtree of a node contains only nodes with keys
greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

Note: If a tree has more than one mode, you can return them in any order.
Follow up: Could you do that without using any extra space?
(Assume that the implicit stack space incurred due to recursion does not count).

https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> ans;
    int cur,mode;
    int *pre;
public:
    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root->left);
        if(pre == nullptr) {
            pre = &root->val;
            cur = mode = 1;
        } else {
            if(*pre == root->val) ++cur;
            else cur=1;
            pre = &root->val;
        }
        if(cur == mode) ans.push_back(root->val);
        else if(cur > mode) {
            ans.clear();
            mode = cur;
            ans.push_back(root->val);
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        pre = nullptr;
        dfs(root);
        return ans;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}
