/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (29.45%)
 * Total Accepted:    4K
 * Total Submissions: 13.2K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<string> a;
        for(auto  const & item:nums)
        {
            a.push_back(to_string(item));
        }

        sort(a.begin(),a.end(),[](string & a,string &b){return a+b>b+a;});

        string ret;
        for(auto const & item:a)
        {
            ret+=item;
        }
        
        if(ret[0]=='0')
        return "0";
        else 
        return ret;
        
    }
};

