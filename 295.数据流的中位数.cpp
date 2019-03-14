/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (33.39%)
 * Total Accepted:    1.6K
 * Total Submissions: 4.6K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
 * 
 * 例如，
 * 
 * [2,3,4] 的中位数是 3
 * 
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 
 * 设计一个支持以下两种操作的数据结构：
 * 
 * 
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 
 * 
 * 示例：
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 进阶:
 * 
 * 
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 
 * 
 */
//开两个stl的优先队列-maxheap。small放前一半大的数，large放后一半大的数。
//为了让他们的顺序从小到大不变，small的用原数存，large的用负数存。
//增删O(logn)，查找O(1)
//细节：
//1.如果是奇数大小，small.top()就是要求的中位数。如果是偶数，(small.top()-large.top())/2就是中位数，是减不是加
//2.优先队列的类型是long. -2^31 (which negated is itself, when using 32-bit ints), I use integer types larger than 32 bits.
//3.(small.top()-large.top())/2.0。要除以2.0，否则返回的是整数
class MedianFinder {
private:
 std::priority_queue<long> small,large;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
          }
    
    void addNum(int num) {
        small.push(num);//O(logn)

        large.push(-small.top());//O(logn)
        small.pop();//O(logn)

        //保证small大于或者等于large的个数
        if(small.size()<large.size())
        {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size()>large.size()? small.top():(small.top()-large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

