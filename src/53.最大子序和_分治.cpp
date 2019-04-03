/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.37%)
 * Total Accepted:    41.2K
 * Total Submissions: 95.7K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return maxHelper(nums, 0, nums.size() - 1);
	}
private:
	int maxHelper(vector<int> &nums, int l, int r)
	{
		if (l > r) return INT_MIN;

		int mid = l + (r - l) / 2;
		int l_max = maxHelper(nums, l, mid - 1);
		int r_max = maxHelper(nums, mid + 1, r);

		int sum = nums[mid],m_max=nums[mid];

		//link left 
		for (int i = mid - 1; i >= l; --i)
		{
			sum += nums[i];
			m_max = max(m_max, sum);
		}

		sum = m_max;
		//link right  
		for (int i = mid + 1; i <= r; i++)
		{ 
			sum += nums[i];
			m_max = max(m_max, sum);
		}
 		
		return max(max(l_max,r_max ),m_max);
	}
};

