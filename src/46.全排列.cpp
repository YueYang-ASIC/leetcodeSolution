/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (66.03%)
 * Total Accepted:    15.2K
 * Total Submissions: 22.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
//递归。分层布局。1.交换第一个数字。2.第一个数固定。后面的排列。3.交换归位。
class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> ret;
        Helper(num,ret,0);
        return ret;	 
    }

    void Helper(vector<int> num,vector<vector<int>> & ret,int start)
    {
        if(start==num.size())
        {
            //一种全排列
            ret.push_back(num);
        }

        for(int i = start ; i<num.size() ; i++)
        {
            swap(num[i],num[start]);//交换当前
            Helper(num,ret,start+1);//进入下一层布局（后部分全排列）
            swap(num[i],num[start]);//回到上一层布局
        } 
    } 
};