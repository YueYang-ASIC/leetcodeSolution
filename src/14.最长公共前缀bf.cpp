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
// 2Darray。纵向遍历。
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return ""; 
		vector<char> ret;

		vector<vector<char>> _2DArray;
		//string to vector<char>
		for (auto const & string : strs)
		{
			vector<char> array;
			for(auto const & c :string)
			{
				array.push_back(c);
			}
			_2DArray.push_back(array);
		}
		 
		
		for (int i = 0,j= 0;i < _2DArray[0].size();  i++)//cols
		{
			char cur = _2DArray[j][i];
			for (; (j < _2DArray.size()); j++)//rows
			{
				if (strs[j].length() <= i||_2DArray[j][i] != cur)//&&strs[j].length()>i vector越界
					break; 
			} 
			if(j==_2DArray.size())
				ret.push_back(cur);
                else break;
			j = 0;// vector越界			
		}

		string res = "";
		for (auto const & c : ret)
			res += c;
		return res;
	}};