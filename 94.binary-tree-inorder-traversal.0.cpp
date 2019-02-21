/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (63.54%)
 * Total Accepted:    19K
 * Total Submissions: 29.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
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
 * 输出: [1,3,2]
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
//非递归：用栈
//1.先从根节点开始，遍历左子树，把经过的节点都压入栈，直到p到达最左节点。
//2.将栈顶元素输出,把当前节点指向栈顶元素右节点，弹出栈顶元素。
//3.如果当前节点存在或者栈不为空，循环1，2步骤，
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* curNode=root;
        while(curNode||!s.empty())//迭代条件：栈不为空，且还有节点没访问到
        {
            //遍历所有left,经历过的全入栈,找到最左节点
            while(curNode)
            {
                s.push(curNode);
                curNode=curNode->left;
            }

            //由于最左节点没有左子树，所以相当于是子结构树的根节点，中序遍历再访问右子树，重复1，2步

            //得到最左节点（栈顶）
            curNode=s.top();
            //输出最左节点
            ret.push_back(curNode->val);
            //出栈
            s.pop();

            //访问最左节点的右子树
            curNode=curNode->right;
        }
        return ret; 
    }
};
