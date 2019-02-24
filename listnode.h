#pragma once
#ifndef _LISTNODE_H_
#define _LISTNODE_H_
#include <iostream>
#include <vector>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x = 0, ListNode *p = nullptr) : val(x), next(nullptr) {};
};
// �����ã���ӡ��������
//void print_list(ListNode *head)
//{
//	while (head != nullptr)
//	{
//		std::cout << head->val << " ";
//		head = head->next;
//	}
//	std::cout << std::endl;
//}
class List
{
public:
	ListNode *head, *tail;
	int pos;
	List()
	{
		head = nullptr;
		tail = nullptr;
	};
	// ��vector���г�ʼ��
	List(const std::vector<int> &in)
	{
		head = nullptr;
		tail = nullptr;
		for (auto it : in)
			this->insert(it);
	};
	~List() {};
	// ����ڵ�
	void insert(int x)
	{
		if (head == nullptr)
		{
			head = tail = new ListNode(x);
			head->next = nullptr;
			tail->next = nullptr;
		}
		else
		{
			ListNode *p = new ListNode(x);
			tail->next = p;
			tail = p;
			tail->next = nullptr;
		}
	};
	//void print()
	//{
	//	print_list(head);
	//}
};
#endif //!_LISTNODE_H_