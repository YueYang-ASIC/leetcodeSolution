/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (52.04%)
 * Total Accepted:    10K
 * Total Submissions: 19.2K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 * 
 * 
 */
//two pointers
class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		if (nums.empty()) return 0;
		int _fast = 0, _slow = 0,sign=0, _max = 0;
		while(_fast!=nums.size())
		{ 
			if (nums[_fast] == 1)
			{
				if (sign == 0)
				{
					_slow == _fast;
					sign = 1;				
				} 
				
			}
			else
			{
				_slow = _fast +1;
				sign = 0;
			}
			_max = max(_fast - _slow + 1, _max);
			_fast++;

		}
		return _max;
	}
};