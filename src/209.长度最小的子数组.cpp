/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (36.91%)
 * Total Accepted:    7.7K
 * Total Submissions: 20.6K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
 * 
 * 示例: 
 * 
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 */
//O(n)。双指针
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int _slow = 0, _fast = 0, _sum = 0, _min_count = INT_MAX;
		while (_fast != nums.size())
		{
			_sum += nums[_fast];
			while (_sum >= s)//不用if，_slow指针会多移动几个，count会一直更新
			{
				_min_count = min(_min_count, _fast-_slow+1);
				_sum -= nums[_slow];
				_slow++;
			}
			_fast++;
		}
		return _min_count==INT_MAX?0:_min_count;//如果一次都没有更新，返回0
	}
};