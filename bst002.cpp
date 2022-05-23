#pragma once
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node(const int& value) : value(value) {}
};

class BinarySearchTree {
private:
	Node* root;

	Node* _find(Node* cursor, const int& value) {
		if (!cursor) {
			return nullptr;
		}

		if (cursor->value == value) {
			return cursor;
		}
		else {
			if (cursor->value > value) {
				return _find(cursor->left, value);
			}
			else {
				return _find(cursor->right, value);
			}
		}
	}

	void _insert(Node* cursor, const int& value) {
		Node* parent = NULL;
		while (cursor) {
			parent = cursor;
			if (parent->value > value) {
				cursor = cursor->left;
			}
			else {
				cursor = cursor->right;
			}
		}
		if (parent->value > value) {
			parent->left = new Node(value);
		}
		else if (parent->value < value) {
			parent->right = new Node(value);
		}
		else {
			cout << "이미 있는 값입니다." << endl;
		}
	}

	void _inorderTraversal(Node* cursor) {
		if (!cursor) {
			return;
		}

		this->_inorderTraversal(cursor->left);
		cout << cursor->value << " ";
		this->_inorderTraversal(cursor->right);
	}

	void _preorderTraversal(Node* cursor) {
		if (!cursor) {
			return;
		}

		cout << cursor->value << " ";
		this->_inorderTraversal(cursor->left);
		this->_inorderTraversal(cursor->right);
	}

	void _postorderTraversal(Node* cursor) {
		if (!cursor) {
			return;
		}

		this->_inorderTraversal(cursor->left);
		this->_inorderTraversal(cursor->right);
		cout << cursor->value << " ";
	}

	void _inOrder(Node* cursor) {
		Node* indexNode = cursor;

		stack<Node*> _stack;

		while (true) {

			// 현재 노드에서 최소 노드 찾기 & 경로 노드 저장
			while (indexNode != NULL) {

				// 현재 노드 저장
				_stack.push(indexNode);

				// 다음 좌측 노드 저장
				indexNode = indexNode->left;

			}
			// 스택에 노드가 있다면
			if (!_stack.empty()) {

				// 가장 늦게 이력된 노드 수령
				indexNode = _stack.top();
				_stack.pop();

				// 노드 데이터 출력
				cout << indexNode->value << " ";

				// 현재 노드의 우측
				indexNode = indexNode->right;

			}
			else 
				break;
			
		}
	}

public:
	void insert(const int& value) {
		if (!this->root) {
			this->root = new Node(value);
			return;
		}

		this->_insert(this->root, value);
	}

	Node* find(const int& value) {
		Node* cursor = this->root;
		if (!cursor) {
			return nullptr;
		}
		return this->_find(cursor, value);
	}

	void remove(const int& value) {
		Node* parent = NULL;
		Node* deleteTarget;
		Node* cursor = this->root;
		while (cursor) {
			// 노드를 삭제하기 위해서 부모값을 저장해둔다.
			if (cursor->left) {
				if (cursor->left->value == value) {
					parent = cursor;
				}
			}
			else if (cursor->right) {
				if (cursor->right->value == value) {
					parent = cursor;
				}
			}

			// 삭제할 노드를 탐색한다.
			if (cursor->value == value) {
				deleteTarget = cursor;
				break;
			}
			else if (cursor->value > value) {
				cursor = cursor->left;
			}
			else {
				cursor = cursor->right;
			}
		}

		// 자식노드가 하나도 없을 때
		if (deleteTarget->right == nullptr && deleteTarget->left == nullptr) {
			if (parent->left == deleteTarget) {
				parent->left = nullptr;
			}
			else if (parent->right == deleteTarget) {
				parent->right = nullptr;
			}
			delete deleteTarget;
			return;
		}

		// 자식노드가 왼쪽 하나만 있을 때
		if (deleteTarget->right == nullptr && deleteTarget->left != nullptr) {
			if (!parent) {
				this->root = deleteTarget->left;
				delete deleteTarget;
			}
			else {
				if (parent->left == deleteTarget) {
					parent->left = parent->left->left;
				}
				else if (parent->right == deleteTarget) {
					parent->right = parent->right->left;
				}
				delete deleteTarget;
			}
			return;
		}
		// 자식노드가 오른쪽 하나만 있을 때
		else if (deleteTarget->right != nullptr && deleteTarget->left == nullptr) {
			if (!parent) {
				this->root = deleteTarget->right;
				delete deleteTarget;
			}
			else {
				if (parent->left == deleteTarget) {
					parent->left = parent->left->right;
				}
				else if (parent->right == deleteTarget) {
					parent->right = parent->right->right;
				}
				delete deleteTarget;
			}
			return;
		}
		// 자식노드가 두 개가 있을 때
		else {
			Node* tmp;
			cursor = deleteTarget->right;
			if (cursor->left) {
				while (cursor->left) {
					tmp = cursor;
					cursor = cursor->left;
				}

				int tmpValue = tmp->left->value;
				tmp->left->value = deleteTarget->value;
				deleteTarget->value = tmpValue;

				delete tmp->left;
				tmp->left = nullptr;
			}
			else if (cursor->right) {
				while (cursor->right) {
					tmp = cursor;
					cursor = cursor->right;
				}

				int tmpValue = tmp->right->value;
				tmp->right->value = deleteTarget->value;
				deleteTarget->value = tmpValue;

				delete tmp->right;
				tmp->right = nullptr;
			}
			return;
		}
	}

	void printTree() {
		this->_inorderTraversal(this->root);
		cout << endl;
	}

	void printTreeStack() {
		this->_inOrder(this->root);
		cout << endl;
	}


};

int main() {

	BinarySearchTree* bst = new BinarySearchTree();

	bst->insert(90);
	bst->insert(5);
	bst->insert(8);
	bst->insert(86);
	bst->insert(10);
	bst->insert(15);
	bst->insert(20);
	bst->insert(50);
	bst->insert(54);
	bst->insert(66);
	bst->insert(69);
	bst->insert(25);
	bst->insert(30);
	bst->insert(40);
	bst->insert(83);

	cout << bst->find(66)->value << " 찾았습니다 !" << endl;

	bst->printTree();

	bst->printTreeStack();


	return 0;
}