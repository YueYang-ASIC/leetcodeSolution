/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (37.64%)
 * Total Accepted:    43.8K
 * Total Submissions: 115.2K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */
//暴力搜索法。O(m(m-n+1))=O(m*n)
class Solution {
public:
	int strStr(string haystack, string needle) {
		int p = needle.size(), t = haystack.size();
		if (!p) return 0;
		if (p>t) return -1;
		for (int index = 0; index <= t - p; index++)
		{
			for (int i=index,j = 0; j < p; j++,i++)
			{
				if (haystack[i] != needle[j])
					break;
				if (j == p-1)
					return index;
			} 
		} 
		return -1;
	}
};
