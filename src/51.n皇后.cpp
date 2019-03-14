/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (58.80%)
 * Total Accepted:    4.7K
 * Total Submissions: 8K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> myqueen(n,string(n,'.'));
        Helper(ret,myqueen,n,0);
        return ret;
    }

    void Helper(vector<vector<string>>&ret,vector<string> &myqueen,int n,int row){
        if(row==n)
        {
            ret.push_back(myqueen);
            return;
        }
        for(int col=0;col<n;col++)//排序的是col
        {
            if(!IsValid(myqueen,n,row,col))//基于条件对string进行排序。col是变量
                continue;
            myqueen[row][col]='Q';
            Helper(ret,myqueen,n,row+1);//往myqueen的下一个string,所以是row+1
            myqueen[row][col]='.';
        }
    }

    bool IsValid(vector<string> myqueen,int n,int row,int col){
         //row
        //  for(int c = col; c >=0; c--)
        //  {
        //      if(myqueen[row][c]=='Q')
        //      return false;
        //  }
        //因为已经Helper(row+1),所以一行中只有一个Q是固定了的。
         
         
         //col
         for(int r=row;r>=0;r--)
         {
             if(myqueen[r][col]=='Q')
                return false;
         }

         //45°
         for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
         {
             if(myqueen[i][j]=='Q')
                return false;
         }

         //135°
         for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
         {
             if(myqueen[i][j]=='Q')
                return false;
         }

         return true;
    }
};

