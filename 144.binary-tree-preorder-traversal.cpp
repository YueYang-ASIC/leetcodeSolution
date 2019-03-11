/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (56.22%)
 * Total Accepted:    13.3K
 * Total Submissions: 23.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
//递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preOrder(root,ret);
        return ret;        
    }

    void preOrder(TreeNode* root,vector<int> &ret)//注意用引用，不然返回不了ret
    {
        //preOrder:root->left->right
        if(!root) return;
        ret.push_back(root->val);
        preOrder(root->left,ret);
        preOrder(root->right,ret);
    }
};
