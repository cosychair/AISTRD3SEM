//Binary tree
#include "BinaryTree.h"

int main() {
	//Вывод приветственного сообщения
	cout << "Glad to see you." << endl
		<< "This is lab3." << endl << endl
		<< "Author - Kirillov Daniil, gr. 7302, version 1.1" << endl << endl
		<< "Program gives you access to view Binary Tree structure." << endl;
	
	BinaryTree *tree = new BinaryTree();
	int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
	for (int i : arrayForTree) tree->insert(i);
	
	tree->printBinaryTreeIntoConsole();
	tree->remove(6);
	tree->printBinaryTreeIntoConsole();

	//пример обхода в ширину
	for (Iterator *tmp = tree->createBfsIterator(); tmp->hasNext(); tmp->next())
		cout << tmp->current()<<" ";
	cout << endl;
	//пример обхода в глубину
	for (Iterator *tmp = tree->createDfsIterator(); tmp->hasNext(); tmp->next())
		cout << tmp->current() << " ";
	cout << endl;
	
	delete tree;
}

