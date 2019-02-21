/*
 * @lc app=leetcode.cn id=111 lang=cpp

 * 给定一个二叉树，找出其最小深度。
 * 示例:
 * 给定二叉树 [3,9,20,null,null,15,7],
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 返回它的最小深度  2.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        //root==nullptr,0
        if(!root)
            return 0;
        //left==nullptr->f(right)+1
        if(!root->left) return 1+minDepth(root->right);
        //right==nullptr->f(left)+1
        if(!root->right) return 1+minDepth(root->left);
        //none of above==nullptr->min(f(left),f(right))+1
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};
