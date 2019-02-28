/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        TreeNode* pre = nullptr;        
        Core(pRootOfTree,pre);
        
        while(pRootOfTree->left)
        {
            pRootOfTree = pRootOfTree->left;
        }
        return pRootOfTree;
    }
    //中序遍历。递归。
    void Core(TreeNode* root,TreeNode*& pre)
    {
        if(!root) return;//终止 
        
        //左
        Core(root->left,pre);
        if(pre)
        {
            pre->right=root;
            root->left=pre;
        }
        
        //根
        pre =root;
        
        //右
        Core(root->right,pre); 
    }
};