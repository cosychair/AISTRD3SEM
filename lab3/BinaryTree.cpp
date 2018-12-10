#include "BinaryTree.h"
#include "../lab2/LinkedList.h"

BinaryTree::~BinaryTree() {
	delete root;
}

BinaryTree::Node *BinaryTree:: getRoot(){
	return root;
}

bool BinaryTree::contains(const int key){
	Node *current = root;

	while (current && current->key != key)
		current = current->getChild(key);

	return current && current->key == key;
}

void BinaryTree::insert(const int key){	
	Node *previous = nullptr,
		 *current = root;

	while (current) {
		previous = current;
		current = current->getChild(key);
	}

	if (previous) {
		current = new Node(key);
		previous->getChild(key) = current;
	}
	else
		root = new Node(key);
}

BinaryTree::Node * BinaryTree::firstAppropriateLeaf(Node * previous, Node * current, const int lowerBound, const int upperBound) {
	if (current) {
		if (current->key <= upperBound && current->key >= lowerBound && !current->left && !current->right) {
			previous->getChild(current->key) = nullptr;
			return current;
		}

		Node *lf = firstAppropriateLeaf(current, current->left, lowerBound, upperBound);
		if (lf) return lf;
		Node *rf = firstAppropriateLeaf(current, current->right, lowerBound, upperBound);
		if (rf) return rf;
	}
	return nullptr;
}

void BinaryTree::remove(const int key){
	Node *previous = nullptr,
		*current = root;
	//Ищем нужный элемент
	while (current && current->key != key) {
		previous = current;
		current = current->getChild(key);
	}
	//если элемента не нашлось
	if (!current) {
		cout << "Element with key " << key << " not found!" << endl;
		return;
	}

	Node *tmp = current;//чтобы удалить потом

	if (!current->left && !current->right) {
		previous->getChild(key) = nullptr;
	}
	else if (current->left && current->right) {
		Node *sab = firstAppropriateLeaf(nullptr, current, current->left->key, current->right->key);
		sab->left = previous->getChild(key)->left;
		sab->right = previous->getChild(key)->right;
		previous->getChild(key) = sab;
	}
	else {
		Node *child = current->left ? current->left : current->right;
		previous->getChild(key) = child;
	}
}

void BinaryTree::printBinaryTreeIntoConsole(){
	if (!root) 
		cout << "Tree is empty." << endl;
	else {
		Queue *outNodes = new Queue();
		outNodes->pushBack(static_cast<void*>(root));
		size_t lvl = 0;
		int slash[132], shift;
		for (size_t i = 0; i < 132; i++)slash[i] = 0;
		while (lvl!=5) {
			for (size_t i = 0, j=0; i < pow(2, lvl); i++, j+=2) {
				shift = 32 / pow(2, lvl);
				if (static_cast<Node*>(outNodes->front())) {
					cout << setw(shift-1) <<"("<< (static_cast<Node*>(outNodes->front()))->key << ")" << setw(shift-1)<<" ";
					if (static_cast<Node*>(outNodes->front())->left) {
						outNodes->pushBack(static_cast<void*>(static_cast<Node*>(outNodes->front())->left));
						slash[j] = 1;
					}
					else {
						outNodes->pushBack(nullptr);
						slash[j] = 0;
					}
					if (static_cast<Node*>(outNodes->front())->right) {
						outNodes->pushBack(static_cast<void*>(static_cast<Node*>(outNodes->front())->right));
						slash[j+1] = 1;
					}
					else {
						outNodes->pushBack(nullptr);
						slash[j+1] = 0;
					}
				}
				else {
					cout << setw(shift) << " "<< setw(shift) << " ";
					slash[j] = 0;
					slash[j+1] = 0;
					outNodes->pushBack(nullptr);
					outNodes->pushBack(nullptr);
				}
				outNodes->popFront();
			}
			cout << endl;
			for (size_t i = 0; i < pow(2, lvl+1); i++) {
				shift = 32 / pow(2, lvl+1);
				if (slash[i])
					if(i%2 == 0)
						cout << setw(shift+2) << "/" << setw(shift-2)<<" ";
					else
						cout << setw(shift-2) << "\\" << setw(shift+2) << " ";
				else
					if (i % 2 == 0)
						cout << setw(shift) << " " << setw(shift) << " ";
					else
						cout << setw(shift) << " " << setw(shift) << " ";
				slash[i] = 0;
			}
			cout << endl;
			++lvl;
		}
	}
}

//BFSIteratorFunctions----------------------------------------
BinaryTree::BfsIterator * BinaryTree::createBfsIterator(){
	return new BfsIterator(root);
}

void BinaryTree::BfsIterator::next() {
	Node* current = static_cast<Node*>(currentNodes->front());
	currentNodes->popFront();
	if (current->left) currentNodes->pushBack(static_cast<void*>(current->left));
	if (current->right) currentNodes->pushBack(static_cast<void*>(current->right));
}

int BinaryTree::BfsIterator::current() {
	return (static_cast<Node*>(currentNodes->front()))->key;
}

bool BinaryTree::BfsIterator::hasNext() {
	return !currentNodes->isEmpty();
}

//DFSIteratorFunctions----------------------------------------
BinaryTree::DfsIterator * BinaryTree::createDfsIterator() {
	return new DfsIterator(root);
}

void BinaryTree::DfsIterator::next(){
	Node *current = static_cast<Node*>(currentNodes->back());
	currentNodes->popBack();

	if (current = current->right) {
		currentNodes->pushBack(static_cast<void*>(current));
		while (current = current->left)
			currentNodes->pushBack(static_cast<void*>(current));
	}
}


int BinaryTree::DfsIterator::current(){
	return static_cast<Node*>(currentNodes->back())->key;
}

bool BinaryTree::DfsIterator::hasNext(){
	return !currentNodes->isEmpty();
}
