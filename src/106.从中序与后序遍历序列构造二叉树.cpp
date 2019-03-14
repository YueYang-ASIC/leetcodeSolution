/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (57.51%)
 * Total Accepted:    5.1K
 * Total Submissions: 8.8K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
//recursive .dfs
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int mid= postorder.size()-1 ;//后序遍历。根节点在最后一个。
        return Helper(inorder,postorder,mid,0,postorder.size()-1);
    }

    TreeNode* Helper(vector<int>& inorder,vector<int>& postorder,int & mid ,int start ,int end )
    {
        if(start>end||mid<0)
        return nullptr;

        TreeNode* root=new TreeNode(postorder[mid]);
        auto pos = distance(inorder.begin(),find(inorder.begin()+start,inorder.begin()+end,postorder[mid]) );
        mid--;//从后面找根节点

        //后序是 先递归右子树。再递归左子树
        root->right=Helper(inorder,postorder,mid,pos+1,end);
        root->left=Helper(inorder,postorder,mid,start,pos-1); 
        return root;
    }
};

