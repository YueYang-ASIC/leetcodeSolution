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
//公式法：C(K,N)=C(K-1,N-1)+C(K,N-1)。
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n<k||k<0) return {};
        if(k==0) return {{}};

        //保存从n-1里面选k-1个的结果res.再在res中每个数组末尾加最后一个数(n) 
        vector<vector<int>> res=combine(n-1,k-1);
        for(auto &a:res) a.push_back(n);

        //保存从n-1里面选k个的结果。将结果中的每个数组都push进res结果集里。
        for(auto a:combine(n-1,k)) res.push_back(a);
        return res;
    }

};
  
