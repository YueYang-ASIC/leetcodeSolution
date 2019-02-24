/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (35.24%)
 * Total Accepted:    2.5K
 * Total Submissions: 7.1K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 示例: 
 * 
 * 你可以将以下二叉树：
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * 序列化为 "[1,2,3,null,null,4,5]"
 * 
 * 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
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
//dfs:preOrder
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         ostringstream out;
         serialize(root,out);
         return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream in(data);
        return deserialize(in);
    }

private:
    //  root - left - right 
    void serialize(TreeNode *root,ostringstream &out)
    {
        if(root)//存在就pre遍历，注意每次存入流中要加空格。
        {
            out<<root->val<<' ';//‘ ’为结束符
            serialize(root->left,out);
            serialize(root->right,out);
        }
        else//不存在就"# "也要有空格。
        {
            out<<"# ";//#代表空节点，后面还有一个结束符' '
        }        
    }


    TreeNode* deserialize(istringstream &in)
    {
        //读取节点
        string val;
        in >> val; //一个单词作为独立元素。用string流把string分割了
        if(val=="#") 
            return nullptr;
        //递归 重构树
        TreeNode* root=new TreeNode(stoi(val));       
        root->left=deserialize(in);       
        root->right=deserialize(in);
        return root;
    }
}; 
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
