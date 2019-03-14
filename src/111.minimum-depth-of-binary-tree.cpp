/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (36.51%)
 * Total Accepted:    10.5K
 * Total Submissions: 28.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
 * 
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
//dfs.递归。E
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
