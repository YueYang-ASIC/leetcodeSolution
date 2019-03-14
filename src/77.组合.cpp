/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (65.43%)
 * Total Accepted:    7K
 * Total Submissions: 10.7K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
//回溯。
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> out;
        Helper(n,k,ret,out,1);
        return ret; 
    }

    void Helper(int n, int k ,vector<vector<int>> &ret,vector<int>& out,int start)
    {
        if(out.size()==k)
        {
            ret.push_back(out);
            return;
        }
        for(int i = start;i<=n;i++)
        {
            
            out.push_back(i);
            Helper(n,k,ret,out,i+1); //开始下级，从i的后面开始。因为是组合不是排列，所以之前取过的数就不取了

            out.pop_back();//一次回溯
        } 
    }
};
  
