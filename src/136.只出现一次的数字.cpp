/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (57.87%)
 * Total Accepted:    56.2K
 * Total Submissions: 93.5K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */
//hash table O(1)time O(n)space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		unordered_map<int, int> m;
		for (int i = 0; i<nums.size(); i++) 
			++m[nums[i]]; 
		for (int i = 0; i<nums.size(); i++) 
			if (m[nums[i]] == 1) return nums[i]; 
		return 0;
	}
};

