/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.13%)
 * Total Accepted:    241.1K
 * Total Submissions: 542.6K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.empty())
        return nums;
        vector<int> ret; 
        unordered_map<int,int> map;//这里要用无序查找
        int i = 0;
        while(!nums.empty())        
        {
            int key=*nums.begin();
            map[key]=target-key;
            nums.erase(nums.begin());//这里删了一个元素,loop里面会迭代两次，所以不能用for(auto :)
            int j = i+1;
            for(auto val : nums)
            {
                if(val==map[key])
                    {
                        ret.push_back(i);
                        ret.push_back(j);
                        return ret;
                    }
                    j++;
            }           
            i++; 
        }
        return ret;
    }
};
