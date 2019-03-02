/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (66.03%)
 * Total Accepted:    15.2K
 * Total Submissions: 22.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
//递归。回溯。填空格法。访问数组标记。
class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) { 
        vector<vector<int>> ret;
        if(num.size()==0) return ret;
        vector<int> out,visited(num.size(),0);
        Helper(num,out,ret,0,visited);
        return ret;
    }
    void Helper(vector<int> num,vector<int> & out,
        vector<vector<int>> &ret,int &index,vector<int> &visited)//int index不能用引用，他是const
        {
            if(index == num.size())
            {
                //一次排列完成
                ret.push_back(out);
                return;
            }
            for(int i =0 ;i<num.size();i++)
            {
                if(visited[i]==1)
                    continue;
                visited[i]=1;
                out.push_back(num[i]);

                Helper(num,out,ret,index+1,visited);

                out.pop_back();
                visited[i]=0;
            }
        }
};