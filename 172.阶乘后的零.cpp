/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (36.83%)
 * Total Accepted:    8.7K
 * Total Submissions: 23.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */
//尾数为0，只能是10的倍数，10是由5*2得来的。因为阶乘中，只要是偶数就有2，所以计算5的倍数的个数就好。
//因为5^2有两个5的因子，所以会多配对一个偶数，即加上5^2的倍数的个数。
//由此推得，0的个数等于5、5^2、5^3……的个数之和。
//用递归就一行搞定。
class Solution {
public:
    int trailingZeroes(int n) {
         return n==0?0:n/5+trailingZeroes(n/5);
    }
};

