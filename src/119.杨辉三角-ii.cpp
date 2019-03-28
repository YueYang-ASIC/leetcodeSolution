/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (53.91%)
 * Total Accepted:    11.7K
 * Total Submissions: 21.5K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
//dp.迭代。清空，塞1，塞中间，塞1，sub=ret
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex < 0)
			return{};
		if (rowIndex == 0)
			return{ 1 };
		if (rowIndex == 1)
			return{ 1,1 };
		 
		vector<int> ret,sub(2,1);
		for(int row=2;row<=rowIndex;row++)
		{ 
			ret = {};
			ret.push_back(1);
			for (int col =0; col<row-1; col++)//不要用迭代器，用下标做
			{ 				
				ret.push_back(sub[col]+sub[col+1]); 
			}
			ret.push_back(1);
			sub = ret;
		}

		return ret;
	}
};

