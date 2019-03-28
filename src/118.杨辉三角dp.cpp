/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (59.80%)
 * Total Accepted:    18.9K
 * Total Submissions: 31.2K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
//dp,O(n^2)space,O(n^2)time
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		if (!numRows)
			return ret;
		ret.push_back(vector<int>(1,1));//0 row,1.vector<int> (1)写错，塞进去的是0
		for (int row = 1; row<numRows; row++)//1~numrows-1 row
		{
			vector<int> sub;
			sub.push_back(1);//first col
			for(int col=1;col<row;col++)
				sub.push_back( ret[row - 1][col - 1] + ret[row - 1][col]) ;//middle col
			sub.push_back(1);//last col
			ret.push_back(sub); 
		} 
		return ret;
	}
};

