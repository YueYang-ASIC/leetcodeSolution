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
//迭代+2个栈 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s1;//缓存栈
        stack<TreeNode*> s2;//弹出栈
        if (!root) {
            return ret;
        }
         
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode* curNode=s1.top();//curNode写在里面，while只做栈空判断。和preorder,inorder不一样，否则会内存泄漏
            //s1.top->s2
            s2.push(s1.top());
            s1.pop(); 
            if(curNode->left)
                s1.push(curNode->left);
            if(curNode->right)
                s1.push(curNode->right);             
            //curNode=s1.top();     
    // -----------------------bug:调用空stack的top()是未定义行为。------------- --- -------------------
    // stack<int>的内部容器是deque<int>，对stack调用top()相当于调用内部deque容器的back()。
    // C++标准（§ 23.2.3, Table 100）规定，对于顺序容器a，函数a.back()的实现如下：
    // {
    //     auto tmp = a.end();
    //     --tmp;
    //     return *tmp;
    // }
    // 在一个空的stack中，内部deque的begin() == end()。
    // 而且标准§ 24.2.6又规定，对一个双向/随机访问迭代器 r 执行前置operator--操作的前提条件是存在另一个迭代器 s 可以满足r == ++s。
    // 由于空stack的top()对内部deque容器的begin()执行了--操作，所以在没有任何优化的情况下，调用top()会导致编译无法通过。
                                
        }

        while(!s2.empty())//stack没有迭代器，不能使用c++11的range loop语法，所以用while遍历。
        {
            ret.push_back(s2.top()->val);
            s2.pop();
        }
        return ret;

    }
};
