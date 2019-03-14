/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 *
 * https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (60.27%)
 * Total Accepted:    1.8K
 * Total Submissions: 3K
 * Testcase Example:  '[4,2,7,1,3]\n5'
 *
 * 给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。
 * 
 * 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。
 * 
 * 例如, 
 * 
 * 
 * 给定二叉搜索树:
 * 
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 * 
 * 和 插入的值: 5
 * 
 * 
 * 你可以返回这个二叉搜索树:
 * 
 * 
 * ⁠        4
 * ⁠      /   \
 * ⁠     2     7
 * ⁠    / \   /
 * ⁠   1   3 5
 * 
 * 
 * 或者这个树也是有效的:
 * 
 * 
 * ⁠        5
 * ⁠      /   \
 * ⁠     2     7
 * ⁠    / \   
 * ⁠   1   3
 * ⁠        \
 * ⁠         4
 * 
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
//迭代.break
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) { 
        if(root==nullptr) root= new TreeNode(val);
        TreeNode* cur= root;
        while(true)
        {
            if(cur->val<val)
                {
                    if(!cur->right) {cur->right=new TreeNode(val);break;}
                    else cur=cur->right;
                }
            else if(cur->val > val)
                    if(!cur->left ) {cur->left= new TreeNode(val);break;}
                    else cur=cur->left;
        }
        return root;
    }    
};
 