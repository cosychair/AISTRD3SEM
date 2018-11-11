#pragma once
#include "Iterator.h"
class BinaryTree : public Iterator{
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
	};
	Node *root;
	int num, maxnum;//счетчик тегов(ключей), максимальный тег
	int maxrow, offset;//максимальная глубина и смещение корня
	char **screen;//массив,который содержит в себе красивый сисок для вывода в консоль
	Node* makeNode(int depth);//создание узла дерева с глубиной depth
	//-----Функции для КРАСИВОГО вывода дерева на экран----
	void clearScreen();//очистка рабочей памяти(заполнение массива точками)
	void outNodes(Node *current, int raw, int coloumn);//всавка кусочка дерева в screen
public:
	//ДУМАЙ САМ - МЕТОДИЧКА НЕ ТОВАРИЩ ТЕБЕ СЕЙЧАС :	(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
	BinaryTree(Node *root = nullptr):root(root){}
	~BinaryTree();

	BinaryTree createRandomBinaryTree(int depth);//создание дерева случайных размеров 

	bool contains(const int key); // поиск элемента в дереве по ключу
	void insert(const int key); // добавление элемента в дерево по ключу
	void remove(const int key); // удаление элемента дерева по ключу

	int next()override;
	bool hasNext()override;

	BinaryTree createDftIterator(); // создание итератора, реализующего методы обхода в глубину (depth-first traverse)
	BinaryTree createBftIterator(); // создание итератора, реализующего методы обхода в ширину (breadth-first traverse)
	
	void printBinaryTreeIntoConsole(); // красивый вывод дерева в консоль
};