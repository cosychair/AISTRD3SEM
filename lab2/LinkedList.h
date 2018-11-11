#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class LinkedList {
private:
	class Node {
	public:
		int data;
		Node *next;
		Node *prev;

		Node(int data = 0, Node *next = nullptr, Node *prev = nullptr) :data(data), next(next), prev(prev) {};
		~Node() {
			next = nullptr;
			delete next;
			prev = nullptr;
			delete prev;
		};
	};
	Node *head;
	Node *tail;
	size_t size;
public:
	LinkedList(Node *head = nullptr, Node *tail = nullptr, size_t size = 0) : head(head), tail(tail), size(size) {};
	~LinkedList();
	void pushBack(const int data); // ���������� � ����� ������
	void pushFront(const int data); // ���������� � ������ ������
	void popBack(); // �������� ���������� ��������
	void popFront(); // �������� ������� ��������
	void insert(const int data, const size_t index); // ���������� �������� �� �������
	int at(const size_t index); // ��������� �������� �� �������
	void remove(const size_t index); // �������� �������� �� �������
	size_t getSize(); // ��������� ������� ������
	void printToConsole(); // ����� ��������� ������ � ������� ����� �����������
	void clear(); // �������� ���� ��������� ������
	void set(const size_t index, const int data); // ������ �������� �� ������� �� ������������ �������
	bool isEmpty(); // �������� �� ������� ������
	void swap(const size_t index1, const size_t index2); // ����� ���� ��������� ������ �� ��������
};