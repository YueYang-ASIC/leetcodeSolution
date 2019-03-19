/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.44%)
 * Total Accepted:    2.4K
 * Total Submissions: 7.9K
 * Testcase Example:  '3'
 *
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
 * 
 * 注意:
 * n 是正数且在32为整形范围内 ( n < 2^31)。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 3
 * 
 * 输出:
 * 3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * 11
 * 
 * 输出:
 * 0
 * 
 * 说明:
 * 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
 * 
 * 
 */
class Solution {
public:
	int findNthDigit(int n) {
        //1.计算位数
        int digit=1;
        long base=9;
        while(n-base*digit>0)
        {
            n-=base*digit;
            base*=10;
            digit++;
        }

        //2.找到num
        int nth=n/digit;
        int index=n%digit;
        int num=0;
        num=pow(10,digit-1)+((index==0)?nth-1:nth);

        //3.转换字符串
        if(index==0)
            index=digit;//很容易忘掉
        string a=to_string(num);
        a=a[index-1];
        return stoi(a);

	}
};

