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
//  分治法。2*O(n/2)+O(1)=O(n)
//divide：用递归来分别求左右子集的max
//merge:用dp来从左右分别线性探索，加上mid
//最后找到divide和merge中最大的就是要求的值。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }

        //divide:
        int m = l + (r - l) / 2;
        int lmax = maxSubArray(nums, l, m - 1);//left
        int rmax = maxSubArray(nums, m + 1, r);//right
        int partmax = max(lmax, rmax);//not including mid
        
        //Merge:
        int ml= 0,mr = 0;
        //left-DP:O(n/2)
        for (int i = m - 1, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        //right-DP:O(n/2)
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        //Merge-including mid,for continuous subset:O(1)
        int contmax=ml + mr + nums[m];

        return max(partmax,contmax);
        //2*O(n/2)+O(1)=O(n)
    }
};
