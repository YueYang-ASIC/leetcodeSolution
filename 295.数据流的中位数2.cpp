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
//开两个stl的优先队列-maxheap和minheap，用来存前后一半的数
//细节：
//1.如果num小于maxheap.top(),说明在num小的那一半里，放入最大堆，如果不这样的话，可能会排序失败。
//2.假定maxheap永远大于或者等于minheap的数量，这样如果两个堆相等就是平均值。不相等就是maxheap.top
//3.利用AVL的思想，保证两个堆的深度之差不超过1，如果超过1,就把max堆顶放入min堆中

class MedianFinder {
private:
	priority_queue<long> maxheap;
	priority_queue<long, vector<long>, greater<long>> minheap;

public:
	/** initialize your data structure here. */
	MedianFinder() {
	}

	void addNum(int num) {
		//细节：如果num小于maxheap.top(),说明在num小的那一半里，放入最大堆，如果不这样的话，可能会排序失败。
		if (maxheap.size() == 0 || num < maxheap.top())
		{
			maxheap.push(num);
		}
		else
			minheap.push(num);
		//平衡二叉树
        if (minheap.size()> maxheap.size())
		{
			maxheap.push(minheap.top());
			minheap.pop();
		}
        else if (maxheap.size()>1 + minheap.size())
		{
			minheap.push(maxheap.top());
			maxheap.pop();
		}  
	}

	double findMedian() {
		return maxheap.size()>minheap.size() ? maxheap.top() : (maxheap.top() + minheap.top()) / 2.0;
	}
};

