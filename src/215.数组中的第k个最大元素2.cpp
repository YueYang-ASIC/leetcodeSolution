/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (56.23%)
 * Total Accepted:    16.6K
 * Total Submissions: 29.4K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */
//法2.O(n)。partition。原地划分
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if(nums.empty()||k>nums.size())
        return 0;

        k=nums.size()-k;//从小到大排列后的k
        QuickSort_Recur(nums,0,nums.size()-1);
 
        return nums[k];
    }
     void QuickSort_Recur(vector<int>& nums, int low, int high)
    { 
        if(low<high)
        {
            int index = Partition(nums,low,high);//找到一个基准，并将所有小于基准的数放在基准左边。
            QuickSort_Recur(nums,low,index-1);
            QuickSort_Recur(nums,index+1,high);
        }
    }

    int Partition(vector<int>& nums,int start,int end)
    {
        if(start<0||end>=nums.size())
          return 0;

        int pivot = random(start,end);
        swap(&nums[pivot],&nums[end]);//把基准移到尾部
        
        int left = start -1;//最左边原地划分一个子集
        for(int i =start;i<end;i++)
        {
            if(nums[i]<nums[end])//如果小于基准就放入子集中
            {
                left++;
                if(left!=i)
                    swap(&nums[i],&nums[left]);
            }
        }

        left++;
        swap(&nums[left],&nums[end]);//将最尾部的基准放在左子集的下一个位置

        return left;//返回基准
     }
    int random(int min,int max)
    {
        int random =rand()%(max-min+1) +min;
        return random;
    }
    void swap(int *in1,int* in2){
        int temp=*in1;
        *in1=*in2;
        *in2=temp;
    }
};

