/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字1的个数
 *
 * https://leetcode-cn.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (24.83%)
 * Total Accepted:    1.2K
 * Total Submissions: 4.6K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 * 
 * 示例:
 * 
 * 输入: 13
 * 输出: 6 
 * 解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
 * 
 */
//公式法：n/(d*10)*d + min(d,max(0,n\%(10*d)-d+1))
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0)
        return 0;    
        int ret=0;
        for(long long degree=1;degree<=n;degree*=10)       
  			ret += n /(degree*10)*degree + min(degree, max((long long)0, n % (10 * degree) - degree+1));
        return ret;
    }
};

