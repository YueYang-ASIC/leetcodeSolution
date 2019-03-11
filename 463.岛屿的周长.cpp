/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 *
 * https://leetcode-cn.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (58.93%)
 * Total Accepted:    4.6K
 * Total Submissions: 7.7K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
 * 
 * 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 * 
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100
 * 。计算这个岛屿的周长。
 * 
 * 
 * 
 * 示例 :
 * 
 * 输入:
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 * 
 * 输出: 16
 * 
 * 解释: 它的周长是下面图片中的 16 个黄色的边：
 * 
 * 
 * 
 * 
 */
//如果这个格子有岛屿，只有在该格子是在岛屿边界处，就计算一条边，
//岛屿边界处：在数组最左边，或者左边格子没有岛屿，同理，判断上下左右四个方向的格子。
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
         if(grid.empty()||grid[0].empty())
        {
            return 0;
        }
        int rows=grid.size();
        int cols=grid[0].size();
        int len=0;
        for(int row=0;row<rows;row++)
        {
            for(int col=0;col<cols;col++)
            {
                if(grid[row][col]==0) continue;
                
                if(row==0||grid[row-1][col]==0) len++;//上
                if(col==0||grid[row][col-1]==0) len++;//左
                if(row==rows-1||grid[row+1][col]==0) len++;//下，这里注意数组越界
                if(col==cols-1||grid[row][col+1]==0) len++;//右
            }
            
        }
        return len;
    }
};

