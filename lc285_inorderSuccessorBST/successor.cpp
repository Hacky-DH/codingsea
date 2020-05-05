/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
285. Inorder Successor in BST

Given a binary search tree and a node in it,
find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

Note:
If the given node has no in-order successor in the tree, return null.
It's guaranteed that the values of the tree are unique.

https://leetcode.com/problems/inorder-successor-in-bst
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        while(root) {
            TreeNode* ans = nullptr;
            if(root->val > p->val) {
                ans = root;
                root = root->left;
            } else root = root->right;
        }
        return ans;
    }

    // 510. Inorder Successor in BST II
    // not given root, but has parent pointer
    Node* inorderSuccessor2(Node* node) {
        if(node == nullptr) return nullptr;
        if(node->right) {
            node = node->right;
            while(node && node->left) node = node->left;
            return node;
        }
        while(node) {
            if(node->parent == nullptr) return nullptr;
            if(node == node->parent->left) return node->parent;
            node = node->parent;
        }
        return node;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
