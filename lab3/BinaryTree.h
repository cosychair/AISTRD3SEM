#pragma once
#include "Iterator.h"
#include <iostream>
#include <iomanip>
//#include <queue>
#include "Queue.h"
using namespace std;
class BinaryTree{
private:
	class Node {
	public:
		int key;
		Node *right;
		Node *left;
		Node(int key = 0, Node *right = nullptr, Node *left = nullptr){
			this->key = key;
			this->right = right;
			this->left = left;
		}
		~Node() {
			if (right) delete right;
			if (left) delete left;
		}
		Node *&getChild(const int childKey) {//Возвращает левый узел, если значение ChildKey меньше чем значение key узла, иначе правый
			return childKey < key ? left : right;
		}
	};
	Node *root;
	//Функция ищет подходящий лист для встави его вместо условного корня
	Node *firstAppropriateLeaf(Node *previous, Node *current, const int lowerBound, const int upperBound);
public:
	BinaryTree(Node *root = nullptr):root(root){}
	~BinaryTree();

	Node *getRoot();
	bool contains(const int key); // поиск элемента в дереве по ключу
	void insert(const int key); // добавление элемента в дерево по ключу
	void remove(const int key); // удаление элемента дерева по ключу
	//for BinaryTree level <= 5
	void printBinaryTreeIntoConsole(); // красивый вывод дерева в консоль 
	
	class BfsIterator : public Iterator {
	private:
		Queue *currentNodes;
	public:
		BfsIterator(Node *root) {
			currentNodes = new Queue();
			if (root) currentNodes->pushBack(static_cast<void*>(root));
		}
		void next();
		int current();
		bool hasNext();
	};

	class DfsIterator : public Iterator {
		Queue *currentNodes;
	public:
		DfsIterator(Node *root) {
			currentNodes = new Queue();
			if (root) {
				Node *current = root;
				currentNodes->pushBack(static_cast<void*>(root));
				while (current = current->left)
					currentNodes->pushBack(static_cast<void*>(current));
			}
		}
		void next();
		int current();
		bool hasNext();
	};

	DfsIterator *createDfsIterator(); // создание итератора, реализующего методы обхода в глубину (depth-first traverse)
	BfsIterator *createBfsIterator(); // создание итератора, реализующего методы обхода в ширину (breadth-first traverse)
	
};