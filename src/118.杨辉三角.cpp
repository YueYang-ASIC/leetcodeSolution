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
//迭代每行，每行resize,头尾是1，中间是上层的和
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret(numRows);//1.记得初始化，不然开始就数组越界
		for (int row = 0; row<numRows; row++)
		{
			ret[row].resize(row + 1);//2.注意是row+1
			ret[row][0] = ret[row][row] = 1;//3.头尾是1,因为size是row+1,所以尾是row,不是row-1

			for (int col = 1; col<row; col++)
			{
				ret[row][col] = ret[row - 1][col - 1] + ret[row - 1][col];//4.中间是上层之和
			}
		}
		return ret;
	}
};

