/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (46.45%)
 * Total Accepted:    19.8K
 * Total Submissions: 42K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
// 1. 考察字符串链接，动态规划。
// 2. 将字符转为int的方法就是-'0'。
// 3. 二进制运算，进位的用法，定义一个标记代表是否需要进位处理。求商表示进位，求余表示剩下的结果。

// - 计算出两个字符串的长度，从每个字符串最后一个元素开始，低位对齐，向前遍历。
// - 开一个字符串ret来保存处理完每一位后的结果。
// - 如果该位有字符，就将字符转化为数字，方法是减字符'0'；如果没有数字就直接取int的0.
// - 每一位的结果，等于，两个字符之和+是否进位的标志，记为sum。再将sum转为2进制，用位运算向右移一位，得到的是进位标志；对sum取模，得到的是该位的结果。最后将该位的结果连接到原来的结果ret前面。 
// - 返回的时候，判断进位标志是否为1，如果是的话，在ret前面连接上一个字符串“1”即可。

class Solution {
public:
	string addBinary(string a, string b) { 
		int max = a.size()-1, min = b.size()-1;
		int numa, numb,sum,carry=0;
		string ret="";
		while (max>=0 || min>=0 )//3.
		{
			numa = (max >= 0) ? a[max--] - '0' : 0;//2.
			numb = (min >= 0) ? b[min--] - '0': 0;
			sum = numa + numb+ carry ;
			carry = sum >> 1;
			ret = to_string(sum % 2)+ret;//4.
		}

		return carry==1?"1"+ret:ret;//1 
	}
};
