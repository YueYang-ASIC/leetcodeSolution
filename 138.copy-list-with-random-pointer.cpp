/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (23.92%)
 * Total Accepted:    3.6K
 * Total Submissions: 15.1K
 * Testcase Example:  '{}'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 
 * 要求返回这个链表的深度拷贝。 
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(!head)
            return head;

        //clone
        RandomListNode* oriNode=head;
        while(oriNode)
        {
            //copy
            RandomListNode* cloneNode=new RandomListNode(0);
            cloneNode->label=oriNode->label;
            cloneNode->next=oriNode->next;
            cloneNode->random=nullptr;
            //link
            oriNode->next=cloneNode;
            //next
            oriNode=cloneNode->next;            
        }
           
        //copy random
        oriNode=head;
        while(oriNode)
        {
            RandomListNode* cloneNode=oriNode->next;
            //copy
            if(oriNode->random)
            {
                cloneNode->random=oriNode->random->next;
            }
            //next
            oriNode=cloneNode->next;
        }
        
        //depart
        oriNode=head;
        RandomListNode* cloneNode=head->next;
        RandomListNode* cloneHead=cloneNode;//return
        
        while(oriNode)
        {
            oriNode->next=cloneNode->next;
            oriNode=oriNode->next;
            
            if(!oriNode)
                break;
            cloneNode->next=oriNode->next;
            cloneNode=cloneNode->next;
        }
        
        return cloneHead;
    }  
};
