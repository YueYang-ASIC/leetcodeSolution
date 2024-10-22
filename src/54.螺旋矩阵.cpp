/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (33.79%)
 * Total Accepted:    10.5K
 * Total Submissions: 30.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */
//上右下左四个方向，依次打印。每次打印完一行后更新变量，判断越界。
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return{ };
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<int> sprial;
		int top = 0, right = cols - 1, bottom = rows - 1, left = 0;
		while (sprial.size()<cols*rows)
		{
			//top row:left to right
			for (int col = left; col <= right; col++) sprial.push_back(matrix[top][col]);
			if (++top > bottom) break;
			
			//right col: top to bottom
			for (int row = top; row <= bottom; row++) sprial.push_back(matrix[row][right]);
			if (--right < left) break;
			
			//bottom row: right to left
			for (int col = right; col >= left; col--) sprial.push_back(matrix[bottom][col]);
			if (--bottom < top) break;

			//left col: bottom to top 
			for (int row = bottom; row >= top; row--) //row>=top不是<=容易弄错！！
				sprial.push_back(matrix[row][left]);
			if (++left > right) break;
		}

		return sprial;
	}
};

