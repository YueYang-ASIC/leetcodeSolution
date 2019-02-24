#pragma once
#ifndef _BSTREE_H_
#define _BSTREE_H_
#include <vector>
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Tree
{
public:
	Tree();
	Tree(std::vector<int> &in);
	~Tree();
	TreeNode *root;
	static void print_tree(TreeNode *root);
	TreeNode *insert_ordered(const std::vector<int> &in, int l, int r);
	void insert(const int &x);
	void insert(const int &x, TreeNode *&parent);
	bool is_empty();
	void print();
	void push(std::vector<int> &in);
};
#endif //!_BSTREE_H_