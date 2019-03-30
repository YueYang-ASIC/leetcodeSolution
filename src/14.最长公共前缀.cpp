/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.94%)
 * Total Accepted:    64K
 * Total Submissions: 196.9K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
// sort,比较第一个和最后一个的公共前缀。
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
			return "";
		sort(strs.begin(), strs.end());
		vector<char> ret;
		string first = *strs.begin();
		string last = strs.back();
		int m = first.size(), n = last.size();
		for(int i=0,j=0;i<m&&j<n;i++,j++)
		{
			if (first[i] != last[i])
				break;
			ret.push_back(first[i]);
		}
		string res = "";
		for (auto const & c : ret)
			res += c;
		return res;

	}
};
