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
// 动态规划。用循环做。
// F(i)=nums[i](F(i-1)<=0);
// F(i)=nums[i]+F(i-1)(F(i-1)>0)
// 细节：nums只有{-1}时，所以开始sum=nums[0]，然后从第二个开始循环。

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
        return 0; 
        int sum=nums[0];
        int maxsum=sum;  
        for(auto it=nums.begin()+1;it!=nums.end();it++)
        {
            sum = max(*it, (sum + *it));
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};

