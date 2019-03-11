/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (56.90%)
 * Total Accepted:    26K
 * Total Submissions: 44.9K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
//法一。快排。找中位数。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())
        return 0;
        std::sort(nums.begin(),nums.end());
        int result=nums[nums.size()/2];

        int count=0;
        for(const auto &i :nums)
        {
            if(i==result)
            count++;
        }
        return count>nums.size()/2?result:0;
    
    }
};

