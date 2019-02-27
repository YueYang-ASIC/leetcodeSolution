/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (55.26%)
 * Total Accepted:    8.3K
 * Total Submissions: 14.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
//递归。二分查找法。关键参数：mid。中序的起始点索引。中序的终止点索引。先序是固定的，mid是由先序得到的。关键是找到mid在中序的pos,用distance(itbegin,itend)。
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootindx=0;
        return helper(preorder,inorder,rootindx,0,preorder.size()-1);//因为index是引用，所以要定义一个变量。不能直接传常量0进去，会报错
    }
    
private:
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int& rootInex,int start,int end) {
        //递归终止"index不能等于size(越界)。start不能超过end,可以等于
        if(rootInex>=preorder.size()||start>end)
        return nullptr;
        
        TreeNode* root = new TreeNode(preorder[rootInex]);
        auto pos = distance(inorder.begin(),find(inorder.begin()+start,inorder.begin()+end,preorder[rootInex]));
        //find(.begin()+start,.begin()+end,pre[index]) 不能直接写.begin和.end,因为他们是会变的。
        rootInex++;
        
        root->left=helper(preorder,inorder,rootInex,start,pos-1);
        root->right=helper(preorder,inorder,rootInex,pos+1,end); 

        return root;
    }
};