/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (63.31%)
 * Total Accepted:    10K
 * Total Submissions: 15.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
//迭代+1个栈 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stack;
        stack.push(root); 
        TreeNode* curNode=nullptr;
        TreeNode* lastNode=root;
        if(!root)//注意入口判断！！
        return ret;

        
        while(!stack.empty())
        {
            curNode=stack.top();
            //left未处理:如果h==c->left，说明刚处理完left。如果h==c->right,说明刚处理完right，由于是后序，那说明left已经处理完了。
            if(curNode->left&&lastNode!=curNode->left&&lastNode!=curNode->right)
            {
                stack.push(curNode->left);
            }
            //left处理完，right未处理
            else if(curNode->right&&lastNode !=curNode->right)
            {
                stack.push(curNode->right);
            }
            //left,right都处理完，处理root
            else 
            {
                lastNode=stack.top();
                stack.pop();
                ret.push_back(lastNode->val);
            } 
        } 
        return ret; 
    }
};
