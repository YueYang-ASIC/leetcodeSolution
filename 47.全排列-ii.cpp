/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (50.41%)
 * Total Accepted:    7.4K
 * Total Submissions: 14.6K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
//set
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ret;
        if(nums.empty())
            return vector<vector<int>>();
        Helper(nums,0,ret); 
        return vector<vector<int>>(ret.begin(),ret.end());

    }

    void Helper(vector<int> nums,int start,set<vector<int>> &ret)
    {
        if(start==nums.size())
        {
            ret.insert(nums);
            return;
        }
        for(int i=start;i<nums.size();i++)
        {
            swap(nums[i],nums[start]);
            Helper(nums,start+1,ret);
            swap(nums[i],nums[start]);
        }
    } 
};

