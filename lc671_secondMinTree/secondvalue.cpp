/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
671. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes
with the non-negative value, where each node in this tree
has exactly two or zero sub-node.
If the node has two sub-nodes, then this node's value is
the smaller value among its two sub-nodes. More formally,
the property root.val = min(root.left.val, root.right.val)
always holds.

Given such a binary tree, you need to output the second minimum
value in the set made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.

https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
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
    int small;
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        small = root->val;
        return dfs(root);
    }

    int dfs(TreeNode* root) {
        if(root == nullptr) return -1;
        if(root->val > small) return root->val;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l == -1) return r;
        if(r == -1) return l;
        return min(l, r);
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
