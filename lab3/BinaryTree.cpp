#include "BinaryTree.h"
#include "../lab2/LinkedList.h"

BinaryTree::Node * BinaryTree::firstAppropriateLeaf(Node * previous, Node * current, const int lowerBound, const int upperBound){
	if (!current)
		return nullptr;

	if (current->key <= upperBound && current->key > lowerBound && !current->left && !current->right) {
		previous->getChild(current->key) = nullptr;
		return current;
	}

	Node *lf = firstAppropriateLeaf(current, current->left, lowerBound, upperBound);
	if (lf) return lf;
	Node *rf = firstAppropriateLeaf(current, current->right, lowerBound, upperBound);
	if (rf) return rf;

	return nullptr;
}

BinaryTree::~BinaryTree() {
	delete root;
}

BinaryTree BinaryTree::createRandomBinaryTree(int depth)
{
	return BinaryTree();
}

BinaryTree::Node * BinaryTree::getRoot(){
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

void BinaryTree::remove(const int key){
	Node *previous = nullptr,
		*current = root;
	//���� ������ �������
	while (current && current->key != key) {
		previous = current;
		current = current->getChild(key);
	}
	//���� �������� �� �������
	if (!current) {
		cout << "Element with key " << key << " not found!" << endl;
		return;
	}

	Node *tmp = current;//����� ������� �����

	if (!current->left && !current->right) {
		if (previous)
			previous->getChild(key) = nullptr;
		else
			root = nullptr;
	}else if (current->left && current->right) {
		Node *sab = firstAppropriateLeaf(nullptr, current, current->left->key, current->right->key);
		if (previous)
			previous->getChild(key) = sab;
		else
			root = sab;
		sab->left = current->left;
		sab->right = current->right;
	}
	else {
		Node *child = current->left ? current->left : current->right;
		if (previous)
			previous->getChild(key) = child;
		else
			root = child;
	}

	delete tmp;
}

void BinaryTree::printBinaryTreeIntoConsole(Node *current, size_t level){
	if (current) {
		printBinaryTreeIntoConsole(current->right, level + 1);
		cout << setw(level*3) << current->key<<endl;
		printBinaryTreeIntoConsole(current->left, level + 1);
	}
}

BinaryTree::BfsIterator *BinaryTree::createBfsIterator() {
	return new BfsIterator(root);
}

void BinaryTree::BfsIterator::next(){
	Node* current = currentNodes.front();
	currentNodes.pop_front();
	if (current->left) currentNodes.push_back(current->left);
	if (current->right) currentNodes.push_back(current->right);
}

int BinaryTree::BfsIterator::current(){
	return currentNodes.front()->key;
}

bool BinaryTree::BfsIterator::hasNext(){
	return	!currentNodes.empty();
}

BinaryTree::DfsIterator * BinaryTree::createDfsIterator() {
	return new DfsIterator(root);
}

void BinaryTree::DfsIterator::next(){
	Node *back = currentNodes.back();
	currentNodes.pop_back();

	if (back = back->right) {
		currentNodes.push_back(back);
		while (back = back->left)
			currentNodes.push_back(back);
	}
}

int BinaryTree::DfsIterator::current(){
	return currentNodes.back()->key;
}

bool BinaryTree::DfsIterator::hasNext(){
	return !currentNodes.empty();
}
