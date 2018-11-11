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
	int num, maxnum;//������� �����(������), ������������ ���
	int maxrow, offset;//������������ ������� � �������� �����
	char **screen;//������,������� �������� � ���� �������� ����� ��� ������ � �������
	Node* makeNode(int depth);//�������� ���� ������ � �������� depth
	//-----������� ��� ��������� ������ ������ �� �����----
	void clearScreen();//������� ������� ������(���������� ������� �������)
	void outNodes(Node *current, int raw, int coloumn);//������ ������� ������ � screen
public:
	//����� ��� - ��������� �� ������� ���� ������ :	(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
	BinaryTree(Node *root = nullptr):root(root){}
	~BinaryTree();

	BinaryTree createRandomBinaryTree(int depth);//�������� ������ ��������� �������� 

	bool contains(const int key); // ����� �������� � ������ �� �����
	void insert(const int key); // ���������� �������� � ������ �� �����
	void remove(const int key); // �������� �������� ������ �� �����

	int next()override;
	bool hasNext()override;

	BinaryTree createDftIterator(); // �������� ���������, ������������ ������ ������ � ������� (depth-first traverse)
	BinaryTree createBftIterator(); // �������� ���������, ������������ ������ ������ � ������ (breadth-first traverse)
	
	void printBinaryTreeIntoConsole(); // �������� ����� ������ � �������
};