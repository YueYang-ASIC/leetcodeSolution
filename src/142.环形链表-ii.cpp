/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 *
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (33.66%)
 * Total Accepted:    11.7K
 * Total Submissions: 32.5K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 * 
 * 说明：不允许修改给定的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：tail connects to node index 1
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：tail connects to node index 0
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1], pos = -1
 * 输出：no cycle
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 你是否可以不用额外空间解决此题？
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//快慢指针，计数
//在判断是否存在环时，计数记为n。
//快指针先走n个，两个指针相遇处为入口处。

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!hasCycle(head)) //2.
			return nullptr;
		
		ListNode* fast, *slow;
		fast = slow = head; 
		while (count--)
		{
			fast = fast->next;
		} 
		while (slow!=fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	bool hasCycle(ListNode *head) {
		ListNode* fast, *slow; 
		fast = slow = head;
		while (fast&&fast->next) 
		{
			fast = fast->next->next;
			slow = slow->next;
			count++;//1.
			if (fast == slow) 
				return true;
		}
		return false;
	}

private:
	int count = 0;
};
