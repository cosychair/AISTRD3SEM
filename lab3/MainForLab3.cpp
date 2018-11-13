//Binary tree
#include "BinaryTree.h"

int main() {
	//Вывод приветственного сообщения
	cout << "Glad to see you." << endl
		<< "This is lab3." << endl << endl
		<< "Author - Kirillov Daniil, gr. 7302, version 1.1" << endl << endl
		<< "Program gives you access to Binary Tree structure." << endl;
	//тут сделать проказ рботы всех ключевых функций
	BinaryTree *tree = new BinaryTree();
	int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
	for (int i : arrayForTree) tree->insert(i);
	tree->printBinaryTreeIntoConsole(tree->getRoot(), 10);
	for (BinaryTree::BfsIterator *tmp = tree->createBfsIterator(); tmp->hasNext(); tmp->next())
		cout << tmp->current()<<" ";
	cout << endl;


	delete tree;
}

