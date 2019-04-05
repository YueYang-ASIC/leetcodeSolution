/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (31.59%)
 * Total Accepted:    106.3K
 * Total Submissions: 330.1K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

//stack + overflow
class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		while (x)
		{
			//pop
			int pop = x % 10;
			x /= 10;

		//positive overflow
			if (ret  > INT_MAX/10 || ret  == INT_MAX/10 && pop > 7) return 0;

			//negative overflow
			if (ret  < INT_MIN/10 || ret  == INT_MIN/10 && pop > 8) return 0;
			
			//push
			ret = ret * 10 + pop;
		}
		return ret;
	}
};

