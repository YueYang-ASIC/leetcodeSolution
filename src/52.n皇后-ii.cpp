/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (69.78%)
 * Total Accepted:    3.3K
 * Total Submissions: 4.8K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
class Solution {
public:
    int totalNQueens(int n) {
        int count=0;
        vector<string> out(n,string(n,'.'));//初始化
        Helper(count,out,n,0);
        return count;
    }

    void Helper(int &count,vector<string> &out,int n,int row)
    {
        if(n==row)
        {
            count++;
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(valid(out,n,row,col))
                {
                    out[row][col]='Q';
                    Helper(count,out,n,row+1);
                    out[row][col]='.';
                }
        }

    }

    bool valid(vector<string> out,int n, int row, int col)
    {
        //检查是否同一列
        for(int r=row-1;r>=0;r--)
        {
            if(out[r][col]=='Q')
            return false;
        }
        //检查是否对角线 45°
        for(int r=row-1,c=col-1;r>=0&&c>=0;r--,c--)
        {
            if(out[r][c]=='Q')
            return false;
        }

        //检查135°
        for(int r=row-1,c=col+1;r>=0&&c>=0;r--,c++)
        {
            if(out[r][c]=='Q')
            return false;
        }
        return true;
    }
};

