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
//  */
// 执行用时: 40 ms, 在Two Sum的C++提交中击败了59.14% 的用户
// 内存消耗: 6.8 MB, 在Two Sum的C++提交中击败了0.82% 的用户
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash;
        
        for (int i = 0; i < nums.size(); i++) {
            auto iter = hash.find(target - nums[i]);//用hash.find，有搜到返回it,没有返回.end

            if (iter != hash.end()) {
                return vector{iter->second, i};//it.first==key,it.second==val
            };
            hash[nums[i]] = i;// 数组值作为key。数组索引作为val。
        }
        return vector<int>();
    }
};
