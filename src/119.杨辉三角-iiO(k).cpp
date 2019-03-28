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
// 1. res.size()是rowIndex,初始化一个size大小的容器，全部值为0.
// 2. res[0]永远是1.
// 3. res[rowIndex]永远是1.
// 4. 想象成一个栈，从后res[rowIndex]往前迭代，每次更新为前一个数加自身的和。因为res本身就是一个上次的结果了，为了不改变以前的结果，所以要从后往前！！这也算是一种动态规划吧，而且不用额外空间！！

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};

