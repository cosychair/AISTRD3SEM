#pragma once
#include "Iterator.h"
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
class BinaryTree{
private:
	class Node {
	public:
		int key;
		Node *right;
		Node *left;
		Node(int key = 0, Node *right = nullptr, Node *left = nullptr) :key(key), right(right), left(left) {}
		~Node() {
			if(right) delete right;
			if(left) delete left;
		}
		Node *&getChild(const int childKey) {
			return childKey < key ? left : right;
		}
	};
	Node *root;
	int num, maxnum;//счетчик тегов(ключей), максимальный тег
	//Node* makeNode(int depth);//создание узла дерева с глубиной depth
	//Функция ищет подходящий лист для встави его вместо условного корня
	Node *firstAppropriateLeaf(Node *previous, Node *current, const int lowerBound, const int upperBound);
public:
	BinaryTree(Node *root = nullptr, int num = 0, int maxnum = 0):root(root), num(num), maxnum(maxnum){}
	~BinaryTree();

	BinaryTree createRandomBinaryTree(int depth);//создание дерева случайных размеров 

	Node *getRoot();
	bool contains(const int key); // поиск элемента в дереве по ключу
	void insert(const int key); // добавление элемента в дерево по ключу
	void remove(const int key); // удаление элемента дерева по ключу
	
	class BfsIterator : public Iterator {
		deque<BinaryTree::Node*> currentNodes;
	public:
		BfsIterator(Node *root) {
			currentNodes.push_back(root);
		}
		void next();
		int current();
		bool hasNext();
	};

	class DfsIterator : public Iterator {
		deque<BinaryTree::Node*> currentNodes;
	public:
		DfsIterator(Node *root) {
			Node *current = root;
			currentNodes.push_back(root);
			while (current = current->left)
				currentNodes.push_back(current);
		}
		void next();
		int current();
		bool hasNext();
	};

	DfsIterator *createDfsIterator(); // создание итератора, реализующего методы обхода в глубину (depth-first traverse)
	BfsIterator* createBfsIterator(); // создание итератора, реализующего методы обхода в ширину (breadth-first traverse)
	
	void printBinaryTreeIntoConsole(Node *current, size_t level); // красивый вывод дерева в консоль
};
