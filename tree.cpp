#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

class TreeNode
{
private:
	int DATA;
	TreeNode *left;
	TreeNode *right;

public:
	TreeNode(int data, TreeNode *l = NULL, TreeNode *r = NULL)
	{
		this->DATA = data;
		this->left = l;
		this->right = r;
	};
	int getData()
	{
		return this->DATA;
	}
	TreeNode *getLeft()
	{
		return this->left;
	}
	TreeNode *getRight()
	{
		return this->right;
	}
};

class TreeTraversal
{
private:
public:
	static void PreOrder(TreeNode *n)
	{
		if (n == NULL)
			return;
		printf("%d ", n->getData());
		PreOrder(n->getLeft());
		PreOrder(n->getRight());
	}
	static void InOrder(TreeNode *n)
	{
		if (n == NULL)
			return;
		InOrder(n->getLeft());
		printf("%d ", n->getData());
		InOrder(n->getRight());
	}
	static void PostOrder(TreeNode *n)
	{
		if (n == NULL)
			return;
		PostOrder(n->getLeft());
		PostOrder(n->getRight());
		printf("%d ", n->getData());
	}
	static void LevelOrder(TreeNode *root)
	{
		if (root == NULL)
			return;

		queue<TreeNode *> que;
		TreeNode *item;
		que.push(root);
		while (!que.empty())
		{
			item = que.front();
			cout << item->getData() << " ";
			if (item->getLeft() != NULL)
				que.push(item->getLeft());
			if (item->getRight() != NULL)
				que.push(item->getRight());
			que.pop();
		}
	}
};

int main()
{
	TreeNode n7 = TreeNode(7);

	TreeNode n4 = TreeNode(4);
	TreeNode n5 = TreeNode(5, &n7, NULL);
	TreeNode n6 = TreeNode(6);

	TreeNode n3 = TreeNode(3, NULL, &n6);
	TreeNode n2 = TreeNode(2, &n4, &n5);

	TreeNode n1 = TreeNode(1, &n2, &n3);

	printf("PreOrder :");
	TreeTraversal::PreOrder(&n1);

	printf("\n\nInOrder : ");
	TreeTraversal::InOrder(&n1);

	printf("\n\nPostOrder : ");
	TreeTraversal::PostOrder(&n1);

	printf("\n\nLevelOrder : ");
	TreeTraversal::LevelOrder(&n1);

	return 0;
}
