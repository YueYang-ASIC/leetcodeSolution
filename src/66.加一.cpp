/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (37.48%)
 * Total Accepted:    42.9K
 * Total Submissions: 113K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */
//递归 O(n)space,O(n)time
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//3.忘了考虑首位是9的情况！
		if (digits.size() == 1&& digits.back() == 9)
		{
			return{ 1,0 };
		}

		if (digits.back() != 9)
		{
			digits.back() += 1;
			return digits;
		}
		else 
		{ 
			digits.erase(digits.end() - 1);//1.是迭代器啊!!不是左值！！
			
			digits=plusOne(digits);//2.只是算前面进位的数
			digits.push_back(0);//最后0添上
			return digits;
		}
	
	}
};
