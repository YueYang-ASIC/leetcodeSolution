/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (38.68%)
 * Total Accepted:    3.6K
 * Total Submissions: 8.7K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */
 //动态规划
class Solution {
    private:
    int t2=0,t3=0,t5=0;//开三个队列。分别存放2，3，5的倍数。
public:
    int nthUglyNumber(int n) {
        if(n<=6) return n; //前6个都是丑数
    vector<int> uglynum;//保存丑数
    uglynum.push_back(1);//将第一个丑数塞入容器

    while(uglynum.size()<n){
        int k = min(min(uglynum[t2]*2,uglynum[t3]*3),uglynum[t5]*5);//uglynum容器中的每一个数都要经过2，3，5的洗礼，取到接受洗礼的数中最小的一个作为勇者.
        uglynum.push_back(k);//放入丑数容器中。
        if(k==uglynum[t2]*2) t2++;//如果被选中的勇者是经过2洗礼的，那么就让2取洗礼容器中的下一个数，所以2的指针++
        if(k==uglynum[t3]*3) t3++;//为什么不用if else判断呢，因为在选中最小的数中，是最小公倍数，所以有可能因子包含2，3，5，所以只要判断是不是当前指针所指数的倍数就好，如果是的话，就要洗礼丑数容器中的下一个数。
        if(k==uglynum[t5]*5) t5++;
    }
    return uglynum.back();//传回容器的最后一个
    }
};

