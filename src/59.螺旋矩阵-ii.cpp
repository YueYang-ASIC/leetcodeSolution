/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (70.65%)
 * Total Accepted:    7.4K
 * Total Submissions: 10.4K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
//
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int num = 1;
		int top = 0, right = n - 1, bottom = n - 1, left = 0;
 
		vector<vector<int>> ret(n,vector<int>(n));
		while (num<=n*n)
		{
			//top
			for (int col = left; col <= right; col++) 
				ret[top][col] = num++;
			if (++top > bottom) break;

			//right
			for (int row = top; row <= bottom; row++) 
				ret[row][right] = num++;
			if (--right < left) break;

			//bottom
			for (int col = right; col >= left; col--) 
				ret[bottom][col] = num++;
			if (--bottom < top) break;

			//left
			for (int row = bottom; row >= top; row--) 
				ret[row][left] = num++;
			if (++left > right) break;
		}
		return ret;
	}
};

